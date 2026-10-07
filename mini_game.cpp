#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard()
{
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n\n";
}

bool checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void resetBoard()
{
    char number = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = number++;
        }
    }
}

void playGame()
{
    char player = 'X';
    int choice;

    while (true)
    {
        displayBoard();

        cout << "Player " << player << ", enter a number (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9)
        {
            cout << "\nInvalid choice! Try again.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int column = (choice - 1) % 3;

        if (board[row][column] == 'X' ||
            board[row][column] == 'O')
        {
            cout << "\nThat position is already taken! Try again.\n";
            continue;
        }

        board[row][column] = player;

        if (checkWin(player))
        {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (checkDraw())
        {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

int main()
{
    char replay;

    cout << "====================================\n";
    cout << "         TIC TAC TOE GAME\n";
    cout << "====================================\n";

    do
    {
        resetBoard();
        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}