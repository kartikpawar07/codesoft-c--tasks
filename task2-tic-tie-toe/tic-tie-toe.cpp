#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

bool isMoveValid(int move) {
    if (move < 1 || move > 9) return false;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    return board[row][col] != 'X' && board[row][col] != 'O';
}

void makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;

    do {
        resetBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        cout << "Tic-Tac-Toe Game (Player X vs Player O)\n";
        displayBoard();

        while (!gameOver) {
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (!isMoveValid(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(move);
            displayBoard();

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}