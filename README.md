Minesweeper Game with SFML
==========================

Introduction
------------
This Minesweeper game, created using the SFML, is a project developed for an object-oriented programming class.
It provides a graphical user interface for a Minesweeper.

Features
--------

*   **Graphical User Interface:** Enjoy Minesweeper with an interactive and visual interface.
*   **Customizable Settings:** Adjust the field size and difficulty level according to your preferences.
*   **Winning and Losing States:** Experience game over screens with a victory or loss message.
*   **Text and Graphic Display:** The game displays both text-based and graphical representations of the Minesweeper board.
    If you want to use the text version you have to change main.cpp to:
        
        int main(){
        MinesweeperBoard board(width, height, EASY/NORMAL/HARD);
        MSBoardTextView view(board);
        MSTextController cntrl(board, view);
        cntrl.play();
        }


Getting Started
---------------
### Prerequisites

Make sure you have SFML installed on your system. You can download SFML from https://www.sfml-dev.org/download.php.
### Installation

Clone the repository:

    git clone https://github.com/kubeqer/Minesweeper.git

Build the project using CMake.


### Controls

* **Arrow keys:** Navigate through menus and game board.
* **Enter key:** Confirm selections in the menu.
* **Left mouse button:** Reveal a field.
* **Right mouse button:** Toggle a flag.

Customization
------------

### Adjust the game settings by navigating through the menu:

* **Field Size:** Choose the number of fields in one line (the field will be square).
* **Difficulty Level:** Select between Easy, Normal, or Hard mode.

Game Loop
----------

* **Menu:** Start the game by navigating through the menu. Customize game settings.
* **Gameplay:** Reveal fields and toggle flags to uncover the Minesweeper board.
* **Winning:** Successfully reveal all non-bomb fields to win the game.
* **Losing:** Uncover a bomb, and the game enters a loss state.

Acknowledgments
---------------

Thanks to the creators of SFML!

Enjoy playing Minesweeper!
----------------------