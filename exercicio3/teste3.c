#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
    char caractere;

    entrada = fopen("teste22.txt", "r"); // Abre o arquivo de entrada
    saida = fopen("teste22saida.txt", "w"); // Abre o arquivo de saída

    if (entrada == NULL || saida == NULL) { // Verifica se houve erro na abertura dos arquivos
        printf("Erro ao abrir os arquivos.");
        return 1;
    }

    while ((caractere = fgetc(entrada)) != EOF) { // Lê caractere por caractere até o fim do arquivo
        if (caractere == ' ' || caractere == '\n') { // Verifica se é espaço, quebra de linha ou tabulação
            continue; // Ignora e vai para o próximo caractere
        } else {
            fputc(caractere, saida); // Se não for espaço ou quebra de linha, escreve no arquivo de saída
        }
    }

    fclose(entrada); // Fecha o arquivo de entrada
    fclose(saida); // Fecha o arquivo de saída

    printf("Espaços e quebras de linha removidos com sucesso.\n");

    return 0;
}
