#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main() {
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10] = {0};
    
    // Posiciona navios (valor 3)
    tabuleiro[1][2] = 3;
    tabuleiro[1][6] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[7][3] = 3;
    tabuleiro[7][7] = 3;
    
    // Cria matrizes de habilidade
    int cone[TAM][TAM] = {0}, cruz[TAM][TAM] = {0}, octaedro[TAM][TAM] = {0};
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            if(j >= TAM/2 - i/2 && j <= TAM/2 + i/2) cone[i][j] = 1;
            if(i == TAM/2 || j == TAM/2) cruz[i][j] = 1;
            if(abs(i - TAM/2) + abs(j - TAM/2) <= TAM/2) octaedro[i][j] = 1;
        }
    }
    
    // Aplica habilidades (valor 5)
    int pos[3][2] = {{1,1}, {4,4}, {7,1}};
    for(int h = 0; h < 3; h++) {
        for(int i = 0; i < TAM; i++) {
            for(int j = 0; j < TAM; j++) {
                int lin = pos[h][0] - TAM/2 + i;
                int col = pos[h][1] - TAM/2 + j;
                if(lin >= 0 && lin < 10 && col >= 0 && col < 10 && tabuleiro[lin][col] != 3) {
                    if((h == 0 && cone[i][j]) || (h == 1 && cruz[i][j]) || (h == 2 && octaedro[i][j])) {
                        tabuleiro[lin][col] = 5;
                    }
                }
            }
        }
    }
    
    // Exibe tabuleiro simplificado
    printf("\n   ");
    for(int j = 0; j < 10; j++) {
        printf(" %c", colunas[j]);
    }
    printf("\n");
    
    for(int i = 0; i < 10; i++) {
        printf("%2d", i+1);
        for(int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLEGENDA: 0 = Água | 3 = Navio | 5 = Área afetada\n");
    return 0;
}