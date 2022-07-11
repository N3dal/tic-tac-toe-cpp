/*
this file contain all function for the game and also the game defaults.
*/

#ifndef GAME
#define GAME

// new game defaults.
int available_moves[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
char game_map[9] = {' ', 'X', 'O', ' ', ' ', ' ', ' ', ' ', ' '};


// game prototypes.
void print_game_map();
int get_user_move();
int is_available_move(int );


void print_game_map(){
    /*
    draw the game map for the users and update it when they do any move.

    */


    std:: cout << "╭───┬───┬───╮\n";
    std:: cout << "│ " << game_map[0] <<" │ " << game_map[1] << " │ "<< game_map[2]<< " │\n";
    std:: cout << "├───┼───┼───┤\n";
    std:: cout << "│ " << game_map[3] <<" │ " << game_map[4] << " │ "<< game_map[5]<< " │\n";
    std:: cout << "├───┼───┼───┤\n";
    std:: cout << "│ " << game_map[6] <<" │ " << game_map[7] << " │ "<< game_map[8]<< " │\n";
    std:: cout << "╰───┴───┴───╯\n";



}

int get_user_move(std::string msg){
    /*
    Docstring
    */

    int usr_input;

    std::cout << msg;
    std::cin >> usr_input;

    return usr_input;

}

int is_available_move(int move){
    /*
    check out if either computer or the user move is available or not,
    return '1' if move is available other wise is return '0'.
    */
    int available = 0;
    for (int i=0; i<9; i++){
        if (move == available_moves[i]){
            available = 1;
            break;
        }

    }

    return available;
}

#endif