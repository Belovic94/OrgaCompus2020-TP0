#ifndef FILEWRITER_H
#define FILEWRITER_H

typedef struct {
   char* filename;
}filewriter_t;

int filewriter_create(filewriter_t* self, char *filename);

void filewriter_destroy(filewriter_t* self);

void filewriter_write(filewriter_t *self, char *output);

#endif //FILEWRITER_H