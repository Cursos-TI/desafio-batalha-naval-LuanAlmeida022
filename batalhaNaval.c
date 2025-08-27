#include <stdio.h>
#include <stdlib.h> // Para abs()

#define tam 10
#define navio 3
#define hab 5 // tamanho das matrizes de habilidade (5x5)

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[tam][tam], int habilidade[hab][hab], int origemLinha, int origemColuna) {
    int centro = hab / 2;

    for (int i = 0; i < hab; i++) {
        for (int j = 0; j < hab; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                if (linhaTab >= 0 && linhaTab < tam && colunaTab >= 0 && colunaTab < tam) {
                    // Marca a habilidade como 5 no tabuleiro
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

int main(){
    // Letras das colunas (A até J)
    char colunas[tam]= {'A','B','C','D','E','F','G','H','I','J'};

    // Números das linhas (1 até 10)
    int linhas[tam] = {1,2,3,4,5,6,7,8,9,10};

    // Tabuleiro inicializado com 0
    int tabuleiro[tam][tam] = {0};

    // Navios
    int linhaDP = 1, colunaDP = 1; 
    for(int i = 0; i < navio; i++ ){ tabuleiro[linhaDP + i][colunaDP + i] = 3; }

    int linhaDS = 0, colunaDS = 9; 
    for(int i = 0; i < navio; i++ ){ tabuleiro[linhaDS + i][colunaDS - i] = 3; }

    int linhaH = 5, colunaH = 4; 
    for(int i = 0; i < navio; i++ ){ tabuleiro[linhaH][colunaH + i] = 3; }

    int linhaV = 5, colunaV = 1; 
    for(int i = 0; i < navio; i++ ){ tabuleiro[linhaV + i][colunaV] = 3; }

    // Matrizes das habilidades
    int cone[hab][hab] = {0}, cruz[hab][hab] = {0}, octaedro[hab][hab] = {0};

    // Cone (ponta em cima, abrindo para baixo)
    for (int i = 0; i < hab; i++){
        for (int j = 0; j < hab; j++){
            if (j >= hab/2 - i && j <= hab/2 + i && i <= hab/2) cone[i][j] = 1;
        }
    }

    // Cruz (padrão exato do exemplo)
    cruz[0][2] = 1;
    cruz[1][0] = 1; cruz[1][1] = 1; cruz[1][2] = 1; cruz[1][3] = 1; cruz[1][4] = 1;
    cruz[2][2] = 1;

    // Octaedro (losango conforme exemplo)
    octaedro[0][2] = 1;
    octaedro[1][1] = 1; octaedro[1][2] = 1; octaedro[1][3] = 1;
    octaedro[2][2] = 1;

    // Aplicar habilidades com valor 5
    aplicarHabilidade(tabuleiro, cone, 2, 2);   
    aplicarHabilidade(tabuleiro, cruz, 7, 3);  
    aplicarHabilidade(tabuleiro, octaedro, 4, 6); 

    // Exibir cabeçalho
    printf (" *** Tabuleiro Batalha Naval *** \n");
    printf("   ");
    for (int j = 0; j < tam; j++) printf("%c ", colunas[j]);
    printf("\n");

    // Exibir tabuleiro
   
    for (int i = 0; i < tam; i++){
        printf("%2d ", linhas[i]);
        for (int j = 0; j < tam; j++) printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}