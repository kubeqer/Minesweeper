#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard() {
    first_move = true;
    width = 10;
    height = 6;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            board[row][col].hasFlag = false;
            board[row][col].hasMine = false;
            board[row][col].isRevealed = false;
        }
    }
    //HAS MINE r = 0 col = 0
    board[0][0].hasMine = true;
    //IS DISCOVERED r = 1 col = 1
    board[1][1].isRevealed = true;
    //FLAG AND MINE r = 0 col = 2
    board[2][0].hasMine = true;
    board[2][0].hasFlag = true;

}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {
    first_move = true;
    this->width = width;
    this->height = height;
    int area = width * height;
    game.mode = mode;
    //CLEARING THE BOARD
    for (auto row = 0; row < height; row++) {
        for (auto col{0}; col < width; col++) {
            board[row][col].hasFlag = false;
            board[row][col].hasMine = false;
            board[row][col].isRevealed = false;
        }
    }
    //DEBUG MODE
    if (mode == DEBUG) {
        for (auto col{0}; col < width; col++) // FIRST ROW CONDITION
            board[col][0].hasMine = true;
        for (auto row{0}; row < height; row += 2) //FIRST COLUMN CONDITION
            board[0][row].hasMine = true;
        if (width > height) { // DIAGONAL CONDITION
            for (auto diagonal{1}; diagonal < height; diagonal++)
                board[diagonal][diagonal].hasMine = true;
        } else {
            for (auto diagonal{1}; diagonal < width; diagonal++)
                board[diagonal][diagonal].hasMine = true;
        }
    }
        // EASY MODE
    else if (auto sumOfMines{0}; mode == EASY) {
        while (sumOfMines < ceil(area / 10)) {
            for (auto row{0}; row < height; row++) {
                for (auto col{0}; col < width; col++) {
                    unsigned int random_number = rand() % 1000;
                    if (!board[row][col].hasMine && random_number % 5 == 0) {
                        board[row][col].hasMine = true;
                        ++sumOfMines;
                        if (sumOfMines == ceil(area / 10))
                            return;
                    }
                }
            }
        }
    }
        // NORMAL MODE
    else if (auto sumOfMines{0};  mode == NORMAL) {
        while (sumOfMines < ceil(area / 5)) {
            for (auto row{0}; row < height; row++) {
                for (auto col{0}; col < width; col++) {
                    unsigned int random_number = rand() % 1000;
                    if (!board[row][col].hasMine && random_number % 5 == 0) {
                        board[row][col].hasMine = true;
                        ++sumOfMines;
                        if (sumOfMines == ceil(area / 5))
                            return;
                    }
                }
            }
        }
    }
        // HARD MODE
    else if (auto sumOfMines{0}; mode == HARD) {
        while (sumOfMines < ceil(3 * area / 10)) {
            for (auto row{0}; row < height; row++) {
                for (auto col{0}; col < width; col++) {
                    unsigned int random_number = rand() % 1000;
                    if (!board[row][col].hasMine && random_number % 5 == 0) {
                        board[row][col].hasMine = true;
                        ++sumOfMines;
                        if (sumOfMines == ceil(3 * area / 10))
                            return;
                    }
                }
            }
        }
    }
}

