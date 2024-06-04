#include <stdio.h>

int main() {
    FILE *entrada, *saida;
    char caractere, proximo;

    entrada = fopen("codigofonte.csv", "r"); // Abre o arquivo de entrada
    saida = fopen("codigosem.txt", "w"); // Abre o arquivo de saída

    if (entrada == NULL || saida == NULL) { // Verifica se houve erro na abertura dos arquivos
        printf("Erro ao abrir os arquivos.");
        return 1;
    }

    while ((caractere = fgetc(entrada)) != EOF) { // Lê caractere por caractere até o fim do arquivo
        if (caractere == '/') { // Verifica se é o início de um comentário
            proximo = fgetc(entrada);
            if (proximo == '/') { // Comentário de linha
                while ((caractere = fgetc(entrada)) != '\n' && caractere != EOF); // Ignora até o final da linha
            } else if (proximo == '*') { // Comentário de bloco
                do { // Ignora até encontrar o fim do comentário de bloco
                    while ((caractere = fgetc(entrada)) != '*');
                } while ((caractere = fgetc(entrada)) != '/');
            } else {
                fputc(caractere, saida); // Se não for comentário, escreve no arquivo de saída
                fputc(proximo, saida);
            }
        } else {
            fputc(caractere, saida); // Se não for comentário, escreve no arquivo de saída
        }
    }

    fclose(entrada); // Fecha o arquivo de entrada
    fclose(saida); // Fecha o arquivo de saída

    printf("Comentários removidos com sucesso.\n");

    return 0;
}

