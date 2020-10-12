//
// Created by victorbelosevich.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filereader.h"

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

int filereader_create(filereader_t *self, char * filename) {
    int ret = EXIT_SUCCESS;
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        ret = EXIT_FAILURE;
        fprintf(stderr, "Archivo no encontrado");
        goto exit;
    }
    self->buffer = _copy_file(fp);
    self->index = 0;
    exit:
    fclose(fp);
    return ret;
}

void filereader_destroy(filereader_t *self) {
    free(self->buffer);
}

int filereader_eof(filereader_t *self) {
    return strlen(self->buffer) >= self->index;
}

int filereader_read(filereader_t *self, char *output) {
    int ret = 0;
    if (filereader_eof(self)) {
        goto exit;
    }
    for (size_t i = 0; i < 3; i++) {
        if (!filereader_eof(self)) {
            output[i] = self->buffer[self->index++];
            ret++;
        } else {
            output[i] = "";
        }  
    }
    exit:
    return ret;
}
