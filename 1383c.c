#include <stdio.h>

#define TAM 9

int verifica_linha(int **grade, int linha) {
    int visto[TAM+1] = {0};
    for (int coluna = 0; coluna < TAM; coluna++) {
        int valor = grade[linha][coluna];
        if (valor < 1 || valor > 9 || visto[valor]) return 0;
        visto[valor] = 1;
    }
    return 1;
}

int verifica_coluna(int **grade, int coluna) {
    int visto[TAM+1] = {0};
    for (int linha = 0; linha < TAM; linha++) {
        int valor = grade[linha][coluna];
        if (valor < 1 || valor > 9 || visto[valor]) return 0;
        visto[valor] = 1;
    }
    return 1;
}

int verifica_caixa(int **grade, int inicio_linha, int inicio_coluna) {
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

int sudoku_valido(int **grade) {
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
    int n;
    scanf("%d", &n);

    // Aloca matriz dinamicamente
    int **grade = (int **)malloc(TAM * sizeof(int *));
    for (int i = 0; i < TAM; i++)
        grade[i] = (int *)malloc(TAM * sizeof(int));

    for (int instancia = 1; instancia <= n; instancia++) {
        for (int i = 0; i < TAM; i++)
            for (int j = 0; j < TAM; j++)
                scanf("%d", &grade[i][j]);
        printf("Instancia %d\n", instancia);
        if (sudoku_valido(grade))
            printf("SIM\n");
        else
            printf("NAO\n");
        if (instancia < n)
            printf("\n");
    }

    // Libera memoria
    for (int i = 0; i < TAM; i++)
        free(grade[i]);
    free(grade);

    return 0;
}