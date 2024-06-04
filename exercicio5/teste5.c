#include <stdio.h>
#include <stdlib.h>

#define SHIFT 3 // Deslocamento da cifra de substituição

void decryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' - SHIFT + 26) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' - SHIFT + 26) % 26;
        }
        fputc(ch, outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;

    inputFile = fopen("Criptografado.txt", "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo criptografado.\n");
        return 1;
    }

    outputFile = fopen("Descriptografado1.txt", "w");
    if (outputFile == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    decryptFile(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Arquivo descriptografado com sucesso.\n");

    return 0;
}
