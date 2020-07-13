#include <iostream>
#include <vector>


#include "life_board.h"

using namespace std;


void print_results(life_board board, life_board::board_type initial, life_board::board_type expected, int test_number) {
    if ((board.unit_test(initial, expected))) {
        cout << "PASSED " << test_number << endl;
    }
    else {
        cout << "FAILED " << test_number << endl;
        board.print_board_state(cout);
        exit(-1);   
    }
}

int main() {

    life_board board(4,4);

    life_board::board_type init1 = {
                                   {0,0,0,0},
                                   {0,0,0,0},
                                   {0,0,0,0},
                                   {0,0,0,0}};

    life_board::board_type expected1 = {
                                         {0,0,0,0},
                                         {0,0,0,0},
                                         {0,0,0,0},
                                         {0,0,0,0}
                                         };
                                         
    life_board::board_type init2 = {
                                   {1,1,0,0},
                                   {1,0,0,0},
                                   {0,0,0,0},
                                   {0,0,0,0}
                                   };

    life_board::board_type expected2 = {
                                         {1,1,0,0},
                                         {1,1,0,0},
                                         {0,0,0,0},
                                         {0,0,0,0}
                                         };
                                         
                                             
    life_board::board_type init3 = {
                                        {0,0,0,0},
                                        {1,1,1,0},
                                        {1,1,1,0},
                                        {0,0,0,0}
                                };

    life_board::board_type expected3 = {
                                            {0,1,0,0},
                                            {1,0,1,0},
                                            {1,0,1,0},
                                            {0,1,0,0}
                                    };

    life_board::board_type init4 = {
                                        {1,0,0,1},
                                        {0,1,1,0},
                                        {0,1,1,0},
                                        {1,0,0,1}
                                };

    life_board::board_type expected4 = {
                                            {0,1,1,0},
                                            {1,0,0,1},
                                            {1,0,0,1},
                                            {0,1,1,0}
                                    };
                                    


    print_results(board, init1, expected1, 1);
    print_results(board, init2, expected2, 2);
    print_results(board, init3, expected3, 3);
    print_results(board, init4, expected4, 4);
}