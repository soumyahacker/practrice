#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

bool check_winner(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool is_board_full() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool is_valid_move(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return false;
    if (board[row][col] != ' ')
        return false;
    return true;
}

void play_game() {
    char player = 'X';
    int row, col;
    bool game_over = false;

    initialize_board();

    while (!game_over) {
        display_board();
        printf("Player %c's turn. Enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if (is_valid_move(row, col)) {
            board[row][col] = player;
            if (check_winner(player)) {
                display_board();
                printf("Player %c wins!\n", player);
                game_over = true;
            } else if (is_board_full()) {
                display_board();
                printf("It's a draw!\n");
                game_over = true;
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    play_game();
    return 0;
}
