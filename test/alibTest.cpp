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
  horizontalLine(1,"red");

#if defined LINUX || MAC
  std::cout << "Console Width is (using consoleWidth Funtion): " <<(consoleWidth());
  std::cout << std::endl;
  std::cout << "Console Width is (Using terminalWidth): "<<(terminalWidth());
  std::cout<<std::endl;
  decorateMe("ALib", 3, "+", true);
  decorateMe("ALib", 3, "+", false);
  std::cout<<std::endl;
  horizontalLine(2, "purple");
  horizontalLine(2,"red");
  #endif
}
