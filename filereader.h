#ifndef FILEREADER_H
#define FILEREADER_H

typedef struct {
   FILE* file;
   int index;
}filereader_t;

int filereader_create(filereader_t* self, char *filename);

void filereader_destroy(filereader_t* self);

int filereader_read(filereader_t *self, char *output, int amount);

#endif //FILEREADER_H
