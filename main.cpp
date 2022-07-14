/*

TODO: ADD colors;




*/




#include <iostream>
#include <ctime>
#include <random>
#include "tools.h"
#include "game.h"

using namespace std;


int main(void){

    // wipe terminal at first.
    clear();

    // print_game_map();
    // cout << is_available_move(12) << endl;


    main_menu();
    cout << get_usr_choice();



    return 0;
}
