/* Test cpp file for alib.hpp */

#include "rang.hpp"
#include "alib.hpp"

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
#define LINUX
#elif defined(__APPLE__) || defined(__MACH__)
#define MAC
#else
#error Unknown
#endif

using namespace alib;

using std::cout;
using std::endl;
int main() {
  std::cout << "Alib\n";
  clrscr();
  showLoadingScreen("Starting");
  std::cout << std::endl;

  showLoadingScreen("Loading", 4, true);
  std::cout << std::endl;

#if defined LINUX || MAC
  decorateMe("ALib");
  decorateMe("ALib", 2);
  decorateMe("ALib", 3, "+");
  decorateMe("ALib", 3, "+", true);
  decorateMe("ALib", 3, "+", false);
  // std::cout << (consoleWidth());
  std::cout << std::endl;
  // std::cout << (terminalWidth());
  std::cout << std::endl;

  countdown(3, 1, true, false);
  showLoadingScreen("Starting");
  std::cout << std::endl;

  showLoadingScreen("Loading", 4, true);
  std::cout << std::endl;

  // horizontalLine(2, "purple");
  #endif
}
