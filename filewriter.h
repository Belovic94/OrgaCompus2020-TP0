#ifndef FILEWITER_H
#define FILEWITER_H

typedef struct {
   char* buffer;
   int index;
}filewriter_t;

int filewriter_create(filewriter_t* self, char *filename);

void filewriter_destroy(filewriter_t* self);

int filewriter_read(filewriter_t *self, char *output, int amount);


int filewriter_eof(filewriter_t *self);

size_t filewriter_length(filewriter_t *self);

#endif //FILEWITER_H