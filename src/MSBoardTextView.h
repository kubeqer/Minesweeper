#ifndef MSBOARDTEXTVIEW_H__
#define MSBOARDTEXTVIEW_H__

#include "MinesweeperBoard.h"
// this class provides a text-based view of the Minesweeper board.
class MSBoardTextView {
    int width;
    int height;
    MinesweeperBoard &board;
public:

    MSBoardTextView(MinesweeperBoard &board);

    // this method displays the current state of the Minesweeper board to the console.
    // it includes the field information for each cell and labels for rows and columns.
    void display() const;
};

#endif