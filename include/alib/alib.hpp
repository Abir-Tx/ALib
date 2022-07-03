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
#include <unistd.h>
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

// A method for countdown from a given number to 0
void countdown(unsigned int starting_number) {
  for (unsigned int i = starting_number; i <= starting_number; i--) {
    std::cout << rang::style::bold << i << rang::style::reset << std::endl;
  }
}

void countdown(unsigned int starting_number, bool transition) {
  if (transition) {
    for (unsigned int i = starting_number; i <= starting_number; i--) {
      std::cout << rang::style::bold << i << rang::style::reset << std::endl;
      sleep(1);
    }
  } else {
    countdown(starting_number);
  }
}
void countdown(unsigned int starting_number, unsigned int ending_number,
               bool transition) {
  if (transition) {
    for (unsigned int i = starting_number; i >= ending_number; i--) {
      std::cout << rang::style::bold << i << rang::style::reset << std::endl;
      sleep(1);
    }
  } else {
    countdown(starting_number);
  }
}

void countdown(unsigned int starting_number, unsigned int ending_number,
               bool transition, bool isInline) {
  if (transition) {
    if (isInline) {
      /* For an unknown reason the transition/sleep is not working as expected.
      Instead of showing one by one it is showing all the numbers at once */

      for (unsigned int i = starting_number; i >= ending_number; i--) {
        std::cout << rang::style::bold << i << rang::style::reset << " ";
        // std::cout << " ";
        sleep(1);
      }
    } else {
      for (unsigned int i = starting_number; i >= ending_number; i--) {
        std::cout << rang::style::bold << i << rang::style::reset << std::endl;
        sleep(1);
      }
    }
  } else {
    if (isInline) {
      for (unsigned int i = starting_number; i >= ending_number; i--) {
        std::cout << rang::style::bold << i << rang::style::reset << " ";
      }
    } else {
      countdown(starting_number);
    }
  }
}

// Shows a loading screen (fake) to give user feedback for something working in
// bg
void showLoadingScreen(unsigned short int count = 3) {
  for (unsigned int i = 0; i < count; i++) {
    sleep(1);
    std::cout << ". " << std::flush;
  }
}

/* Overloaded function of showloadingScreen with added paramater. if no
 * parameters are paased then the default values will be used */
void showLoadingScreen(std::string loadingText, unsigned short int count = 3,
                       bool enableBothSide = false) {
  if (!enableBothSide) {
  RightSideLoading:
    std::cout << rang::style::bold << loadingText << " " << rang::style::reset;
    showLoadingScreen(count);
  } else {
    showLoadingScreen(count); /* For left side loading */
    goto RightSideLoading;
  }
}

// Prints a full screen horizontal line dynamically on runtime depending on the
// terminal size with optional colors

// The Colors enum class used to specify colors while passing arguments to the
// function This is also usefull to handle errors.
enum class Colors { White = 1, Red, Blue, Green };

void horizontalLine(unsigned short int count = 1,
                    Colors barColor = Colors::White) {
  using namespace rang;

// Macro for setting the bar color
#define SETBARCOLOR std::cout << fg::

  bool runBar = true;

  if (barColor == Colors::White) {
    SETBARCOLOR reset;
  } else if (barColor == Colors::Red)
    SETBARCOLOR red;
  else if (barColor == Colors::Blue)
    SETBARCOLOR blue;
  else if (barColor == Colors::Green)
    SETBARCOLOR green;
  else {
    /* TODO: Remove this error message as it is not needed or will not be
    executed anymore because of usage of the enum class */
    runBar = false;
    std::cerr << "The specified "
              << " Bar Color is not supported. Supported "
                 "colors are -> white, red, blue, green";
  }

  if (runBar) {
    for (unsigned short int i = 0; i < count; i++) {
      for (int i = 0; i < consoleWidth(); i++) { std::cout << "_"; }
    }
  } else {
    std::cerr << "The specified "
              << " Bar Color is not supported. Supported "
                 "colors are -> white, red, blue, green";
  }

  // Reset the standart output stream to avoid showing colors for other streams
  SETBARCOLOR reset;

#undef SETBARCOLOR
}

/*
The function prints vertical line to the left side of the console. By default
the minimum amount of lines (|) are 7 and this can be increased by passing the
count parameter. If count is 1 then only 7 lines will be printed if count is 2
then (7*2)14 lines will be printed & so on.

The function also accepts a string param which is responsible to be printed on
the mid point of all the lines. This is done by dividing the totalLine by 2
which gives the middle number of all the printed lines. If the totalLine equals
to an even number then we add one more line to make it odd & display the text in
perfect middle
*/
void verticalLine(unsigned short int count = 1,
                  std::string middlePointDisplayText = "",
                  bool isCenter = false) {
#define DEFAULT_MIN_LINES 7
  unsigned short int totalLine = DEFAULT_MIN_LINES * count;
  unsigned short int midPoint = totalLine / 2;

  if (isCenter) {
    int charSize = middlePointDisplayText.capacity();

    // Getting the terminal center value & starting point of the decorations
    unsigned int termCenter = consoleWidth() / 2;
    int startingPoint = termCenter - (charSize / 2);
    int textToDecor_StartingPoint = startingPoint + ((charSize * 2) - charSize);

    if (totalLine % 2 == 0) totalLine += 1;
    for (int i = 1; i < totalLine; i++) {
      std::cout << "|" << std::endl;
      if (i == midPoint) {
        std::cout << "| " << std::setw(textToDecor_StartingPoint)
                  << std::setfill(' ') << middlePointDisplayText << std::endl;
        continue;
      }
    }
  } else {
    if (totalLine % 2 == 0) totalLine += 1;
    for (int i = 1; i < totalLine; i++) {
      std::cout << "|" << std::endl;
      if (i == midPoint) {
        std::cout << "| " << middlePointDisplayText << std::endl;
        continue;
      }
    }
  }
#undef DEFAULT_MIN_LINES
}

}  // end of namespace alib

// Undefining different platforms
#undef LINUX
#undef WINDOWS
#undef MAC

#endif  // ALIB_DOT_HPP
