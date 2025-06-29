#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return currentPlayer;
    }

    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return currentPlayer;

    return 0;
}

void swapPlayerTurn() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    cout << "TIC-TAC-TOE GAME\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;

    drawBoard();

    int playerWon;

    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        playerWon = winner();
        if (playerWon != 0) {
            cout << "Player " << playerWon << " wins! 🎉\n";
            break;
        }

        swapPlayerTurn();
    }

    if (playerWon == 0)
        cout << "It's a draw!\n";

    return 0;
}
