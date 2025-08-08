#include <stdio.h>

// Função recursiva para movimentação do Bispo (diagonal)
void moverBispo(int linha, int coluna, int limite) {
    if (linha > limite || coluna > limite) return; // Condição de parada
    printf("Bispo na posição: (%d, %d)\n", linha, coluna);
    moverBispo(linha + 1, coluna + 1, limite); // Move para diagonal inferior direita
}

// Função recursiva para movimentação da Torre (horizontal direita)
void moverTorre(int coluna, int limite) {
    if (coluna > limite) return;
    printf("Torre na coluna: %d\n", coluna);
    moverTorre(coluna + 1, limite);
}

// Função recursiva para movimentação da Rainha (horizontal esquerda)
void moverRainha(int coluna, int limite) {
    if (coluna < 1) return;
    printf("Rainha na coluna: %d\n", coluna);
    moverRainha(coluna - 1, limite);
}

// Função para movimentação do Cavalo usando loops aninhados
void moverCavalo(int linha, int coluna, int limite) {
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int novaLinha = linha + movimentos[i][0];
        int novaColuna = coluna + movimentos[i][1];

        // Verifica se está dentro do tabuleiro
        if (novaLinha < 1 || novaLinha > limite || novaColuna < 1 || novaColuna > limite) {
            continue; // Pula movimentos inválidos
        }

        printf("Cavalo pode ir para: (%d, %d)\n", novaLinha, novaColuna);
    }
}

int main() {
    int limite = 8; // Tabuleiro 8x8

    printf("=== Movimentação do Bispo ===\n");
    moverBispo(1, 1, limite);

    printf("\n=== Movimentação da Torre ===\n");
    moverTorre(1, limite);

    printf("\n=== Movimentação da Rainha ===\n");
    moverRainha(8, limite);

    printf("\n=== Movimentação do Cavalo ===\n");
    moverCavalo(4, 4, limite);

    return 0;
}
