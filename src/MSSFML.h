#ifndef MINESWEEPER_MSSFML_H
#define MINESWEEPER_MSSFML_H


#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
// this class handles the graphical user interface and game loop for Minesweeper using the
// SFML. it includes methods for displaying menus, drawing
// the Minesweeper board, and playing the game.
class MSSFML {
    int howManyFields;
    int windowsizeWidth;
    int windowsizeHeight;
    int square_length;
    GameMode gamemode;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape squareUnrevealed;
    sf::RectangleShape squareRevealed;
    sf::RectangleShape squareBomb;
    sf::RectangleShape squareFlag;
public:
    explicit MSSFML();

    // this method presents a menu allowing the user to select (using arrows and enter) game settings such as field size
    // (2 < size < 100) and difficulty level (EASY, NORMAL, HARD) using SFML.
    // it handles user input and updates game parameters accordingly.
    void Menu(sf::RenderWindow &window);

    // this method draws the Minesweeper board on the SFML RenderWindow based on the current state
    // of the MinesweeperBoard object. It handles user input for revealing fields and toggling flags.
    void drawMSBoard(sf::RenderWindow &window, MinesweeperBoard &board);

    // this method creates an SFML RenderWindow and enters the game loop, which includes displaying
    // the menu, initializing a MinesweeperBoard, and drawing the Minesweeper board until the window is closed.
    void play();
};

#endif //MINESWEEPER_MSSFML_H
