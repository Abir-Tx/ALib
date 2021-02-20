/* Test cpp file for alib.hpp */

#include "alib.hpp"
#include "rang.hpp"

using namespace alib;
int main() {
  std::cout << "Alib";
  clrscr();
  decorateMe("ALib");
  decorateMe("ALib", 2);
  decorateMe("ALib", 3, "+");
  decorateMe("ALib", 3, "+", true);
  decorateMe("ALib", 3, "+", false);

  std::cout << (consoleWidth());
  std::cout << std::endl;
  std::cout << (terminalWidth());
  std::cout << std::endl;

  std::cout << (consoleHeight());
}
