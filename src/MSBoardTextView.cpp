#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) : board(board) {
    width = board.getBoardWidth();
    height = board.getBoardHeight();
}

void MSBoardTextView::display() const {
    board.debug_display();
    std::cout << "     ";
    for (auto col_index{0}; col_index < width; col_index++) {
        std::cout << " " << col_index;
        if (col_index > 9)
            std::cout << "";
        else
            std::cout << " ";
    }
    std::cout << std::endl;
    for (auto row{0}; row < height; row++) {
        std::cout << "  " << row;
        if (row > 9)
            std::cout << " ";
        else
            std::cout << "  ";
        for (auto col{0}; col < width; col++) {
            std::cout << "[" << board.getFieldInfo(row, col) << "]";
        }
        std::cout << std::endl;
    }
}