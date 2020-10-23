#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filereader.h"
#include <unistd.h>

char* _copy_file(FILE* file) {
    int numbytes;
    fseek(file, 0, SEEK_END);
    numbytes = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = calloc(numbytes, sizeof(char));
    int character;
    size_t n = 0;
    while ((character = fgetc(file)) != EOF) {
        buffer[n++] = (char) character;
    }
    buffer[n] = '\0';
    return buffer;
}

char* _copy_file_from_stdin() {
    size_t buffer_size = 100, n = 0;       
    char *buffer = calloc(buffer_size, sizeof(char));
    int character;
    while ((character = fgetc(stdin)) != '\n' && !feof(stdin)) {
        buffer[n] = character;
        if (++n == buffer_size) {
            buffer = realloc(buffer, (buffer_size *= 2) * sizeof(char));
        }      
    }
    buffer = realloc(buffer, (n + 1) * sizeof(char));
    buffer[n] = '\0';

    return buffer;
}

int filereader_create(filereader_t *self, char * filename) {
    if (strcmp(filename, "stdin") == 0) {
        self->buffer = _copy_file_from_stdin();
    } else {
        FILE *fp;
        fp = fopen(filename, "r");
        if (fp == NULL) {
            fprintf(stderr, "File not found: %s  \n", filename);
            return EXIT_FAILURE;
        }
        self->buffer = _copy_file(fp);
        fclose(fp);
    }
    self->index = 0;
    return EXIT_SUCCESS;
}

void filereader_destroy(filereader_t *self) {
    free(self->buffer);
}

int filereader_eof(filereader_t *self) {
    return self->index >= strlen(self->buffer);
}

size_t filereader_length(filereader_t *self) {
    return strlen(self->buffer);
}

int filereader_read(filereader_t *self, char *output, int amount) {
    int ret = 0;
    if (filereader_eof(self)) {
        goto exit;
    }
    for (size_t i = 0; i < amount; i++) {
        if (!filereader_eof(self)) {
            output[i] = self->buffer[self->index++];
            if (output[i] != '=') {
                ret++;
            }
        } else {
            output[i] = "";
        }  
    }
    exit:
    return ret;
}
