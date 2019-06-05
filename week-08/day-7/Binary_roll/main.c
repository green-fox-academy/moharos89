#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char *file_reader(char file_name[]);

char binary_to_char(char lettters[]);

int *string_to_int(char letter[]);

int main()
{
    printf("%s\n", file_reader("../input.txt"));

    return 0;
}

char binary_to_char(char lettters[])
{
    int letter = 0;
    for (int i = 0; i < 8; ++i) {
        if (lettters[i] == '0') {
            letter |= (0 << (7 - i));
        } else {
            letter |= (1 << (7 - i));
        }
    }
    return (char) letter;
}

char *file_reader(char file_name[])
{
    FILE *file;
    file = fopen(file_name, "r");
    char *result = (char *) calloc(1, sizeof(char));
    if (file != NULL) {
        int status = 0;
        char binary[8];
        while (fscanf(file, "%s", &binary) != EOF) {
            char letter = binary_to_char(binary);
            char temp[2];
            temp[0] = letter;
            temp[1] = '\0';
            printf("%c", letter);
            result = (char *) realloc(result, (strlen(result) + 2) * sizeof(char));
            if (status == 0) {
                strcpy(result, temp);
                status = 1;
            } else {
                strcat(result, temp);
            }
        }
    }

    fclose(file);
    return result;
}
