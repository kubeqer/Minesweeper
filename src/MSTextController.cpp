#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"


MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : board(board), view(view) {}

void MSTextController::play() {
    int n;
    int row;
    int col;
    GameState state;
    state = board.getGameState();
    while (state == RUNNING) {
        view.display();
        std::cout << "WHAT DO YOU WANT TO DO?\n1. TOOGLE FLAG 2. REVEAL FIELD\n";
        std::cin >> n;
        switch (n) {
            case 1:
                std::cout << "GIVE ME ROW AND COL INDEX NUMBER (FROM 0)" << std::endl;
                std::cin >> row >> col;
                board.toggleFlag(row, col);
                break;
            case 2:
                std::cout << "GIVE ME ROW AND COL INDEX NUMBER (FROM 0)" << std::endl;
                std::cin >> row >> col;
                board.revealField(row, col);
                break;
        }
        state = board.getGameState();
    }

    if (state == FINISHED_LOSS) {
        view.display();
        std::cout << "YOU LOST";
        return;
    }
    if (state == FINISHED_WIN) {
        view.display();
        std::cout << "YOU WON";
        return;
    }
}