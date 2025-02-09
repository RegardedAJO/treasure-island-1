#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <cstdlib>
#include <ctime> 

using namespace std;

void initialize(char [][3], int);  // prototype for function that will initialze the array that represents the grid/board

void draw_board(char [][3], int);   // prototype for function that draw the board

void player_turn(char [][3], int);    // prototype for function that will prompt the player for their move

bool check_player_winner(char [][3], int);  // prototype for function that will check if the player is a winner

bool check_comp_winner(char [][3], int);    // prototype for function that will check if computer is a winner

bool check_game_finished(char [][3], int);  // prototype for function that will check if the game is over, all spaces are filled

void comp_play(char [][3], int); // prototype for function that will use rand function to generate an integer for the computer move

int main()
{   
    // declare and initialize the 2d array that will hold the results of the games, will be limited to 10 games
    int winnerTurns[2][10];

    for (int winner_row_index = 0; winner_row_index < 2; winner_row_index++)
    {
        for (int winner_cols_index = 0; winner_cols_index < 10; winner_cols_index++)
        {
            winnerTurns[winner_row_index][winner_cols_index] = 0;
        }
    }

    // declare the char variable that will control the loop for playing the next game or stopping play
    // prompt user to play and enter the loop for the game session and initialze the game counter variable
    char play_again = 'y'; 

    cout << "Do you want to play Tic tac toe? 'y' for yes any other letter for no.\n";
   
    cin >> play_again;

    int game_counter = 0;

    while (tolower(play_again) == 'y' && game_counter < 10)   // loop that controls the game session based on player input and game count, limit is 10 games
    {   
        const int grid_rows = 3, grid_cols = 3; // initialize a constant for the dimensions of the array
       
        char grid_array[grid_rows][grid_cols]; // declare the grid array

        initialize(grid_array, grid_cols); // call the initialization function to fill the grid with blank spaces
        
        draw_board(grid_array, grid_cols);  // draw the initial empty board
        
        int player_turn_counter = 0, comp_turn_counter = 0;     // initialze turn counter for player and computer and a bool to check if the games is over
        bool game_finished = false;

        while (game_finished == false)      // this while loop controls the individual game
        {   int player_is_winner = 0, computer_is_winner = 1, tie = 2;

            // player choice starts here
            player_turn(grid_array, grid_cols);     // call player_turn function to get players move, increment player turn counter                
            
            player_turn_counter++;

            draw_board(grid_array, grid_cols);      // draw the board with players move

            
            game_finished = check_game_finished(grid_array, grid_cols); // call the check_game_finished function to check if grid is full/no more moves
                                                                        // assigns bool result to game finished

            // if game is over check if player is a winner, assign winner to the winner array, if not call the game a draw and assign draw to the 
            if (game_finished == true)                // the winner array and break out of the game loop, incremenent the game counter, output results
            {
                bool did_player_win_on_last_move = check_player_winner(grid_array, grid_cols);

                if (did_player_win_on_last_move == true)
                {
                    winnerTurns[0][game_counter] = player_is_winner;
                    winnerTurns[1][game_counter] = player_turn_counter;
                    cout << "Player wins\n";
                    game_counter++;
                    break;
                }
                else
                {
                    winnerTurns[0][game_counter] = tie;
                    winnerTurns[1][game_counter] = player_turn_counter;
                    game_counter++;
                    cout << "Its a draw\n";
                    break;
                }
            }
            
            // check if player is a winner, if board is not full, assign winner to winner array, break out of loop if there is a winner, increment game counter
            game_finished = check_player_winner(grid_array, grid_cols);     // output results

            if (game_finished == true)
            {
                winnerTurns[0][game_counter] = player_is_winner;
                winnerTurns[1][game_counter] = player_turn_counter;
                cout << "Player wins\n";
                game_counter++;
                break;
            }
        
    
            
            comp_play(grid_array, grid_cols);   // call the comp_play function to have the computer place its move on the board, increment comp turn counter

            comp_turn_counter++;

            draw_board(grid_array, grid_cols);      // draw the board with the computers move on it
            
            // check if all moves made, check if computer won on last move, assigns results to the winner array, increment game counter,
            game_finished = check_game_finished(grid_array, grid_cols);     // break out of current game and output result

            if (game_finished == true)
            {
                bool did_comp_win_on_last_move = check_comp_winner(grid_array, grid_cols);

                if (did_comp_win_on_last_move == true)
                {
                    winnerTurns[0][game_counter] = computer_is_winner;
                    winnerTurns[1][game_counter] = comp_turn_counter;
                    cout << "Computer wins\n";
                    game_counter++;
                    break;
                }
                else
                {
                    winnerTurns[0][game_counter] = tie;
                    winnerTurns[1][game_counter] = comp_turn_counter;
                    cout << "Its a draw\n";
                    game_counter++;
                    break;
                }
            }
            
            
            // check if computer won, if board is not full, if computer won update winner array, increment game counter, break of this game and output result
            game_finished = check_comp_winner(grid_array, grid_cols);

            if (game_finished == true)
            {
                winnerTurns[0][game_counter] = computer_is_winner;
                winnerTurns[1][game_counter] = comp_turn_counter;
                cout << "Computer wins\n";
                game_counter++;
                break;
            }
           
        }
        cout << "Play again? 'y' for yes any other letter for no.\n"; // prompts user to play again
        cin >> play_again;
    }

    // this block will find and print the winner by iterating through the winner array and finidng the lowest number of turns that was not a tie
    int lowest_number_turns = 6, who_is_winner;
    

    for (int col_num = 0; col_num < 10; col_num++)
    {   

        if (winnerTurns[1][col_num] != 0 && winnerTurns[1][col_num] < lowest_number_turns && winnerTurns[0][col_num] != 2)
        {   
            lowest_number_turns = winnerTurns[1][col_num];
            
            who_is_winner = winnerTurns[0][col_num];
        }
    }

    string winner;

    if (who_is_winner == 0)
    {
        winner = "You"; 
    }
    else
    {
        winner = "the computer";
    }

    cout << "Winner is " << winner << " who won in " << lowest_number_turns << " turns\n";
    
    return 0; // end the program
}


