/*






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

    cout << get_computer_move() << endl;




    return 0;
}
