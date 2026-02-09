#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    // Inicialização
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Definindo os navios como vetores unidimensionais (tamanho 3)
    int navio[3] = {3,3,3};

   //Navio horizontal

   int linhaC = 2, colunaC = 2;
   for (int j = 0; j < 3; j++) {
       tabuleiro[linhaC][colunaC + j] = navio[j];
        }

    //Navio vertical

     int linhaV = 5, colunaV = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navio[i];
        }

    //Navio diagonal  

    int linhaD = 1, colunaD = 8;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD + i][colunaD - i] = navio[i];
        }
    
    //navio diagonal 2

    int linhaD2 = 7, colunaD2 = 9;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
        }


    printf("--- Tabuleiro Batalha Naval ---\n\n");

    // 1. Imprime o cabeçalho de números (Colunas)
    printf("    "); // Espaço para alinhar com as letras da lateral
    for (int j = 0; j < 10; j++) {
        printf("%d ", j + 1); 
    }
    printf("\n");

    // 2. Imprime as linhas com as letras na frente
    for (int i = 0; i < 10; i++) {
        printf("%c | ", letras[i]); // Imprime a letra da linha e uma barra divisória

        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }



    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
