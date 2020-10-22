#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "filereader.h"
#include "filewriter.h"
#include "encoder.h"
#include "decoder.h"

#define VERSION "0.1.0"

void show_help() {
    printf("Usage:\n");
    printf("\ttp0 -h\n");
    printf("\ttp0 -V\n");
    printf("\ttp0 [options]\n");
    printf("Options\n");
    printf("\t-V --version\tPrint version and quit.\n");
    printf("\t-h --help\tPrint this information.\n");
    printf("\t-o --output\tPath to output file.\n");
    printf("\t-i --output\tPath to input file.\n");
    printf("\t-d --decode\tDecode a base64-encoded file.\n");
    printf("Examples\n");
    printf("\n");
    printf("\ttp0 -i input.txt -o output.txt\n");
}

void show_version() {
    printf("tp0 version: %s\n", VERSION);
}

void show_error(char *msg) {
    fprintf(stderr, "%s", msg);
}

int main(int argc, char *argv[]) {
    int option = 0;
    int version = 0;
    int help = 0;
    int must_return = 0;
    int decode = 0;
    char *input = NULL;
    char *output = NULL;
    int ret = EXIT_SUCCESS;

    static struct option long_options[] = {
        {"version", no_argument, 0, 'V'},
        {"help", no_argument, 0, 'h'},
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"decode", no_argument, 0, 'd'}, 
    };

    int long_index = 0;
    while ((option = getopt_long(argc, argv, "Vhi:o:d", long_options, &long_index)) != -1) {
        if (must_return) {
            show_error("Invalid parameters.");
            return 1;
        }

        switch (option) {
            case 'V':
                show_version();
                must_return = 1;
                break;
            case 'h':
                show_help();
                must_return = 1;
                break;
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            case 'd':
                decode = 1;
                break;
            case '?':
                must_return = 1;
                break;
            default:
                must_return = 1;
                break;
        }
    }

    if (must_return) {
        return 0;
    }

    if (input == NULL) {
        input = "stdin";
    }

    if (output == NULL) {
        output = "stdout";
    }

    filereader_t inputFile;
    filewriter_t outputFile;
    if (filereader_create(&inputFile, input) == EXIT_FAILURE) {
        ret = EXIT_FAILURE;
        goto exit;
    }
    fprintf(stdout, "Salio del fileReader \n");
    filewriter_create(&outputFile, output);
    fprintf(stdout, "Salio del filewriter \n");
    if (decode) {
        ret = decode_base64(&inputFile, &outputFile);
    } else {
        ret = encode_base64(&inputFile, &outputFile);
    }
    exit:
    filereader_destroy(&inputFile);
    filewriter_destroy(&outputFile);
    return ret;
    
}