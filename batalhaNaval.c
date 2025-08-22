#include <stdio.h>

#define tam 10
#define navio 3

int main(){
  

    // Letras das colunas (A até J, horizontal)
    char colunas[tam]= {'A','B','C','D','E','F','G','H','I','J'};

    // Números das linhas (1 até 10, vertical)
    int linhas[tam] = {1,2,3,4,5,6,7,8,9,10};

    // Tabuleiro inicializado com 0
    int tabuleiro[tam][tam] = {0};

    
    // Navio diagonal principal (↘)
    int linhaDP = 1, colunaDP = 1; 
    for(int i = 0; i < navio; i++ ){
        tabuleiro[linhaDP + i][colunaDP + i] = 3;
    }

    // Navio diagonal secundária (↙)
    int linhaDS = 0, colunaDS = 9; 
    for(int i = 0; i < navio; i++ ){
        tabuleiro[linhaDS + i][colunaDS - i] = 3;
    }
    
    // Navio horizontal
    int linhaH = 5, colunaH = 4; 
    for(int i = 0; i < navio; i++ ){

        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio vertical 
    int linhaV = 5, colunaV = 1; 
    for(int i = 0; i < navio; i++ ){

        tabuleiro[linhaV + i][colunaV] = 3;
    }


    // Exibir cabeçalho de colunas (A–J)
    printf(" *** Tabuleiro Batalha Naval *** \n");
    printf("   ");
    for (int j = 0; j < 10; j++){
        printf("%c ", colunas[j]);
    }
    printf("\n");

    // Exibir tabuleiro completo

    for (int i = 0; i < tam; i++) {
        printf("%2d ", linhas[i]); // imprime número da linha (1–10)
        for (int j = 0; j < tam; j++) {
            printf("%d ", tabuleiro[i][j]); // imprime cada posição
        }
        printf("\n");
    }

    return 0;
}