#ifndef ENCODER_H
#define ENCODER_H

char *encode_base64(filereader_t *file);

void bytes_to_binary(char *bytes, size_t *output);

#endif //ENCODER_H