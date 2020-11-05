#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#include "filewriter.h"

void encode_bytes_to_binary(char *bytes, size_t *output) {
    size_t aux = bytes[0];
    for (int i = 1; i < 3; i++) {
        aux = (bytes[i] == '\0') ? aux << 8 : aux << 8 | bytes[i];
    }
    *output = aux;
}

int encode_base64(filereader_t* inputFile, filewriter_t* outputFile) {
    char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t total_allocated = 4;
    size_t bytes_in_binary;
    char bytes[3];
    size_t index = 0;
    char *encoded_data = calloc(total_allocated, sizeof(char));
    int bytes_read = 0;

    while ((bytes_read = filereader_read(inputFile, bytes, 3)) > 0) {
        if (total_allocated <= index) {
            total_allocated += 4;
            encoded_data = realloc(encoded_data, total_allocated * sizeof(char));
        }
        encode_bytes_to_binary(bytes, &bytes_in_binary);
        for (size_t i = 0; i < 4; i++) {
            encoded_data[index++] = bytes_read >= i ? base64_chars[(bytes_in_binary >> 6 * (3 - i)) & 0x3F] : '=';    
        }
    }
    filewriter_write(outputFile, encoded_data);
    free(encoded_data);
    return EXIT_SUCCESS;
}