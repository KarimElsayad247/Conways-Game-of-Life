//
// Created by karim on 12-Jul-20.
//

#ifndef CONWAY_GAME_OF_LIFE_LIFE_BOARD_H
#define CONWAY_GAME_OF_LIFE_LIFE_BOARD_H

#include <vector>
#include <iostream>

class life_board {
public:
    typedef int row_type;
    typedef int column_type;
    typedef std::vector<std::vector<int> > board_type;

public:
    life_board(int width, int height);
    void dead_state();
    void random_state();
    void print_board_state(std::ostream& out);
    void render(std::ostream& out);
    void curses_render();
    void next_board_state();
    bool unit_test(board_type& initial_state, board_type& expected_next_state);

private:
    column_type width;
    row_type height;
    std::vector<std::vector<int> > board_state;
    void modify_cell(row_type i, column_type j, board_type &new_board);




};


#endif //CONWAY_GAME_OF_LIFE_LIFE_BOARD_H