void MinesweeperBoard::debug_display() const {
    std::cout << "     ";
    for (auto col_index{0}; col_index < width; col_index++) {
        std::cout << "  " << col_index;
        if (col_index > 9)
            std::cout << " ";
        else
            std::cout << "  ";
    }
    std::cout << std::endl;
    for (auto row{0}; row < height; row++) {
        std::cout << "  " << row;
        if (row > 9)
            std::cout << " ";
        else
            std::cout << "  ";
        for (auto col = 0; col < width; col++) {
            std::cout << "[";
            if (board[row][col].hasMine)
                std::cout << "M";
            else
                std::cout << ".";
            if (board[row][col].isRevealed)
                std::cout << "o";
            else
                std::cout << ".";
            if (board[row][col].hasFlag)
                std::cout << "f";
            else
                std::cout << ".";
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}

int MinesweeperBoard::getBoardWidth() const {
    return width;
}

int MinesweeperBoard::getBoardHeight() const {
    return height;
}

int MinesweeperBoard::getMineCount() const {
    int sumOfMines{0};
    for (int row{0}; row < height; row++) {
        for (int col{0}; col < width; col++) {
            if (board[row][col].hasMine)
                ++sumOfMines;
        }
    }
    return sumOfMines;
}

GameState MinesweeperBoard::getGameState() const {
    int sumOfMines{0};
    int sumOfUnrevealed{0};
    for (auto row{0}; row < height; row++) {
        for (auto col{0}; col < width; col++) {
            if (board[row][col].hasMine)
                ++sumOfMines;
            if (!board[row][col].isRevealed)
                ++sumOfUnrevealed;
        }
    }
    for (auto row{0}; row < height; row++) {
        for (auto col{0}; col < width; col++) {
            if (board[row][col].hasMine && board[row][col].isRevealed)
                return FINISHED_LOSS;
            else if (sumOfMines == sumOfUnrevealed) {
                return FINISHED_WIN;
            }
        }
    }
    return RUNNING;
}

int MinesweeperBoard::countMines(int row, int col) const {
    int sumOfMines{0};
    if ((row >= height || row < 0) || (col >= width || col < 0))
        return -1;
    else {
        for (auto row_h{row - 1}; row_h <= row + 1; row_h++) {
            for (auto col_h{col - 1}; col_h <= col + 1; col_h++) {
                if ((row_h < height && row_h >= 0) && (col_h < width && col_h >= 0)) {
                    if (board[row_h][col_h].hasMine)
                        ++sumOfMines;
                }
            }
        }
        return sumOfMines;
    }
}

bool MinesweeperBoard::hasFlag(int row, int col) const {
    if (row >= height || col >= width || board[row][col].isRevealed || !board[row][col].hasFlag)
        return false;
    else if (board[row][col].hasFlag)
        return true;
}

bool MinesweeperBoard::isRevealed(int row, int col) const {
    if (board[row][col].isRevealed)
        return true;
    else
        return false;
}

void MinesweeperBoard::toggleFlag(int row, int col) {
    if (row >= height || col >= width || row < 0 || col < 0 || board[row][col].isRevealed || getGameState() == !RUNNING)
        return;
    else
        board[row][col].hasFlag = !board[row][col].hasFlag;
}

void MinesweeperBoard::revealField(int row, int col) {
    if (row < height && col < width && row >= 0 && col >= 0 && getGameState() == RUNNING &&
        !board[row][col].isRevealed && !board[row][col].hasFlag) {
        if (!first_move) {
            board[row][col].isRevealed = true;
            return;
        }
        if (first_move) {
            first_move = false;
            if (int sumOfMines{0}; board[row][col].hasMine && game.mode != DEBUG) {
                unsigned int random_number;
                while (sumOfMines == 0) {
                    for (auto row_h{0}; row_h < height; row_h++) {
                        for (auto col_h{0}; col_h < width; col_h++) {
                            random_number = rand() % 1000;
                            if (!board[row_h][col_h].hasMine && random_number % 5 == 0) {
                                board[row_h][col_h].hasMine = true;
                                board[row][col].hasMine = false;
                                ++sumOfMines;
                                break;
                            }
                        }
                        if (sumOfMines == 1)
                            break;
                    }
                }
                board[row][col].isRevealed = true;
                return;
            } else {
                board[row][col].isRevealed = true;
            }

        }
    } else {
        return;
    }
}

std::string MinesweeperBoard::getFieldInfo(int row, int col) const {
    if ((row < 0 || row >= height) || (col < 0 || col >= width))
        return "#";
    else if (!board[row][col].isRevealed && board[row][col].hasFlag)
        return "F";
    else if (!board[row][col].isRevealed && !board[row][col].hasFlag)
        return "_";
    else if (board[row][col].isRevealed && board[row][col].hasMine)
        return "x";
    else if (board[row][col].isRevealed && countMines(row, col) == 0)
        return " ";
    else
        return std::to_string(countMines(row, col));
}