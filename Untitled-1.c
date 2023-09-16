#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", 
        "manga", "abacate", "kiwi", "cereja", "morango", "pêssego", 
        "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", 
        "papaya"};

    // Tamanho do vetor
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    int numTrocas = 0;
    int numComparacoes = 0;

    // Ordenar o vetor usando qsort e contar trocas e comparações
    qsort(arr, tamanho, sizeof(arr[0]), comparar);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d) %s\n", i + 1, arr[i]);
    }


    char *mediana;
    if (tamanho % 2 == 0) {
        mediana = arr[tamanho / 2 - 1];
    } else {
        mediana = arr[tamanho / 2];
    }
    printf("\nMediana: %s\n", mediana); /* Media */

    FILE *arquivo = fopen("saida.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída.");
        return 1;
    } /* abrir arquivo para ser gravado */

    for (int i = 1; i < tamanho; i++) {
        for (int j = 0; j < tamanho - i; j++) {
            numComparacoes++;
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                numTrocas++;
            }
        }
    }

    fprintf(arquivo, "Número de trocas: %d\n", numTrocas);
    fprintf(arquivo, "Número de comparações: %d\n", numComparacoes);
    fprintf(arquivo, "Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "(%d) %s\n", i + 1, arr[i]);
    }
    fprintf(arquivo, "\nMediana: %s\n", mediana);

    fclose(arquivo);

    return 0;
}
