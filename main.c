#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 30000

void execute_brainfuck(char *buffer);

int main() {
    FILE *f;
    long fsmol;
    char *buffer;
    char filepath[256];
    char yn;
    char input[256];

    printf("I have a File (y/n)");
    scanf(" %c", &yn);

    if (yn == 'n') {
        printf("Enter your Code here:\n");
        scanf(" %s", input);
        buffer = calloc(1, strlen(input) + 1);
        strcpy(buffer, input);
        execute_brainfuck(buffer);
        free(buffer);
    } else if (yn == 'y') {
        printf("Filepath: ");
        scanf(" %s", filepath);

        f = fopen(filepath, "rb");
        if (f == NULL) {
            printf("Error opening file\n");
            return 1;
        }

        fseek(f, 0L, SEEK_END);
        fsmol = ftell(f);
        rewind(f);

        buffer = calloc(1, fsmol + 1);
        if (!buffer) {
            fclose(f);
            fputs("memory allocation fail", stderr);
            exit(1);
        }

        if (1 != fread(buffer, fsmol, 1, f)) {
            fclose(f);
            free(buffer);
            fputs("read fail", stderr);
            exit(1);
        }

        execute_brainfuck(buffer);
        fclose(f);
        free(buffer);
    }
}

void execute_brainfuck(char *buffer) {
    char data[DATA_SIZE] = {0};
    char *ptr = data;

    printf("Your Program-Output:\n\n");
    for (char *c = buffer; *c != '\0'; c++) {
        switch (*c) {
            case '>':
                ptr++;
                break;
            case '<':
                ptr--;
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (*ptr == 0) {
                    int bracket_nesting = 1;
                    while (bracket_nesting != 0) {
                        c++;
                        if (*c == '[') {
                            bracket_nesting++;
                        }
                        if (*c == ']') {
                            bracket_nesting--;
                        }
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    int bracket_nesting = 1;
                    while (bracket_nesting != 0) {
                        c--;
                        if (*c == '[') {
                            bracket_nesting--;
                        }
                        if (*c == ']') {
                            bracket_nesting++;
                        }
                    }
                    c--;
                }
                break;
        }
    }
}