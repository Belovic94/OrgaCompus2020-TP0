#include <stdio.h>
#include "filereader.h"

int b64invs[] = { 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };

int is_valid_char(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '=' || c == '/' || c == '+') {
        return 1;
    }
    return 0;
}

void bytes_to_binary(char *bytes, size_t *output) {
    size_t aux = bytes[0];
    for (int i = 1; i < 4; i++) {
        aux = (bytes[i] == "=") ? aux << 6 : aux << 6 | bytes[i];
    }
    *output = aux;
}

char* decode_base64(filereader_t* file) {
    size_t file_length = filereader_length(file);
    size_t output_size = file_length / 4 * 3;
    char *decoded_data = calloc(output_size + 1, sizeof(char));

    char output;
    char bytes[4];
    int bytes_read = 0;
    size_t index = 0;
    size_t bytes_in_binary;


    while (!filereader_eof(file)) {
        if(filereader_read_char(file, &output) != 0 && !is_valid_char(output)) {
            return 0;
        }
        bytes_read = filereader_read(file, bytes, 4);

        bytes_to_binary(bytes, &bytes_in_binary);
        for (size_t i = 0; i < 4; i++) {
            decoded_data[index++] = bytes_read >= i ? base64_chars[(bytes_in_binary >> 6 * (3 - i)) & 0x3F] : '=';    
        }
    }
    fprintf(stdout, "%s \n", decoded_data);

}