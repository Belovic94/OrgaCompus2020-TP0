#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filereader.h"
#include <unistd.h>

int filereader_create(filereader_t *self, char * filename) {
    if (strcmp(filename, "stdin") == 0) {
        self->file = stdin;
    } else {
        FILE *fp;
        fp = fopen(filename, "r");
        if (fp == NULL) {
            fprintf(stderr, "File not found: %s  \n", filename);
            return EXIT_FAILURE;
        }
        self->file = fp;
    }
    self->index = 0;
    return EXIT_SUCCESS;
}

void filereader_destroy(filereader_t *self) {
    if (self->file != 0) {
        fclose(self->file);
    }
}

int filereader_read(filereader_t *self, char *output, int amount) {
    return read(fileno(self->file), output, amount);
}
