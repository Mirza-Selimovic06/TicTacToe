/* 
Program: tictactoe.cpp 
Purpose: Terminal tictactoe game 
Author: Mirza Selimovic 
Date: 12-8-24 
*/ 
#include <ctime>
#include <iostream>
#include <vector>
using namespace std; 

//A function to draw the board 
void drawBoard(vector<vector<char>>& spaces) 
{ 
    cout << "********|********|********\n"; 
    cout << "*      *|*      *|*      *\n"; 
    cout << "*  " << spaces[0][0] << "   *|*  "<< spaces[0][1] << "   *|*   "<< spaces[0][2] <<"  *\n"; 
    cout << "*      *|*      *|*      *\n"; 
    cout << "**************************\n"; 
    cout << "********|********|********\n"; 
    cout << "*      *|*      *|*      *\n"; 
    cout << "*  "<< spaces[1][0] << "   *|*  " << spaces[1][1]<< "   *|*   " << spaces[1][2] << "  *\n"; 
    cout << "*      *|*      *|*      *\n"; 
    cout << "**************************\n"; 
    cout << "********|********|********\n"; 
    cout << "*      *|*      *|*      *\n"; 
    cout << "*  "<< spaces[2][0] << "   *|*  "<< spaces[2][1] << "   *|*  " << spaces[2][2] <<"   *\n"; 
    cout << "*      *|*      *|*      *\n"; 
    cout << "**************************\n"; 
} 

 

//Make a simple AI to make a move 

void computerMove(vector<vector<char>>& spaces, char computer) 
{ 

    srand(time(0)); 
    int row; 

    int column; 
    do     
    { 
        row = rand() % 3; 
        column = rand() % 3; 
    } while (spaces[row][column] != ' '); 

spaces[row][column] = computer; 
drawBoard(spaces); 
} 

 

//Bool function to check if player won or not 
bool checkWin(vector<vector<char>>& spaces, char player) 
{ 
//for loop to go through the spaces and see if player has three in a row, horizontaly and vertically. 
for(int i = 0; i < 3; i++) 
{ 
    if((spaces[i][0] == player && spaces[i][1] == player && spaces[i][2] == player) || (spaces[0][i] == player && spaces[1][i] == player && spaces[2][i] == player)) 
    { 
        return true; 
    } 
} 

//checks diagnol spaces 
if((spaces[0][0] == player && spaces[1][1] == player && spaces[2][2] == player) || (spaces[0][2] == player && spaces[1][1] == player && spaces[2][0] == player)) 
{   
    return true; 
} 
return false; 
} 

 

//Bool function to check ties 

bool checkTie(vector<vector<char>>& spaces) 
{ 
    for(int i = 0; i < 3; i++) 
    { 
        for(int j = 0; j < 3; j++) 
        { 
            if(spaces[i][j] == ' ') 
            { 
                return false; 

            } 
        } 

    } 
return true; 
} 

int main() 
{ 
    vector<vector<char>>spaces = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; 
    char startGame; 
    cout << "Welcome to TicTacToe enter Y to start the game!\n"; 
    cin >> startGame; 

    char player; 
    char computer; 
    cout << "Would you like to be x(goes firts) or o(goes second)." << endl; 
    cin >> player; 

    //player choosing if he wants to start or not 
    if(player == 'o') 
    { 
        computer = 'x'; 
        computerMove(spaces, computer); 
    } 
    else if(player == 'x') 
    { 
        computer = 'o'; 
    } 
    else 
    { 
        cout << "please enter the value of x or o. (must be lower case)." << endl; 
        cin >> player; 
    } 

 

 

    while(startGame == 'Y' || startGame == 'y') 
    { 
        int row; 
        int column; 

 

        //To get players move based on what row and what column they want the x or o to be 
        cout << "Enter row (1-3): \n";      
        cin >> row; 
        cout << "Enter column (1-3): \n"; 
        cin >> column; 
        //check for valid input 

        if (row < 1 || row > 3 || column < 1 || column > 3 || spaces[row - 1][column - 1] != ' ') 
        { 
            cout << "Invalid Move please try again :)\n"; 
            continue; 
        } 

        //puts x or o in place where player wants 
        spaces[row - 1][column - 1] = player; 
        cout << endl; 
        cout << endl;  


        //to check win and tie after player move 
        if(checkWin(spaces, player)) 
        { 
            drawBoard(spaces); 
            cout << "You Won!\n";   
            break; 
        } 
        else if(checkTie(spaces)) 
        { 
            drawBoard(spaces); 
            cout << "Tie!\n"; 
            break; 
        } 

        //check win and tie after computer move 
        computerMove(spaces, computer); 

        if(checkWin(spaces, computer)) 
        { 
            cout << "You lose\n"; 
            break; 
        } 
        else if(checkTie(spaces)) 
        { 
            drawBoard(spaces); 
            cout << "Tie!\n"; 
            break; 
        } 
    } 
} 