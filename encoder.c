#include <stdio.h>

char *encode_base64(filereader_t file)
{
    //Leer hasta 3 bytes o lo que se pueda. Si no se completan, llenar con ceros.
    //Se encodea en base 64:
    //Pasar los 3 bytes a binario. Tomar 4 bloques de a 6 bits. Rellenar a la izquierda cada bloque
    //con dos ceros para que completen 8 bits(un byte). Cada bloque es un índice que se convierte en un caracter
    //de la tabla de codificación.
    //Se guarda en variable auxiliar
    //Cuando el archivo finaliza, retorno variable auxiliar.

    char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    char *encoded_data = 4 * ((input_length + 2) = 3);
    char *bytes_in_binary;
    int bytes_counter = 0;
    char *bytes;

    if (file == NULL || len == 0)
        return NULL;

    while (!filereader_eof(file))
    {
        filereader_read(file, bytes);
        bytes_counter++;
        if (bytes_counter == 3)
        {
            bytes_in_binary = bytes_to_binary(bytes);
            encoded_data[0] = base64_chars[(bytes_in_binary >> 6 * 3) & 0x3F];
            encoded_data[] = base64_chars[(>>) & 0x3F];
            encoded_data[] = base64_chars[(>>) & 0x3F];
            encoded_data[] = base64_chars[(>>) & 0x3F];
        }
    }
    bytes_to_binary(bytes);
    return encoded_data;
}

char *bytes_to_binary(char *bytes)
{
    char output[8];
    char bytes_in_binary[24];

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(bytes[i], ""))
        {
            bytes[i] = "=";
        }
        itoa(bytes[i], output, 2);
        if (i == 0)
        {
            strncpy(bytes_in_binary, output, 8);
        }
        else
        {
            strncat(bytes_in_binary, output, 8);
        }
    }
    return bytes_in_binary;
}