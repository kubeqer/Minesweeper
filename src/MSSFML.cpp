#include <SFML/Window/Event.hpp>
#include "MSSFML.h"

MSSFML::MSSFML() {
    if (!font.loadFromFile(
            "fonts/Arialn.ttf")) {
        std::cerr << "ERROR NO FONT FOUND" << std::endl;
    }
    howManyFields = 5;
    windowsizeWidth = 800;
    windowsizeHeight = windowsizeWidth + 100; //100 is for text only

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    squareUnrevealed.setFillColor(sf::Color::Blue);
    squareUnrevealed.setOutlineThickness(2.f);
    squareUnrevealed.setOutlineColor(sf::Color::Black);

    squareRevealed.setFillColor(sf::Color::Green);
    squareRevealed.setOutlineThickness(2.f);
    squareRevealed.setOutlineColor(sf::Color::Black);

    squareBomb.setFillColor(sf::Color::Red);
    squareBomb.setOutlineThickness(2.f);
    squareBomb.setOutlineColor(sf::Color::Black);

    squareFlag.setFillColor(sf::Color::Yellow);
    squareFlag.setOutlineThickness(2.f);
    squareFlag.setOutlineColor(sf::Color::Black);
}

void MSSFML::Menu(sf::RenderWindow &window) {
    sf::Event evnt;
    unsigned int menuSelection = 0;
    int xPos = windowsizeWidth / 3;
    int yPos = windowsizeHeight / 5;
    int gap = 100;
    bool isPressed = false;
    bool isEnterPressed = false;
    while (!isEnterPressed) {
        window.clear();
        sf::Text menuTitle;
        menuTitle.setFont(font);
        menuTitle.setCharacterSize(48);
        menuTitle.setPosition(xPos, yPos);
        menuTitle.setString("    Minesweeper    ");
        window.draw(menuTitle);

        sf::Text startGameOption;
        startGameOption.setFont(font);
        startGameOption.setCharacterSize(24);
        startGameOption.setPosition(xPos, yPos + gap);
        startGameOption.setString("Start Game");
        if (menuSelection % 2 == 0) {
            startGameOption.setFillColor(sf::Color::Red);
        }

        sf::Text exitOption;
        exitOption.setFont(font);
        exitOption.setCharacterSize(24);
        exitOption.setPosition(xPos, yPos + gap * 2);
        exitOption.setString("Exit");
        if (menuSelection % 2 == 1) {
            exitOption.setFillColor(sf::Color::Red);
        }
        window.draw(exitOption);
        window.draw(startGameOption);
        window.pollEvent(evnt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isPressed) {
            menuSelection++;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isPressed) {
            menuSelection--;
        }
        if (evnt.type == sf::Event::KeyPressed) {
            isPressed = true;

            if (evnt.key.code == sf::Keyboard::Enter) {
                isEnterPressed = true;
            }
        } else if (evnt.type == sf::Event::KeyReleased) {
            isPressed = false;
        }

        window.display();
    }
    if (menuSelection % 2 == 1) {
        window.close();
    } else {
        while (isEnterPressed) {
            window.pollEvent(evnt);
            if (evnt.type == sf::Event::KeyPressed) {
                isPressed = true;

                if (evnt.key.code == sf::Keyboard::Enter) {
                    isEnterPressed = true;
                }
            } else if (evnt.type == sf::Event::KeyReleased) {
                isPressed = false;
                isEnterPressed = false;
            }
        }

        while (!isEnterPressed) {
            window.pollEvent(evnt);
            if (evnt.type == sf::Event::KeyPressed) {
                isPressed = true;

                if (evnt.key.code == sf::Keyboard::Enter) {
                    isEnterPressed = true;
                }
            } else if (evnt.type == sf::Event::KeyReleased) {
                isPressed = false;
            }

            window.clear();

            sf::Text HowManyFields;
            HowManyFields.setFont(font);
            HowManyFields.setCharacterSize(24);
            HowManyFields.setPosition(0, 0);
            HowManyFields.setString("How many fields do you want to have in one line? (The field will be square)");

            sf::Text number;
            number.setFont(font);
            number.setCharacterSize(24);
            number.setPosition(xPos + gap, yPos + gap * 2);
            number.setString(std::to_string(howManyFields));
            window.draw(HowManyFields);
            window.draw(number);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) & !isPressed) {
                if (howManyFields < 100)
                    howManyFields++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) & !isPressed) {
                if (howManyFields > 2)
                    howManyFields--;
            }
            window.display();
        }
        while (isEnterPressed) {
            window.pollEvent(evnt);
            if (evnt.type == sf::Event::KeyPressed) {
                isPressed = true;

                if (evnt.key.code == sf::Keyboard::Enter) {
                    isEnterPressed = true;
                }
            } else if (evnt.type == sf::Event::KeyReleased) {
                isPressed = false;
                isEnterPressed = false;
            }
        }
        menuSelection = 0;
        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            window.clear();
            sf::Text easyMode;
            easyMode.setFont(font);
            easyMode.setCharacterSize(24);
            easyMode.setPosition(xPos, yPos + gap);
            easyMode.setString("EASY MODE");

            sf::Text normalMode;
            normalMode.setFont(font);
            normalMode.setCharacterSize(24);
            normalMode.setPosition(xPos, yPos + gap * 2);
            normalMode.setString("NORMAL MODE");

            sf::Text hardMode;
            hardMode.setFont(font);
            hardMode.setCharacterSize(24);
            hardMode.setPosition(xPos, yPos + gap * 3);
            hardMode.setString("HARD MODE");


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isPressed) {
                menuSelection--;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) & !isPressed) {
                menuSelection++;
            }
            if (menuSelection % 3 == 0) {
                easyMode.setFillColor(sf::Color::Red);
            } else if (menuSelection % 3 == 1) {
                normalMode.setFillColor(sf::Color::Red);
            } else if (menuSelection % 3 == 2) {
                hardMode.setFillColor(sf::Color::Red);
            }

            window.pollEvent(evnt);
            if (evnt.type == sf::Event::KeyPressed) {
                isPressed = true;

                if (evnt.key.code == sf::Keyboard::Enter) {
                    isEnterPressed = true;
                }
            } else if (evnt.type == sf::Event::KeyReleased) {
                isPressed = false;
                isEnterPressed = false;
            }


            window.draw(easyMode);
            window.draw(normalMode);
            window.draw(hardMode);
            window.display();
        }
        if (menuSelection % 3 == 0)
            gamemode = EASY;
        else if (menuSelection % 3 == 1)
            gamemode = NORMAL;
        else if (menuSelection % 3 == 2)
            gamemode = HARD;
    }
}

