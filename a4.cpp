//
//  main.cpp
//  a4_q1
//
//  Created by Tiffany Teng on 2020-11-05.
//  Copyright © 2020 Tiffany Teng. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>


using namespace std;

// declare gloabl variables for a 4x4 array
const int COLUMN_SIZE = 4;
const int ROW_SIZE = 4;


// declare functions
void player_O(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& o_games_won, bool& won_game);
void check_column(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& win, char e, bool& won_game);
void check_row(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& win, char e, bool& won_game);
void check_row(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& win, char e, bool& won_game);
void player_X(int (&game_array)[ROW_SIZE][COLUMN_SIZE],  int& x_games_won, bool& won_game);
void output_stats(int o_games_won, int x_games_won);
void check_diagonal(int (&game_array)[ROW_SIZE][COLUMN_SIZE],  int win, char e, bool& won_game);
void output_game_board(int (&game_array)[ROW_SIZE][COLUMN_SIZE]);


// output winner stats at the end
void output_stats(int o_games_won, int x_games_won)
{
    
    cout << "Game Scores: \n   Wins for Player O: " << o_games_won << endl
        << "   Wins for Player X: " << x_games_won << endl;

}
  
// player X turn, places X in the chosen spot
void player_X(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& x_games_won, bool& won_game)
{
    // declare variables
    int location = 0;
    bool valid_choice = false;
    
    // for winner later
    char h = 'X';
    
    // user chooses loacation on the game board and loop ensures the location has not been taken and it is a valid location
    do {
        cout << "Player X, please enter your desired location " << endl;
        cin >> location;
    } while (location < 1 || location > 16);
        //requirements: 1 < location < 16

        while (!valid_choice) {
                // player x = -2
                // only replaces the spot if it does not have X(-2) or O(-2)
                if (game_array[(location - 1) / 4][(location - 1) % 4] != -2 && game_array[(location - 1) / 4][(location - 1) % 4] != -1) { // x = -2 o = -1
                    
                    game_array[(location - 1) / 4][(location - 1) % 4] = -2 ;
                    valid_choice = true;
                }
                else {
                    cout << "Please enter a valid location. " << endl<< endl;
                    
                    do {
                        cout << "Player X, please enter your desired location " << endl;
                        cin >> location;
                    } while (location < 1 || location > 16);
                }
            }

        // checks if players x has won
        check_column(game_array, x_games_won, h, won_game);
        check_row(game_array, x_games_won, h, won_game);
        check_diagonal(game_array, x_games_won,h, won_game);
}//end of player_x()


//player o turn
void player_O(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& o_games_won, bool& won_game) {
   
    // declare variables
    int location = 0;
    bool valid_choice = false;
   
    //to ouput winner later
    char p = 'O';
   
    // user chooses loacation on the game board and loop ensures the location has not been taken and it is a valid location
    do {
       cout << "Player O, please enter your desired location between 1 and 16 " << endl;
       cin >> location;
   } while (location < 1 || location > 16);


    while (!valid_choice) {
        // O = -1
            if (game_array[(location - 1) / 4][(location - 1) % 4] != -1 && game_array[(location - 1) / 4][(location - 1) % 4] != -2) {
               
                game_array[(location - 1) / 4][(location - 1) % 4] = (-1);
                valid_choice = true;
            }
            // continues until a valid choice is chosen
            else {
                cout << "Please enter a valid location that wasn't previously chosen. " << endl << endl;
                
                     // user chooses loacation on the game board and loop ensures the location has not been taken and it is a valid location
                do {
                    cout << "Player O, please enter your desired location between 1 and 16 " << endl;
                    cin >> location;
                } while (location < 1 || location > 16);

            }
    }
    
    check_column( game_array, o_games_won, p, won_game);
    check_row(game_array,  o_games_won,p, won_game);
    check_diagonal(game_array, o_games_won,p,won_game);
}

