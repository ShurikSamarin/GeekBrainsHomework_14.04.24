#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка открытия файлов\n");
        return 1;
    }

    char address[100];
    fgets(address, 100, input_file);

    char *last_slash = strrchr(address, '/');
    
    char *last_dot = strrchr(last_slash, '.');
    
    if (last_dot != NULL) {
        
        strcpy(last_dot, ".html");
    } else {
        
        strcat(address, ".html");
    }

    fprintf(output_file, "%s", address);

    fclose(input_file);
    fclose(output_file);

    return 0;
}