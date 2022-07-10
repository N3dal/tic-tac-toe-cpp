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

#endif