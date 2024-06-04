#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 1000
#define MAX_TAMANHO_PALAVRA 50

typedef struct {
    char palavra[MAX_TAMANHO_PALAVRA];
    int frequencia;
} Palavra;

Palavra palavras[MAX_PALAVRAS];
int num_palavras = 0;

void adiciona_palavra(char *palavra) {
    int i;
    for (i = 0; i < num_palavras; i++) {
        if (strcmp(palavras[i].palavra, palavra) == 0) {
            palavras[i].frequencia++;
            return;
        }
    }
    strcpy(palavras[num_palavras].palavra, palavra);
    palavras[num_palavras].frequencia = 1;
    num_palavras++;
}

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    char linha[100], palavra[50];
    int i;

    arquivo_entrada = fopen("arquivocomdados.txt", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    arquivo_saida = fopen("arquivocomsaida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(arquivo_entrada);
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo_entrada)!= NULL) {
        char *token = strtok(linha, " \n");
        while (token!= NULL) {
            adiciona_palavra(token);
            token = strtok(NULL, " \n");
        }
    }

    for (i = 0; i < num_palavras; i++) {
        fprintf(arquivo_saida, "%s: %d\n", palavras[i].palavra, palavras[i].frequencia);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Frequência de palavras contada com sucesso.\n");

    return 0;
}
