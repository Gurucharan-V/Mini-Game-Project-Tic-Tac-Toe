#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char currentMarker;

    void displayBoard() const {
        cout << "\n";
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
        cout << "---|---|---\n";
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
        cout << "---|---|---\n";
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
        cout << "\n";
    }

    bool placeMarker(int slot) {
        if (slot < 1 || slot > 9) return false;
        int index = slot - 1;
        if (board[index] != 'X' && board[index] != 'O') {
            board[index] = currentMarker;
            return true;
        }
        return false;
    }

    int checkWinner() const {
        // Winning combinations
        const int winCombos[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
            {0, 4, 8}, {2, 4, 6}             // Diagonals
        };

        for (int i = 0; i < 8; ++i) {
            if (board[winCombos[i][0]] == board[winCombos[i][1]] && 
                board[winCombos[i][1]] == board[winCombos[i][2]]) {
                return (board[winCombos[i][0]] == 'X') ? 1 : 2;
            }
        }

        for (int i = 0; i < 9; ++i) {
            if (board[i] != 'X' && board[i] != 'O') return 0; // Game ongoing
        }

        return -1; // Draw
    }

    void swapTurn() {
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    }

public:
    void resetGame() {
        board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        currentMarker = 'X';
    }

    void play() {
        resetGame();
        int winner = 0;

        cout << "========================================\n";
        cout << "          TIC TAC TOE MINI GAME         \n";
        cout << "========================================\n";

        while (winner == 0) {
            displayBoard();
            int slot;
            cout << "Player " << (currentMarker == 'X' ? "1 (X)" : "2 (O)") << ", enter slot (1-9): ";
            cin >> slot;

            if (!placeMarker(slot)) {
                cout << "Invalid move! Slot is either taken or out of range. Try again.\n";
                continue;
            }

            winner = checkWinner();
            if (winner == 0) {
                swapTurn();
            }
        }

        displayBoard();

        if (winner == 1) {
            cout << "🎉 Congratulations! Player 1 (X) wins!\n";
        } else if (winner == 2) {
            cout << "🎉 Congratulations! Player 2 (O) wins!\n";
        } else {
            cout << "🤝 It's a draw! Well played both.\n";
        }
    }
};

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.play();
        cout << "\nWould you like to play another game? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing Tic Tac Toe!\n";
    return 0;
}