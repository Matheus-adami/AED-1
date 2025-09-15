#include <stdio.h>
#include <string.h>

#define TAM 9

int verifica_linha(int grade[TAM][TAM], int linha) {
    int visto[TAM+1] = {0};
    for (int coluna = 0; coluna < TAM; coluna++) {
        int valor = grade[linha][coluna];
        if (valor < 1 || valor > 9 || visto[valor]) return 0;
        visto[valor] = 1;
    }
    return 1;
}

int verifica_coluna(int grade[TAM][TAM], int coluna) {
    int visto[TAM+1] = {0};
    for (int linha = 0; linha < TAM; linha++) {
        int valor = grade[linha][coluna];
        if (valor < 1 || valor > 9 || visto[valor]) return 0;
        visto[valor] = 1;
    }
    return 1;
}

int verifica_caixa(int grade[TAM][TAM], int inicio_linha, int inicio_coluna) {
    int visto[TAM+1] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valor = grade[inicio_linha + i][inicio_coluna + j];
            if (valor < 1 || valor > 9 || visto[valor]) return 0;
            visto[valor] = 1;
        }
    }
    return 1;
}

int sudoku_valido(int grade[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        if (!verifica_linha(grade, i) || !verifica_coluna(grade, i))
            return 0;
    }
    for (int i = 0; i < TAM; i += 3) {
        for (int j = 0; j < TAM; j += 3) {
            if (!verifica_caixa(grade, i, j))
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, grade[TAM][TAM];
    scanf("%d", &n);
    for (int instancia = 1; instancia <= n; instancia++) {
        for (int i = 0; i < TAM; i++)
            for (int j = 0; j < TAM; j++)
                scanf("%d", &grade[i][j]);
        printf("Instancia %d\n", instancia);
        if (sudoku_valido(grade))
            printf("SIM\n");
        else
            printf("NAO\n");
        //if (instancia < n)
        //    printf("\n");
    }
    return 0;
}