// declares initialize function, accepts the grid array as a parameter, populates the 2d char grid array that will represent the board, with empty spaces ' '. returns nothing
void initialize(char grid_array[][3], int grid_row)
{  
    for (int grid_row = 0; grid_row < 3; grid_row++)
    {
        for (int grid_cols = 0; grid_cols < 3; grid_cols++)
        {
            grid_array[grid_row][grid_cols] = ' ';
        }
    }
}

// accepts the 2d char grid_array and draws the game board based on the current moves, clears the screen before drawing the updated board, returns nothing
void draw_board(char grid_array[][3], int grid_row)
{
    system("cls");

    cout << "________________________\n";
    cout << "|  " << grid_array[0][0] << "   " << "|" << "   " << grid_array[0][1] << "   " << "|" << "   " << grid_array[0][2] << "   |" << endl;
    cout << "|______|_______|_______|" << endl;
    cout << "|  " << grid_array[1][0] << "   " << "|" << "   " << grid_array[1][1] << "   " << "|" << "   " << grid_array[1][2] << "   |" << endl;
    cout << "|______|_______|_______|" << endl;
    cout << "|  " << grid_array[2][0] << "   " << "|" << "   " << grid_array[2][1] << "   " << "|" << "   " << grid_array[2][2] << "   |\n";
    cout << "|______|_______|_______|\n";
}


// accepts the grid_array, prompts player for their move, checks to see if it is a valid move, and updates the grid_array to place 'X' in players choice, returns nothing
void player_turn(char grid_array[][3], int grid_row)
{
    string user_input, player_row_choice, player_col_choice;
    bool valid_choice = false, valid_move = false;
    
    cout << "Make your move in the format: row-column\n";

    cin >> user_input;

    player_row_choice = user_input[0];
    player_col_choice = user_input[2];
    

    while (valid_choice == false)   // will evaluate if the player made a valid choice, for example entering the letter 'a' instead of a number or a number out of range
    {    
        
        if ((player_row_choice == "0" | player_row_choice == "1" | player_row_choice == "2") && (player_col_choice == "0" | player_col_choice == "1" | player_col_choice == "2"))
        {
            valid_choice = true;
            break;
        }
        else
        {
            cout << "Invalid character, must be a '0', '1' or '2'. Enter again in format row-column\n";

            cin >> user_input;

            player_row_choice = user_input[0];
            player_col_choice = user_input[2];
        }
    }
    

    
    int player_row_choice_as_int, player_col_choice_as_int;

    player_row_choice_as_int = stoi(player_row_choice);
    player_col_choice_as_int = stoi(player_col_choice);

    while (valid_move == false) // will check if the space is empty
    {
        
        if (grid_array[player_row_choice_as_int][player_col_choice_as_int] == ' ')
        {

            valid_move = true;
            break;
        }
        else
        {   
            cout << "That space is occupied, choose again\n";
            cin >> user_input;

            player_row_choice = user_input[0];
            player_col_choice = user_input[2];

            player_row_choice_as_int = stoi(player_row_choice);
            player_col_choice_as_int = stoi(player_col_choice);
            
        }
    }

    grid_array[player_row_choice_as_int][player_col_choice_as_int] = 'X';

}


