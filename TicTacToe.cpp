#include <iostream>
using namespace std;

char GameElements[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int Winner();
void Check();
void ResetGame();

int main()
{
    int Player, i, c;
    char score;
    char restart;

    do
    {
        ResetGame(); // Reset the game elements for a new game
        Player = 1;  // Reset player to 1

        do
        {
            Check();
            Player = (Player % 2) ? 1 : 2; // Player switching logic
            cout << "Player " << Player << ", enter a number: ";
            cin >> c;

            score = (Player == 1) ? 'X' : 'O';

            if (c >= 1 && c <= 9 && GameElements[c] == '0' + c) // Check if the move is valid
            {
                GameElements[c] = score;
            }
            else
            {
                cout << "Invalid move, try again." << endl;
                Player--; // Do not decrement player count
                cin.ignore();
                cin.get();
                continue; // Skip the rest of the loop
            }

            i = Winner();
            Player++; // Increment player for the next turn
        } while (i == -1); // Continue if the game is still ongoing

        Check();
        if (i == 1)
            cout << "==>\aPlayer " << --Player << " wins!" << endl; // \a is a bell character that rings the terminal bell
        else
            cout << "==>\aA Tie" << endl;

        cout << "Do you want to play a TieBreaker? (Y/N): ";
        cin >> restart;

    } while (restart == 'y' || restart == 'Y'); // Restart if user inputs 'y' or 'Y'

    return 0;
}

int Winner()
{
    if (GameElements[1] == GameElements[2] && GameElements[2] == GameElements[3])
        return 1;
    else if (GameElements[4] == GameElements[5] && GameElements[5] == GameElements[6])
        return 1;
    else if (GameElements[7] == GameElements[8] && GameElements[8] == GameElements[9])
        return 1;
    else if (GameElements[1] == GameElements[4] && GameElements[4] == GameElements[7])
        return 1;
    else if (GameElements[2] == GameElements[5] && GameElements[5] == GameElements[8])
        return 1;
    else if (GameElements[3] == GameElements[6] && GameElements[6] == GameElements[9])
        return 1;
    else if (GameElements[1] == GameElements[5] && GameElements[5] == GameElements[9])
        return 1;
    else if (GameElements[3] == GameElements[5] && GameElements[5] == GameElements[7])
        return 1;
    else if (GameElements[1] != '1' && GameElements[2] != '2' && GameElements[3] != '3' &&
             GameElements[4] != '4' && GameElements[5] != '5' && GameElements[6] != '6' &&
             GameElements[7] != '7' && GameElements[8] != '8' && GameElements[9] != '9')
        return 0; // Draw
    else
        return -1; // Game continues
}

void Check()
{
    system("cls");
    cout << "\n\nTIC TAC TOE\n\n";
    cout << "PLAYER 1 (X)  -  PLAYER 2 (O)" << endl
         << endl;

    // Display the grid
    cout << "     |     |     " << endl;
    cout << "  " << GameElements[1] << "  |  " << GameElements[2] << "  |  " << GameElements[3] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << GameElements[4] << "  |  " << GameElements[5] << "  |  " << GameElements[6] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << GameElements[7] << "  |  " << GameElements[8] << "  |  " << GameElements[9] << "  " << endl;
    cout << "     |     |     " << endl;
}

void ResetGame()
{
    for (int i = 1; i <= 9; i++)
    {
        GameElements[i] = '0' + i; // Reset the game elements
    }
}
