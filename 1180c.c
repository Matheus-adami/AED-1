#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);//tamanho desejado

    int *X = (int*)malloc(N * sizeof(int));//alocando a memoria dinamicamente
    if (X == NULL) {
        return 1; //em caso de erro

    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);//lendo os valores para cada posição

    }

    int menor = X[0];//assumindo o primeiro como o menor
    int posicao = 0;//assumindo a posição 0 (primeira no vetor) como a do menor
    for (int i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];//descobrindo o menor valor
            posicao = i;//dizendo a posição do menor

        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free(X);//liberando a memoria
    return 0;
}