#include <stdio.h>
#include "filereader.h"

char *encode_base64(filereader_t* file) {
    //Leer hasta 3 bytes o lo que se pueda. Si no se completan, llenar con ceros.
    //Se encodea en base 64:
    //Pasar los 3 bytes a binario. Tomar 4 bloques de a 6 bits. Rellenar a la izquierda cada bloque
    //con dos ceros para que completen 8 bits(un byte). Cada bloque es un índice que se convierte en un caracter
    //de la tabla de codificación.
    //Se guarda en variable auxiliar
    //Cuando el archivo finaliza, retorno variable auxiliar.

    char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    size_t output_size = filereader_length(file);
    if (output_size % 3 != 0)
        output_size += 3 - (filereader_length(file) % 3);
    output_size /= 3;
    output_size *= 4;
    char *encoded_data = calloc(output_size, sizeof(char));
    size_t bytes_in_binary;
    char *bytes;
    size_t index = 0;
    int bytes_read = 0;

    while (!filereader_eof(file)) {
        bytes_read = filereader_read(file, bytes);
        bytes_to_binary(bytes, &bytes_in_binary);
        for (size_t i = 0; i < 4; i++) {
            encoded_data[index++] = bytes_read >= i ? base64_chars[(bytes_in_binary >> 6 * (3 - i)) & 0x3F] : "=";    
        }
    }
    return encoded_data;
}

void bytes_to_binary(char *bytes, size_t *output) {
    size_t aux = bytes[0];
    for (int i = 1; i < 3; i++) {
        aux = strcmp(bytes[i], "") == 0 ? aux << 8 | bytes[i] : aux << 8;
    }
    *output = aux;
}