#ifndef FILEREADER_H
#define FILEREADER_H

typedef struct {
   char* buffer;
   int index;
}filereader_t;

int filereader_create(filereader_t* self, char *filename);

void filereader_destroy(filereader_t* self);

int filereader_read(filereader_t *self, char *output, int amount);

int filereader_read_char(filereader_t *self, char *output);

int filereader_eof(filereader_t *self);

size_t filereader_length(filereader_t *self);

#endif //FILEREADER_H