// checks if either player has won
void check_column(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& win, char e, bool& won_game) {
    
    // checks each column if they have the same value
    if (game_array[0][0] == game_array[1][0] && game_array[1][0] == game_array[2][0] && game_array[2][0] == game_array[3][0]) {
       //outputs the correct winner
        cout << e << " is the winner! Congratulations!"<< endl;
       // increments the win score for the player
        win += 1;
        // set bool to true
        won_game = true;
    }
    else if (game_array[0][1] == game_array[1][1] && game_array[1][1] == game_array[2][1] && game_array[2][1] == game_array[3][1]) {
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
    else if (game_array[0][2] == game_array[1][2] && game_array[1][2] == game_array[2][2] && game_array[2][2] == game_array[3][2]) {
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
    else if (game_array[0][3] == game_array[1][3] && game_array[1][3] == game_array[2][3] && game_array[2][3] == game_array[3][3]) {
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
    else
        won_game = false;
}

// checks if the player has won
void check_row(int (&game_array)[ROW_SIZE][COLUMN_SIZE], int& win, char e, bool& won_game) {
    // checks if any rows have the same value, if so they have won
    if (game_array[0][0] == game_array[0][1] && game_array[0][1] == game_array[0][2] && game_array[0][2] == game_array[0][3]) {
        
        // outputs correct winner
        cout << e << " is the winner! Congratulations!" << endl;
        //increments win count
        win += 1;
       // sets bool to true
        won_game = true;
    }
    else if (game_array[1][0] == game_array[1][1] && game_array[1][1] == game_array[1][2] && game_array[1][2] == game_array[1][3]) {
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
    else if (game_array[2][0] == game_array[2][1] && game_array[2][1] == game_array[2][2] && game_array[2][2] == game_array[2][3]) {
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
    else if (game_array[3][0] == game_array[3][1] && game_array[3][1] == game_array[3][2] && game_array[3][2] == game_array[3][3]) {
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
}

// check if player has won
void check_diagonal(int (&game_array)[ROW_SIZE][COLUMN_SIZE],  int win, char e, bool& won_game) {
    
    // checks if either of the diagonals have the same value
    if (game_array[0][0] == game_array[1][1] && game_array[1][1] == game_array[2][2] && game_array[2][2] == game_array[3][3]) {
        // outputs winner, increments number of games won , and sets boolean to true
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
    else if (game_array[0][3] == game_array[1][2] && game_array[1][2] == game_array[2][1] && game_array[2][1] == game_array[3][0]) {
        cout << e << " is the winner! Congratulations!" << endl;
        win += 1;
        won_game = true;
    }
}

// fills the array with numbers from 1 - 16
void fill_array(int (&game_array)[ROW_SIZE][COLUMN_SIZE]) {

    int fill_numbers = 1;

    // iterates through indices as fill numbers increments to put in consecutive numbers
    for (int index = 0; index < ROW_SIZE; index++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
           game_array[index][j] = fill_numbers;
            fill_numbers++;
        }
    }
}

// outputs the game board after each turn
void output_game_board(int (&game_array)[ROW_SIZE][COLUMN_SIZE]){
    
    for (int index = 0; index < ROW_SIZE; index++)
     {
         for (int j = 0; j < COLUMN_SIZE; j++)
         {
             // puts in O for any spots that holds -1
             if ( game_array[index][j] == -1){
                 cout << setfill(' ') << setw(5) << "O";
             }
             //outputs X for any spots that holds -2
             else if ( game_array[index][j] == -2){
                 cout << setfill(' ') << setw(5) << "X";
             }
             // if not -1 or -2, output the number stored in the array
             else
                 cout << setfill(' ') << setw(5) << game_array[index][j];
         }
    // enters line after each row for easier reading
     cout << endl << endl;
     }
}

// the game simulation
void game(){
   
    //declare and initialize variables
   
    int number_of_games = 0;
    
    // whether or not to continue playing
    bool play_again = true;
    string to_play_again;
   
    // counts the number of games won per player
    int x_games_won = 0;
    int o_games_won = 0;
    bool tie_game = false ;
    bool won_game = false;

    //initialize array for a tictactoe board
    int game_array[ROW_SIZE][COLUMN_SIZE] = {};

    // fill the declared array
    fill_array(game_array);
    
    // keeps playing until won game is true or there is over 16 turns
    
    while (play_again ){
        
        int turn = 0;

        
        while (!won_game && turn < 16 ){
            output_game_board(game_array);
            // indicates which player to start w
        
            if (number_of_games % 2 == 0){
                turn % 2 == 0 ? player_X(game_array, x_games_won, won_game) : player_O(game_array, o_games_won, won_game);
            }
            else  {
            turn % 2 == 0 ? player_O(game_array, o_games_won, won_game) : player_X(game_array, x_games_won, won_game);
            }
            // counts which turn the move is on
            turn++;
        }
        
        if (!won_game && turn == 16){
            cout << "Tie game! No winner this time! " << endl << endl;
            tie_game = true;
        }
        
        
        if (won_game || tie_game) {
        
            output_game_board(game_array);
            cout << "Do you wish to play again? (yes or no)  " << endl ;
            cin >> to_play_again;
        
            if (to_play_again == "yes" || to_play_again == "Yes" ) {
                play_again = true;
                won_game = false;
                fill_array(game_array);
                number_of_games++;
            }
            else {
                play_again = false;
            }
        }
    }
    output_stats( o_games_won, x_games_won);
    
}

int main() {
    
    game();
    
}
