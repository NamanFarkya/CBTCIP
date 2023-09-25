#include <stdio.h>
int main() {
    char filename[100];
    FILE *file;
    char ch;
    int lines = 0, words = 0, characters = 0, inword = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("your file are not opened\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\v' || ch == '\f') {
            inword = 0;
        } else if (inword == 0) {
            inword = 1;
            words++;
        }
    }
    fclose(file);
    printf("\nFile analysis for '%s':\n", filename);
    printf("Total lines: %d\n", lines);
    printf("Total words: %d\n", words);
    printf("Total characters: %d\n", characters);
    return 0;
}
