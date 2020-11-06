#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filewriter.h"
#include <unistd.h>

int filewriter_create(filewriter_t *self, char *filename) {
    if (strcmp(filename, "stdout") == 0) {
        self->file = stdout;
    } else {
        FILE *fp;
        fp = fopen(filename, "w");
        if (fp == NULL) {
            fprintf(stderr, "File not found: %s  \n", filename);
            return EXIT_FAILURE;
        }
        self->file = fp;
    }
    return EXIT_SUCCESS;
}

void filewriter_write(filewriter_t *self, char* output) {
    write(fileno(self->file), output, 1);
    /* if (strcmp(self->filename, "stdout") != 0) {
        FILE *fp;
        fp = fopen(self->filename, "w");
        fwrite(output, strlen(output), sizeof(char), fp);
        fclose(fp);
    } else {
        
    } */
}


void filewriter_destroy(filewriter_t *self) {
    if (fileno(self->file) != 1) {
        fclose(self->file);
    }
}