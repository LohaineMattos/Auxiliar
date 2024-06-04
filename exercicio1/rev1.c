#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
    FILE *arquivo1, *arquivo2, *arquivosaida;
    char linha[100];

    // Abre os dois arquivos de entrada
    arquivo1 = fopen("arquivo1.csv", "r");
    arquivo2 = fopen("arquivo2.csv", "r");

    // Verifica se os arquivos foram abertos corretamente
    if (arquivo1 == NULL || arquivo2 == NULL) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    // Abre o arquivo de sa�da para escrita
    arquivosaida = fopen("arquivosaida.csv", "w");
    if (arquivosaida == NULL) {
        perror("Erro ao criar arquivo de sa�da");
        exit(EXIT_FAILURE);
    }

    // L� e mescla os arquivos linha por linha
    while (fgets(linha, sizeof(linha), arquivo1) != NULL || fgets(linha, sizeof(linha), arquivo2) != NULL) {
        if (linha[0] != '\0') {
            fputs(linha, arquivosaida);
        }
        
        // L� a pr�xima linha de cada arquivo
        if (fgets(linha, sizeof(linha), arquivo2) != NULL) {
            fputs(linha, arquivosaida);
        }
    }

    // Fecha todos os arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivosaida);

    printf("Arquivos mesclados com sucesso!\n");

    return 0;
}
