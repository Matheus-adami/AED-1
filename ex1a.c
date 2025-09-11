#include <stdio.h>
/* Exercicio 1A - AED-1
Autor: Matheus Gabriel Dieguez Adami
*/

int main() {
    int N;
    scanf("%d", &N);
    if (N < 1 || N > 1000) {
        return 1; // não faz nada se N estiver fora do intervalo
    }
    else {  // se n estiver dentro do intervalo
            // lê os N valores e armazena em um vetor
        int X[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &X[i]);
        }

        int menor = X[0];
        int posicao = 0;
        for (int i = 1; i < N; i++) {
            if (X[i] < menor) {
                menor = X[i];
                posicao = i;
            }
        }

        printf("Menor valor: %d\n", menor);
        printf("Posicao: %d\n", posicao);

        return 0;
    }
}