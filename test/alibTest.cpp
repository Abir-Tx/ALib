/* Test cpp file for alib.hpp */

#include "rang.hpp"
#include "alib.hpp"

// Platform Detection Shortcuts
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
#define LINUX
#elif defined(__APPLE__) || defined(__MACH__)
#define MAC
#else
#error Unknown
#endif

// Namespace usage
using namespace alib;
using std::cout;
using std::endl;

// Main driver function for running the tests
int main() {
  /* 
  This portion is for Windows only meaning all these function wll only be tested on windows machines only
  .Because on GitHub Windows runners some fucntions i.e  void decorateMe(std::string textToDecor, unsigned short int lineBreaksNumber,
  std::string decorator, bool isCenter) which uses/depends on the consoleWidth & consoleHeight function
  causes to execute the program infinitely which in result runs for over than 6 hours and 6 hours is the max limit for Windows
  GitHub runners. So as a resul the CI breaks with error which was a false error for the developers. So to eradicate this issue
  I have disables those functions which caused this infinite running behaviour for Windows only but kept all the tests for Linux
  cause Linux Runners doesn't have this problem on GitHub runner as of now.

  I have figured out that the console height and width of Windows Runners are very very big in github & maybe for that reason
  this strange problem is occuring


  TESTS FOR ALL (INCLUDING WINDOWS) ->
  */
  clrscr();
  std::cout << "Alib\n";
  decorateMe("ALib");
  decorateMe("ALib", 2);
  decorateMe("ALib", 3, "+");

  std::cout << std::endl;

  countdown(3, 1, true, false);
  showLoadingScreen("Starting");

  std::cout << std::endl;

  showLoadingScreen("Loading", 4, true);

  std::cout << std::endl;

  horizontalLine(1, Colors::Red);
  horizontalLine(1, alib::Colors::Blue);
  horizontalLine(1);
  horizontalLine(1,Colors::Green);

// LINUX & MAC ONLY TESTS
#if defined LINUX || MAC
  std::cout << "Console Width is (using consoleWidth Funtion): " <<(consoleWidth());
  std::cout << std::endl;
  std::cout << "Console Width is (Using terminalWidth): "<<(terminalWidth());
  std::cout<<std::endl;
  decorateMe("ALib", 3, "+", true);
  decorateMe("ALib", 3, "+", false);
  std::cout<<std::endl;
  horizontalLine(2, "purple");
  std::cout<<std::endl;
  horizontalLine(2,"red");
  #endif
}
