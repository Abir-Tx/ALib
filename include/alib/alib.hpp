/*
alib is a header only library which offers many usefull and frequently used C++
functions which are not present in standard c++ library. The library is under
GPL3 license and is open for others to contribute to this project. This library
supports multi platform. It works on both windows and Linux operating system.

The project is inspired from the rang project.

The project is maintained by Mushfiqur Rahman Abir aka Abir-Tx.


Current Version:    v1.0
Maintainer:         Mushfiqur Rahman Abir
Developer Profile   https://www.github.com/Abir-Tx
*/

#if !defined(ALIB_DOT_HPP)
#define ALIB_DOT_HPP

// Defining the different platforms
#if defined(__unix__) || defined(__unix) || defined(__linux__)
#define LINUX
#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
#define MAC
#else
#error Unknown
#endif

// Including platform specific files
#if defined(LINUX) || defined(MAC)
#include <sys/ioctl.h> /* For getting terminal height and width. See consoleWidth() & consoleHeight() */
#include <unistd.h>
#elif defined(WINDOWS)
#include <windows.h>
#endif

// Including platform independent files
#include <iomanip>
#include <iostream>
#include <vector>

#include "rang.hpp" /* A third party library for console text styling and coloring */

// Functions
namespace alib {
// Function for dynamically decorating a text
void decorateMe(std::string textToDecor) {
  using namespace rang;

  int charSize = textToDecor.capacity();
  std::cout << std::endl;
  std::cout << fg::red;
  for (int i = 0; i < (charSize * 2); i++) { std::cout << "_"; }
  std::cout << fg::reset;
  std::cout << std::endl;

  std::cout << fg::blue << style::bold << textToDecor << style::reset
            << fg::reset;

  std::cout << std::endl;
  std::cout << fg::red;
  for (int i = 0; i < (charSize * 2); i++) { std::cout << "_"; }
  std::cout << fg::reset;
  std::cout << std::endl;
  std::cout << std::endl;
}

void decorateMe(std::string textToDecor, unsigned short int lineBreaksNumber) {
  using namespace rang;

  int charSize = textToDecor.capacity();
  std::cout << std::endl;
  std::cout << fg::red;
  for (int i = 0; i < (charSize * 2); i++) { std::cout << "_"; }
  std::cout << fg::reset;
  for (int i = 1; i <= lineBreaksNumber; i++) { std::cout << std::endl; }
  std::cout << fg::blue << style::bold << textToDecor << style::reset
            << fg::reset;

  for (int i = 1; i <= lineBreaksNumber; i++) { std::cout << std::endl; }
  std::cout << fg::red;
  for (int i = 0; i < (charSize * 2); i++) { std::cout << "_"; }
  std::cout << fg::reset;
  std::cout << std::endl;
  std::cout << std::endl;
}

void decorateMe(std::string textToDecor, unsigned short int lineBreaksNumber,
                std::string decorator) {
  using namespace rang;

  int charSize = textToDecor.capacity();
  std::cout << std::endl;
  std::cout << fg::red;
  for (int i = 0; i < (charSize * 2); i++) { std::cout << decorator; }
  std::cout << fg::reset;
  for (int i = 1; i <= lineBreaksNumber; i++) { std::cout << std::endl; }
  std::cout << fg::blue << style::bold << textToDecor << style::reset
            << fg::reset;

  for (int i = 1; i <= lineBreaksNumber; i++) { std::cout << std::endl; }
  std::cout << fg::red;
  for (int i = 0; i < (charSize * 2); i++) { std::cout << decorator; }
  std::cout << fg::reset;
  std::cout << std::endl;
  std::cout << std::endl;
}

/* Clears the screen depending on OS */
void clrscr() {
#if defined(LINUX) || defined(MAC)
  system("clear");
#elif defined(WINDOWS)
  system("cls");
#endif
}

// Return the console's width and height respectively
unsigned int consoleWidth() {
#if defined(LINUX) || defined(MAC)
  winsize conSize;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &conSize);
  return conSize.ws_col;
#elif defined(WINDOWS)
  int width;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  width = (int)(csbi.dwSize.X);
  return width;
#endif
}

unsigned int consoleHeight()

{
#if defined(LINUX) || defined(MAC)
  winsize conSize;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &conSize);
  return conSize.ws_row;
#elif defined(WINDOWS)
  int height;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  height = (int)(csbi.dwSize.Y);
  return height;
#endif
}
// Alias for the consoleWidth & consoleHeight funcs
#define terminalWidth consoleWidth
#define terminalHeight consoleHeight

// Another overload of decorateMe function with print to center ability
void decorateMe(std::string textToDecor, unsigned short int lineBreaksNumber,
                std::string decorator, bool isCenter) {
  if (isCenter) {
    using namespace rang;

    int charSize = textToDecor.capacity();

    // Getting the terminal center value & starting point of the decorations
    unsigned int termCenter = consoleWidth() / 2;
    int startingPoint = termCenter - (charSize / 2);
    int textToDecor_StartingPoint = startingPoint + ((charSize * 2) - charSize);

    std::cout << std::endl;
    std::cout << fg::red;
    std::cout << std::setw(startingPoint) << std::setfill(' ');
    for (int i = 0; i < (charSize * 2); i++) { std::cout << decorator; }
    std::cout << fg::reset;
    for (int i = 1; i <= lineBreaksNumber; i++) { std::cout << std::endl; }
    std::cout << fg::blue << style::bold << std::setw(textToDecor_StartingPoint)
              << std::setfill(' ') << textToDecor << style::reset << fg::reset;

    for (int i = 1; i <= lineBreaksNumber; i++) { std::cout << std::endl; }
    std::cout << fg::red;
    std::cout << std::setw(startingPoint) << std::setfill(' ');
    for (int i = 0; i < (charSize * 2); i++) { std::cout << decorator; }
    std::cout << fg::reset;
    std::cout << std::endl;
    std::cout << std::endl;
  } else {
    decorateMe(textToDecor, lineBreaksNumber, decorator);
  }
}

}  // end of namespace alib

// Undefining different platforms
#undef LINUX
#undef WINDOWS
#undef MAC

#endif  // ALIB_DOT_HPP
