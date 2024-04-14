#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch1, ch2;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    int count = 0; 
    while ((ch1 = fgetc(inputFile)) != EOF) {
        if (ch1 != ' ') {
            count++;
            ch2 = fgetc(inputFile);
            if (ch2 != EOF && ch2 != ' ') {
                fputc(ch2, outputFile);
                fputc(ch1, outputFile);
            } else {
                fputc(ch1, outputFile);
            }
        } else {
            fputc(ch1, outputFile);
        }
    }

    
    if (count % 2 != 0) {
        fseek(outputFile, -1, SEEK_CUR); 
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}