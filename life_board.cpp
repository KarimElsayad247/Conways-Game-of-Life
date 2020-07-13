//
// Created by karim on 12-Jul-20.
//
#include <cstdlib>     // srand, rand
#include <ctime>       // time
#include <string>
#include <algorithm>
#include <ncurses.h>

#include "life_board.h"

using namespace std;

life_board::life_board(int w, int h) {
    width = w;
    height = h;

    // prepare board height
    vector<int> v;
    for (row_type i = 0; i != height; ++i) {
        board_state.push_back(v);
    }

    // initialize board by setting every cell to dead
    for (row_type i = 0; i != height; ++i) {
        for (column_type j = 0; j != width; j++) {
            board_state[i].push_back(0);
        }
    }

}

void life_board::dead_state() {

    // set every cell to dead
    for (row_type i = 0; i != height; ++i) {
        for (column_type j = 0; j != width; j++) {
            board_state[i][j] = 0;
        }
    }
}

void life_board::random_state() {

    // initialize random seed
    srand(time(nullptr));

    // set every cell to either 0 or 1
    for (row_type i = 0; i != height; ++i) {
        for (column_type j = 0; j != width; j++) {
            board_state[i][j] = (rand() % 100 > 50)? 0 : 1;
        }
    }
}

void life_board::next_board_state() {
    // create new board to store new state so that changes don't ripple
    std::vector<std::vector<int> > new_board_state = board_state;

    // iterate over each cell, and set them appropriately
    for (row_type i = 0; i != height; ++i) {
        for (column_type j = 0; j != width; j++) {
            modify_cell(i, j, new_board_state);
        }
    }

    // new board overwrites old board
    board_state = new_board_state;
}

void life_board::print_board_state(std::ostream& out) {

    // print every cell
    for (row_type i = 0; i != height; ++i) {
        for (column_type j = 0; j != width; j++) {
            out << board_state[i][j] << " ";
        }
        out << endl;
    }
}

// void life_board::curses_render() {
//     // construct top and bottom border
//     string top_bottom(board_state[0].size() + 2, '-');

//     printw(top_bottom.c_str());

//         // print contents of every line
//     for (row_type i = 0; i != height; ++i) {
//         printw ("|");
//         for (column_type j = 0; j != width; j++) {
//             printw(((board_state[i][j] == 0) ? " " : "#"));
//         }
//         printw("|");
//     }

//     printw(top_bottom.c_str());

//     refresh();
// }

// print every in a pretty fasion
void life_board::render(ostream &out) {

    // construct top and bottom border
    string top_bottom(board_state[0].size() + 2, '-');

    // print top border
    cout << top_bottom << endl;

    // print contents of every line
    for (row_type i = 0; i != height; ++i) {
        cout << "|";
        for (column_type j = 0; j != width; j++) {
            out <<((board_state[i][j] == 0) ? " " : "#");
        }
        cout << "|";
        out << endl;
    }

    // print bottom border
    cout << top_bottom << endl;
}

void life_board::modify_cell(row_type i, column_type j, board_type& new_board) {
    int population = 0;
    column_type zero_c = 0;
    row_type zero_r = 0;
    if (i == 0 || j == 0 || i == height - 1 || j == width - 1) { // edge cell
        for (row_type r = max(zero_r, i - 1); r <= min(i + 1, height - 1); ++r) {
            for (column_type c = max(zero_c, j - 1); c <= min(j + 1, width - 1); ++c) {
                if (board_state[r][c] == 1) // get population numbers from old board
                    ++population;
            }
        }
    }
    else {  // internal cell
        for (row_type r = i - 1; r <= i + 1; ++r) {
            for (column_type c = j - 1; c <= j + 1; ++c) {
                if (board_state[r][c] == 1) // get population numbers from old board
                    ++population;
            }
        }
    }

    if(board_state[i][j] == 1) { // is a live cell
        --population;
        if (population < 2 || population > 3)
            new_board[i][j] = 0;  // under population and over population
        else
            new_board[i][j] = 1;  // just right
    }
    else { // is a dead cell
        if (population == 3)
            new_board[i][j] = 1;  // reproduction
    }
}

bool life_board::unit_test(board_type& initial_state, board_type& expected_next_state) {
    board_state = initial_state;
    next_board_state();
    return board_state == expected_next_state;
}
