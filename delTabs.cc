#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];
    char *cleanedLine;

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) {
        cleanedLine = (char *)malloc(strlen(line) + 1);
        int j = 0;
        int spaceCount = 0;

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != ' ' || (i > 0 && line[i - 1] != ' ')) {
                cleanedLine[j++] = line[i];
                if (line[i] == ' ') {
                    spaceCount++;
                } else {
                    spaceCount = 0;
                }
                if (spaceCount > 1) {
                    j--;
                }
            }
        }
        cleanedLine[j] = '\0';
        fprintf(outputFile, "%s", cleanedLine);
        free(cleanedLine);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
