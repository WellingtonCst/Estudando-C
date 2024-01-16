#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int gameover;
const int width = 20;
const int height = 10;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Setup() {
    gameover = 0;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = 0;
    position.Y = 0;
    SetConsoleCursorPosition(hConsole, position);

    for (int i = 0; i < width + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                int printTail = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        printTail = 1;
                    }
                }
                if (!printTail)
                    printf(" ");
            }

            if (j == width - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++)
        printf("#");
    printf("\n");

    printf("Score:%d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}
// Função para exibir uma pergunta de exemplo
void ShowQuestion() {
    system("cls");
    printf("Pergunta: Qual é a capital do Brasil?\n");
    printf("a) Buenos Aires\nb) Brasília\nc) Rio de Janeiro\nd) São Paulo\n");
}

// Função para processar a resposta do jogador
int ProcessAnswer(char answer) {
    // Aqui você pode adicionar mais perguntas e lógica para verificar respostas
    if (answer == 'b' || answer == 'B') {
        printf("Resposta correta! Ganhou 20 pontos!\n");
        return 20;
    } else {
        printf("Resposta incorreta. Tente novamente na próxima fruta.\n");
        return 0;
    }
}

void Algorithm() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x < 0) x = width - 1;
    if (x >= width) x = 0;
    if (y < 0) y = height - 1;
    if (y >= height) y = 0;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
    Setup();
    // Oculta o cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    while (!gameover) {
        Draw();
        Input();
        Algorithm();
        Sleep(100);
    }

    // Exibe o cursor novamente antes de encerrar
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    return 0;
}
