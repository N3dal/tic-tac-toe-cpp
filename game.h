/*
this file contain all function for the game and also the game defaults.
*/

#ifndef GAME
#define GAME

// new game defaults.
int available_moves[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

// i use the string type instead of char type,
// to be able to concatenate the chars later.
std::string game_map[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};


// game prototypes.
void print_game_map();
int get_user_move(void);
int get_computer_move(void);
int is_available_move(int );
int who_win(std::string, std::string);
int any_available_move(void);
void main_menu(void);
int get_usr_choice(void);
void new_game(void);


void print_game_map(void){
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

    // make sure to remove one from the user input.
    usr_input--;

    while (is_available_move(usr_input)==0){
            // warn the user.
            std::cout << "This is not available move!!!\n";

            std::cout << msg;
            std::cin >> usr_input;

            // make sure to remove one from the user input.
            usr_input--;
    }

    return usr_input;

}

int get_computer_move(void){
    /*
    generate random number depending on the available,
    in simple words select random choice from the available moves. 
    */

    srand(time(0));

    int random_choice = rand() % 9;


    // note -1 indicate for not available place in the game-board.

    while(is_available_move(random_choice)){
        random_choice = rand() % 9;
    }

    return available_moves[random_choice];

    
}

int is_available_move(int move){
    /*
    check out if either computer or the user move is available or not,
    return '1' if move is available other wise is return '0'.
    */

    for (int i=0; i<9; i++){
        if (move == available_moves[i]){
            return 1;
        }

    }

    return 0;
}

int who_win(std::string usr_character, std::string computer_character){
    /*
    check out if the user win or the computer win.
    and tell who is win depending on the user char,
    and computer char.

    return 1 if user win.
    return 2 if computer win.
    return 0 if its draw.
    return -1 if game still going.
    */

    // all available moves to win in the game.
    int moves_to_win[8][3] = {

        // horizontal moves to win.
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},

        // vertical moves to win.
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},

        // diagonal moves to win.
        {0, 4, 8},
        {2, 4, 6},
    };

    // create temp string to check the moves.
    std::string moves_check_string;

    // create temp indices for game-board places.
    int place0, place1, place2;

    std::string usr_pattern_to_win = usr_character + usr_character + usr_character;
    std::string computer_pattern_to_win = computer_character + computer_character + computer_character;




    for (int i=0; i<8; i++){

        place0 = moves_to_win[i][0];
        place1 = moves_to_win[i][1];
        place2 = moves_to_win[i][2];

        moves_check_string = game_map[place0] + game_map[place1] + game_map[place2];

        if (moves_check_string==usr_pattern_to_win){
            // usr win.
            return 1;
        }

        else if (moves_check_string==computer_pattern_to_win){
            // computer win.
            return 2;
        }

    }

    // if game still going.
    return -1;
}

int any_available_move(void){
    /*
        checkout if still there any available moves in the available move array.
        if there's any available move then return 1, other wise return 0;
    */
    

    for(int i=0; i<9; i++){
        if (available_moves[i] != -1){
            return 1;
        }
    }

    return 0;
}

void main_menu(void){
    /*
    print the main menu to user.
    */

    clear();

    std::string OPTIONS[2] = 
    {
        "New Game",
        "Exit"
    };

    for (int i=0; i<2; i++){
        std::cout << "\t\t[" << i+1 << "]  " << OPTIONS[i] << std::endl; 
    }


    // now get the usr choice.
    int usr_choice = 0;
    usr_choice = get_usr_choice();
    
    if (usr_choice == -1){
        // kill the program for any wrong input.
        exit(3);
    }

    else if (usr_choice == 1){
        // start new game.
        new_game();
    }

    else if (usr_choice == 2){
        // quit from the game.
        exit(3);
    }
    
}

int get_usr_choice(void){
    /*
    get the usr choice for the main menu.
    return -1 if there's any wrong.
    for example if the user give us char or out of range,
    choice like number 4.
    */
    int usr_input = 0;
    std::cout << ":";
    std::cin >> usr_input;

    if (size_t(usr_input) == 0){
        // that's mean it's not integer.
        return -1;
    }

    if (usr_input!=1 && usr_input!=2){
        // that's mean the number is out of range.
        return -1;
    }

    return usr_input;
}

void new_game(void){
    /*
    start new game for the users.
    */

    // re-init the available_moves to the default.
    int available_moves[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // re-init the game_map to the default.
    std::string game_map[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};


    print_game_map();


    // while (who_win() == -1 && any_available_move()){
    //     // game main-loop.
        


    // }




}


#endif
