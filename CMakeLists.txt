
cmake_minimum_required(VERSION 3.11)
project ("Minesweeper")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_compile_options(-Wall -Wextra)

if (UNIX)
  # ANTIC UBUNTU
  set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULES_PATH})

  # FOR NEW UBUNTU
  set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})

  # for MACOS or different linux type
  # set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})
endif(UNIX)

if (WIN32)
  set( SFML_STATIC_LIBRARIES TRUE )

  # WINDOW SFML DICTIONARY
  set ( SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)


find_package(SFML 2 COMPONENTS graphics audio REQUIRED)


add_executable (Minesweeper
        src/main.cpp
        src/MinesweeperBoard.h src/MinesweeperBoard.cpp
        src/MSBoardTextView.h src/MSBoardTextView.cpp
        src/MSTextController.h src/MSTextController.cpp
        src/MSSFML.cpp src/MSSFML.h)
target_link_libraries(Minesweeper sfml-graphics)