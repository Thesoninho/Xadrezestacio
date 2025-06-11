#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Inicializa o tabuleiro
void initBoard() {
    // Peças pretas
    strcpy(board[0], "rnbqkbnr");
    for (int i = 0; i < BOARD_SIZE; i++) board[1][i] = 'p';

    // Espaços vazios
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '.';

    // Peças brancas
    for (int i = 0; i < BOARD_SIZE; i++) board[6][i] = 'P';
    strcpy(board[7], "RNBQKBNR");
}

// Imprime o tabuleiro
void printBoard() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Converte notação (e.g., 'e2') para índices
int posToIdx(char col, char row, int *x, int *y) {
    if (col < 'a' || col > 'h' || row < '1' || row > '8') return 0;
    *y = col - 'a';
    *x = 8 - (row - '0');
    return 1;
}

// Move uma peça
int movePiece(char fromCol, char fromRow, char toCol, char toRow) {
    int fx, fy, tx, ty;
    if (!posToIdx(fromCol, fromRow, &fx, &fy) || !posToIdx(toCol, toRow, &tx, &ty)) {
        printf("Coordenadas inválidas!\n");
        return 0;
    }

    char piece = board[fx][fy];
    if (piece == '.') {
        printf("Não há peça na origem!\n");
        return 0;
    }

    board[tx][ty] = piece;
    board[fx][fy] = '.';
    return 1;
}

int main() {
    char from[3], to[3];
    initBoard();
    
    printf("=== Jogo de Xadrez em C ===\n");
    printBoard();

    while (1) {
        printf("\nDigite o movimento (ex: e2 e4): ");
        scanf("%2s %2s", from, to);
        
        if (strcmp(from, "00") == 0) break;

        if (movePiece(from[0], from[1], to[0], to[1])) {
            printBoard();
        } else {
            printf("Movimento inválido.\n");
        }
    }

    printf("Jogo encerrado.\n");
    return 0;
}
