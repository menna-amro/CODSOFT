#include <iostream>
using namespace std;

const int SIZE = 3;            // dimensions of the board
char board[SIZE][SIZE];
char currentPlayer;            // X or O
bool gameOver;                 // to check if game has ended
char winner;                   // variable to store the winner


// initialize the game board
void initializeBoard() 
{
    for (int i = 0; i < SIZE; ++i)               // row
    {
        for (int j = 0; j < SIZE; ++j)           // column
            board[i][j] = ' ';
    }
    currentPlayer = 'X';         
    gameOver = false;
    winner = ' ';
}

void displayBoard() 
{
    cout << "   0   1   2" << endl;                                     // print column indices
    for (int i = 0; i < SIZE; ++i) 
    {  
        cout << " " << i << " ";                                        // print row indices
        for (int j = 0; j < SIZE; ++j) 
        {
            cout << board[i][j];                                        // print the cell value  ( 'X' or 'O' or ' ' )
            if (j < SIZE - 1) cout << " | ";                            // if the current column is not the last one so print a vertical separator ( | ) between columns
        }
        cout << endl;                                                   // new line after finishing the current row
        if (i < SIZE - 1) cout << "  ---|---|---" << endl;              // if the current row is not the last one so print a horizontal separator ( ---|---|--- ) between rows
    }
    cout << endl;
}


// check if current player has won 
bool checkWin() 
{
    // check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;
    }
    // check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) || (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return true;

    return false;
}


bool checkDraw() {
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == ' ')
                return false;                   // return false if there are empty cells, meaning the game is not a draw
        }
    }
    return true;                               // return true if all cells are filled and no player has won
}

// switch the current player after each move
void switchPlayer() 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// makes a move for the current player at the specified row and column
void makeMove(int row, int col) 
{
    if (board[row][col] == ' ')                          // check if the specified cell is empty
    {
        board[row][col] = currentPlayer;
        if (checkWin()) 
        {
            winner = currentPlayer;
            gameOver = true;
        }

        else if (checkDraw())
            gameOver = true;

        else 
            switchPlayer();
        
    }
    else 
        cout << "Invalid move! That spot is already taken." << endl;
    
}


void displayResult() 
{
    if (winner != ' ')                                           // check if there is a winner
        cout << "Player " << winner << " wins!" << endl << endl;
    
    else if (gameOver)                                           // if gameOver is true but winner is still a space, it means the game ended in a draw
        cout << "It's a draw!" << endl << endl;
    
    else 
        cout << "The game is ongoing." << endl << endl;
  
}


void playGame() 
{
    initializeBoard();
    cout << "****** TIC-TAC-TOE ******" << endl << endl << endl;

    while (!gameOver)                                                      // continue the game loop until the game is over
    {
        displayBoard();                                                    // display the current state of the board
        cout << "Player " << currentPlayer << "'s turn." << endl << endl;
        int row, col;
        cout << "Enter row (0-2): ";
        cin >> row;
        cout << "Enter column (0-2): ";
        cin >> col;
        cout << endl << endl;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) 
        {
            makeMove(row, col);
            displayResult();                                                // display the result after each move         
        }
        else 
            cout << "Invalid input. Row and column must be between 0 and 2." << endl;
        
    }

    displayBoard();                                                        // display the final state of the board
    //displayResult();
}

int main() 
{
    char playAgain;
    do 
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl << endl;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!" << endl << endl;
    return 0;
}
