#include <stdio.h>

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char player = 'X';

void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

int checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

void makeMove() {
    int choice;
    printf("Player %c, enter your choice: ", player);
    scanf("%d", &choice);

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move! Try again.\n");
        makeMove();
    } else {
        board[row][col] = player;
    }
}

int main() {
    int gameOver = 0;

    printf("🎮 TIC TAC TOE GAME 🎮\n");
    displayBoard();

    while(!gameOver) {
        makeMove();
        displayBoard();

        if(checkWin()) {
            printf("🎉 Player %c wins!\n", player);
            gameOver = 1;
        } else if(checkDraw()) {
            printf("😐 It's a draw!\n");
            gameOver = 1;
        } else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