// accepts the grid_array and uses an if statement to check all possibilites if the player is a winner, returns true if there is a winner, false if no winner
bool check_player_winner(char grid_array[][3], int grid_row)
{
    if ((grid_array[0][0] == 'X' && grid_array[0][1] == 'X' && grid_array[0][2] == 'X') |//top row 
            (grid_array[1][0] == 'X' && grid_array[1][1] == 'X' && grid_array[1][2] == 'X') |   //middle row
            (grid_array[2][0] == 'X' && grid_array[2][1] == 'X' && grid_array[2][2] == 'X') |   // bottom row
            (grid_array[0][0] == 'X' && grid_array[1][0] == 'X' && grid_array[2][0] == 'X') |   //first col
            (grid_array[0][1] == 'X' && grid_array[1][1] == 'X' && grid_array[2][1] == 'X') |   //second col
            (grid_array[0][2] == 'X' && grid_array[1][2] == 'X' && grid_array[2][2] == 'X') |   // third col
            (grid_array[0][0] == 'X' && grid_array[1][1] == 'X' && grid_array[2][2] == 'X') |   // diagonal top left to bottom right
            (grid_array[0][2] == 'X' && grid_array[1][1] == 'X' && grid_array[2][0] == 'X'))  // diagonal top right to bottom left
            {
                return true;
            }
    else
    {
        return false;
    }
}


// accepts the grid_array and uses an if statement to check all possibilites if the computer is a winner, returns true if there is a winner, false if no winner
bool check_comp_winner(char grid_array[][3], int grid_row)
{
    if ((grid_array[0][0] == 'O' && grid_array[0][1] == 'O' && grid_array[0][2] == 'O') |//top row 
            (grid_array[1][0] == 'O' && grid_array[1][1] == 'O' && grid_array[1][2] == 'O') |   //middle row
            (grid_array[2][0] == 'O' && grid_array[2][1] == 'O' && grid_array[2][2] == 'O') |   // bottom row
            (grid_array[0][0] == 'O' && grid_array[1][0] == 'O' && grid_array[2][0] == 'O') |   //first col
            (grid_array[0][1] == 'O' && grid_array[1][1] == 'O' && grid_array[2][1] == 'O') |   //second col
            (grid_array[0][2] == 'O' && grid_array[1][2] == 'O' && grid_array[2][2] == 'O') |   // third col
            (grid_array[0][0] == 'O' && grid_array[1][1] == 'O' && grid_array[2][2] == 'O') |   // diagonal top left to bottom right
            (grid_array[0][2] == 'O' && grid_array[1][1] == 'O' && grid_array[2][0] == 'O'))  // diagonal top right to bottom left
            {
                return true;
            }
    else
    {
        return false;
    }
}


// accepts grid_array as a parameter, function checks if there is any white space in the grid_array, if there is white space present game continues and returns false, 
// if all spaces are full return true
bool check_game_finished(char grid_array[][3], int grid_row)
{
    if (grid_array[0][0] == ' ' | grid_array[0][1] == ' ' | grid_array[0][2] == ' ' | grid_array[1][0] == ' ' | grid_array[1][1] == ' ' | grid_array[1][2] == ' ' | grid_array[2][0] == ' ' | grid_array[2][1] == ' ' | grid_array[2][2] == ' ' )
        {
            return false;
        }
        else
        {
            return true;
        }
}

// accepts grid array as a parameters, uses random function to create a random int for computer choice/play, checks to see if it is a valid move, if so updates the grid array with comp move
void comp_play(char grid_array[][3], int grid_row)
{   
    srand(time(0));
    int comp_choice_row = rand()% 3;
    int comp_choice_col = rand()% 3;
    bool valid_comp_move = false;

    while (valid_comp_move == false)
    {
        if (grid_array[comp_choice_row][comp_choice_col] == ' ')
        {
            valid_comp_move = true;
            break;
        }
        else
        {
            comp_choice_row = rand()% 3;       
            comp_choice_col = rand()% 3;
        }
    }
    grid_array[comp_choice_row][comp_choice_col] = 'O';

}