void MSSFML::drawMSBoard(sf::RenderWindow &window, MinesweeperBoard &board) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int row = static_cast<int>(event.mouseButton.y / square_length);
                    int col = static_cast<int>(event.mouseButton.x / square_length);
                    board.revealField(row, col);
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    int row = static_cast<int>(event.mouseButton.y / square_length);
                    int col = static_cast<int>(event.mouseButton.x / square_length);
                    board.toggleFlag(row, col);
                }
            }
        }

        window.clear();

        square_length = floor(windowsizeWidth / howManyFields);
        squareUnrevealed.setSize(sf::Vector2f(square_length, square_length));
        squareRevealed.setSize(sf::Vector2f(square_length, square_length));
        squareBomb.setSize(sf::Vector2f(square_length, square_length));
        squareFlag.setSize(sf::Vector2f(square_length, square_length));

        for (auto row = 0; row < board.getBoardHeight(); ++row) {
            for (auto col = 0; col < board.getBoardWidth(); ++col) {
                unsigned int xPos = col * square_length;
                unsigned int yPos = row * square_length;

                if (board.getFieldInfo(row, col) == "_") {
                    squareUnrevealed.setPosition(xPos, yPos);
                    window.draw(squareUnrevealed);
                } else if (board.getFieldInfo(row, col) == "x") {
                    squareBomb.setPosition(xPos, yPos);
                    window.draw(squareBomb);
                } else if (board.isRevealed(row, col)) {
                    squareRevealed.setPosition(xPos, yPos);
                    window.draw(squareRevealed);

                    text.setFillColor(sf::Color::Red);
                    text.setString(board.getFieldInfo(row, col));
                    text.setPosition(xPos + square_length / 2, yPos + square_length / 2);
                    window.draw(text);
                } else if (board.getFieldInfo(row, col) == "F") {
                    squareFlag.setPosition(xPos, yPos);
                    window.draw(squareFlag);
                }
            }
        }
        text.setFillColor(sf::Color::White);
        text.setString("YOU HAVE " + std::to_string(board.getMineCount()) + " BOMBS");
        text.setPosition(0, windowsizeHeight - 100);
        window.draw(text);
        if (board.getGameState() == RUNNING) {
            text.setString("GAME STATE: RUNNING");
            text.setPosition(windowsizeWidth / 1.75, windowsizeHeight - 100);
            window.draw(text);
        } else if (board.getGameState() == FINISHED_LOSS) {
            text.setString("GAME STATE: LOST");
            text.setPosition(windowsizeWidth / 1.75, windowsizeHeight - 100);
            window.draw(text);
            text.setString("CLICK SPACE TO LEAVE");
            text.setPosition(0, windowsizeHeight - 50);
            window.draw(text);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                break;
        } else if (board.getGameState() == FINISHED_WIN) {
            text.setString("GAME STATE: WIN");
            text.setPosition(windowsizeWidth / 1.75, windowsizeHeight - 100);
            window.draw(text);
            text.setString("CLICK SPACE TO LEAVE");
            text.setPosition(0, windowsizeHeight - 50);
            window.draw(text);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                break;
        }
        window.display();
    }
}

void MSSFML::play() {
    sf::RenderWindow window(sf::VideoMode(windowsizeWidth, windowsizeHeight), "Minesweeper", sf::Style::Close);
    while (window.isOpen()) {
        sf::Event evnt;
        Menu(window);
        MinesweeperBoard minesweeperBoard(howManyFields, howManyFields, gamemode);
        drawMSBoard(window, minesweeperBoard);
    }
    return;
}