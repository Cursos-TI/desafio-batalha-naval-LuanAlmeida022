#include <stdio.h>

int main(){
  

    // Letras das colunas (A até J, horizontal)
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Números das linhas (1 até 10, vertical)
    int linhas[10] = {1,2,3,4,5,6,7,8,9,10};

    // Tabuleiro inicializado com 0
    int tabuleiro[10][10] = {0};

    // Posicionar navio horizontal (linha 3, coluna 5)
    
    int linhaH = 2, colunaH = 4; 
    for(int i = 0; i < 3; i++ ){

        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Posicionar navio vertical (linha 3, coluna 5)
    
    int linhaV = 5, colunaV = 7; 
    for(int i = 0; i < 3; i++ ){

        tabuleiro[linhaV + i][colunaV] = 3;
    }


    // Exibir cabeçalho de colunas (A–J)
    printf("   ");
    for (int j = 0; j < 10; j++){
        printf("%c ", colunas[j]);
    }
    printf("\n");

    // Exibir tabuleiro completo
    for (int i = 0; i < 10; i++) {
        printf("%2d ", linhas[i]); // imprime número da linha (1–10)
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // imprime cada posição
        }
        printf("\n");
    }

    return 0;
}