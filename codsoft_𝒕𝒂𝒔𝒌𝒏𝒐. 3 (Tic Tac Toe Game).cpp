#include <iostream>
#include <limits>
#include <conio.h>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:

    void printTitle()
    {
        system("cls");

        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "            ******************************************              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            *            TIC-TAC-TOE GAME            *              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            ******************************************              " << endl;
        cout << endl;
        cout << endl;
        cout << "  Welcome to Tic-Tac-Toe Game! Press any key to continue...";
        getch();
        system("cls");
    }
    
    TicTacToe() {
        initializeBoard();
        currentPlayer = 'X';
    }
    

    void initializeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard() const {
        cout << "  1   2   3\n";
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < 2)
                    cout << "|";
            }
            cout << "\n";
            if (i < 2)
                cout << "  ---|---|---\n";
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool isMoveValid(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
    }

    bool checkWin() const {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool isBoardFull() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void play() {
        int row, col;

        do {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            while (true) {
                try {
                    cin >> row >> col;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input. Please enter numbers.");
                    }
                    --row;
                    --col;
                    if (isMoveValid(row, col))
                        break;
                    else
                        throw out_of_range("Cell already occupied. Choose another cell.");
                } catch (const exception &e) {
                    cout << "Error: " << e.what() << "\n";
                    cout << "Please enter valid row and column: ";
                }
            }

            makeMove(row, col);

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "The game is a draw!\n";
                break;
            }

            switchPlayer();

        } while (true);
    }
};

int main() {
    do {
        TicTacToe game;
        game.printTitle();
        
        game.play();
        
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing!\n";
            break;
        }

    } while (true);

    return 0;
}
