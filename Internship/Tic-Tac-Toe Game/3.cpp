#include <iostream>
#include <vector>

using namespace std;

void showGameBoard(const vector<vector<char>>& board){
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool checkVictory(const vector<vector<char>>& board, char player){
    for (int i = 0; i < 3; ++i) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkDraw(const vector<vector<char>>& board){
    for(const auto& row : board) {
        for(char cell : row) {
            if(cell == ' ') return false;
        }
    }
    return true;
}

void displayScore(int playerXScore, int playerOScore){
    cout<<"Score: Player X - " << playerXScore << ", Player O - " << playerOScore << endl;
}

int main(){
    int playerXScore = 0;
    int playerOScore = 0;

    while (true) {
        vector<vector<char>> gameBoard(3, vector<char>(3, ' '));
        char currentPlayer = 'X';

        while (true){
            showGameBoard(gameBoard);

            int row, col;
            cout << "Player " << currentPlayer << ", make your move (row and column): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || gameBoard[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            gameBoard[row - 1][col - 1]=currentPlayer;

            if (checkVictory(gameBoard, currentPlayer)) {
                showGameBoard(gameBoard);
                cout << "Player " << currentPlayer << " wins this round!"<<endl;
                (currentPlayer == 'X') ? ++playerXScore : ++playerOScore;
                displayScore(playerXScore, playerOScore);
                break;
            } else if (checkDraw(gameBoard)) {
                showGameBoard(gameBoard);
                cout << "It's a draw! No points awarded."<<endl;
                displayScore(playerXScore, playerOScore);
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        char playAgain;
        cout << "\n Do you want to play again? (Yes/No): ";
        cin >> playAgain;

        if(playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing! \n Final Score: Player X - " << playerXScore << ", Player O - " << playerOScore<<endl;
            break;
        }
    }
    return 0;
}
