#include <iostream>
#include "life_board.h"

using namespace std;

int main(int argc, char** argv) {


    life_board board(20,10);

    board.random_state();
//    board.print_board_state(cout);
    board.render(cout);
    int x;
    while (cin >> x) {
        board.next_board_state();
        board.render(cout);
    }

//    life_board board(4,4);
//    life_board::board_type init2 = {
//            {0,0,0,0},
//            {1,1,1,0},
//            {1,1,1,0},
//            {0,0,0,0}
//    };
//
//    life_board::board_type next_state2 = {
//            {0,1,0,0},
//            {1,0,1,0},
//            {1,0,1,0},
//            {0,1,0,0}
//    };
//
//    if ((board.unit_test(init2, next_state2))) {
//        cout << "PASSED 2" << endl;
//    }
//    else {
//        cout << "FAILED 2" << endl;
//        board.print_board_state(cout);
//    }
    return 0;
}
