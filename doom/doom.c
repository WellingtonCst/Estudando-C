#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define LINHAS 10
#define COLUNAS 10

int jogadorX, jogadorY;
int objetivoX, objetivoY;

char labirinto[LINHAS][COLUNAS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

void imprimirLabirinto() {
    system("cls"); // Limpar a tela (apenas para Windows, use "clear" no Linux/Mac)

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c ", labirinto[i][j]);
        }
        printf("\n");
    }
}

void mover(char direcao) {
    switch (direcao) {
        case 'w':
            if (jogadorX - 1 >= 0 && labirinto[jogadorX - 1][jogadorY] != '#') {
                labirinto[jogadorX][jogadorY] = ' ';
                jogadorX--;
            }
            break;
        case 's':
            if (jogadorX + 1 < LINHAS && labirinto[jogadorX + 1][jogadorY] != '#') {
                labirinto[jogadorX][jogadorY] = ' ';
                jogadorX++;
            }
            break;
        case 'a':
            if (jogadorY - 1 >= 0 && labirinto[jogadorX][jogadorY - 1] != '#') {
                labirinto[jogadorX][jogadorY] = ' ';
                jogadorY--;
            }
            break;
        case 'd':
            if (jogadorY + 1 < COLUNAS && labirinto[jogadorX][jogadorY + 1] != '#') {
                labirinto[jogadorX][jogadorY] = ' ';
                jogadorY++;
            }
            break;
    }

    if (jogadorX == objetivoX && jogadorY == objetivoY) {
        printf("Parabéns! Você alcançou o objetivo!\n");
        exit(0);
    }

    labirinto[jogadorX][jogadorY] = 'P'; // Posição do jogador
    imprimirLabirinto();
}

int main() {
    jogadorX = 1;
    jogadorY = 1;

    objetivoX = 7;
    objetivoY = 8;

    imprimirLabirinto();

    char movimento;
    while (1) {
        printf("W - cima, S - baixo, A - esquerda, D - direita\n");
        movimento = getch();

        mover(movimento);
    }

    return 0;
}
