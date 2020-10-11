#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileReader.h"

#define VERSION "0.1.0"

void show_help()
{
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

void show_version()
{
    printf("tp0 version: %s\n", VERSION);
}

void show_error(char *msg)
{
    fprintf(stderr, msg);
}

int main(int argc, char *argv[])
{
    int option = 0;
    int version = 0;
    int help = 0;
    int must_return = 0;
    char *input = NULL;
    char *output = NULL;
    FILE *input_handler = NULL;
    FILE *output_handler = NULL;

    int long_index = 0;
    while ((option = getopt_long(argc, argv, "Vhi:o:d", long_option, &long_index)) != -1)
    {
        if (must_return)
        {
            show_error("Invalid parameters.");
            return 1;
        }

        switch (option)
        {
        case 'v':
            show_verion();
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
        case '?':
            must_return = 1;
            break;
        default:
            break;
        }
    }

    if (must_return)
    {
        return 0;
    }

    FILE *fp;
    fp = fopen(argv[2], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    filereader_t file;
    filereader_create(&file, fp);
}