#ifndef MSTEXTCONTROLLER_H__
#define MSTEXTCONTROLLER_H__

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
// this class serves as a controller for the Minesweeper game, interacting with the user through
// a text-based interface. It takes references to a MinesweeperBoard and an MSBoardTextView for
// handling game logic.
class MSTextController {
    MinesweeperBoard &board;
    MSBoardTextView &view;
public:


    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);

    // this method facilitates the interaction between the user and the Minesweeper game. It displays
    // the current state of the game through the provided MSBoardTextView and prompts the user for
    // actions such as toggling flags or revealing fields. The game continues until a win or loss condition
    // is reached.
    // It:
    // - continues game loop until win or loss condition is reached
    // - displays current state of the Minesweeper board
    // - process user input based on choice - 1 toggle flag, 2 for reveal field
    // - display final game state based on win or loss.
    void play();
};

#endif