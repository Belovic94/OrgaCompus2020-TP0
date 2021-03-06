#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filewriter.h"

int filewriter_create(filewriter_t *self, char *filename) {
    self->filename = calloc(strlen(filename), sizeof(char));
    strncpy(self->filename, filename, strlen(filename));
    return EXIT_SUCCESS;
}

void filewriter_write(filewriter_t *self, char *output) {
    if (strcmp(self->filename, "stdout") != 0) {
        FILE *fp;
        fp = fopen(self->filename, "w");
        fprintf(fp, "%s", output);
        fclose(fp);
    } else {
        fprintf(stdout, "%s", output);
    }
}


void filewriter_destroy(filewriter_t *self) {
    free(self->filename);
}