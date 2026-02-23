#include <stdio.h>
#include <stdlib.h>

// Adicionamos o parâmetro 'valorHabilidade' no final
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int origemLinha, int origemColuna, int valorHabilidade) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int tabL = origemLinha + (i - 2); 
                int tabC = origemColuna + (j - 2);

                if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                    // Agora ele marca o tabuleiro com o valor específico daquela habilidade
                    tabuleiro[tabL][tabC] = valorHabilidade;
                }
            }
        }
    }
}

int main() {
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0};

    // 1. Definição das Matrizes de Habilidade (5x5)
    int habilidadeCone[5][5] = {0};
    int habilidadeCruz[5][5] = {0};
    int habilidadeOctaedro[5][5] = {0};

    // Preenchendo Cone
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 2) habilidadeCone[i][j] = 1;
            if (i == 1 && j >= 1 && j <= 3) habilidadeCone[i][j] = 1;
            if (i == 2) habilidadeCone[i][j] = 1;
        }
    }

    // Preenchendo Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) habilidadeCruz[i][j] = 1;
        }
    }

    // Preenchendo Octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) habilidadeOctaedro[i][j] = 1;
        }
    }

    // 2. Posicionamento de Navios
    tabuleiro[2][2] = 3; tabuleiro[2][3] = 3; tabuleiro[2][4] = 3; // Horizontal
    tabuleiro[5][7] = 3; tabuleiro[6][7] = 3; tabuleiro[7][7] = 3; // Vertical

    // 3. Aplicação das Habilidades no Tabuleiro
    // Passando o número que representa cada desenho no final:
    
    // Aplicando CONE (Valor 5)
    aplicarHabilidade(tabuleiro, habilidadeCone, 1, 7, 5);
    
    // Aplicando CRUZ (Valor 6)
    aplicarHabilidade(tabuleiro, habilidadeCruz, 7, 2, 6);
    
    // Aplicando OCTAEDRO (Valor 7)
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 7, 7, 7);

    // 4. Exibição Final
    printf("--- Batalha Naval: Nivel Mestre ---\n");
    // Legenda atualizada para refletir as novas marcações
    printf("Legenda: 0=Agua | 3=Navio | 5=Cone | 6=Cruz | 7=Octaedro\n\n");

    printf("    ");
    for (int j = 0; j < 10; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%c | ", letras[i]);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}