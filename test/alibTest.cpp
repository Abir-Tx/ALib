/* Test cpp file for alib.hpp */

#include "rang.hpp"
#include "alib.hpp"

using namespace alib;

using std::cout;
using std::endl;
int main() {
  std::cout << "Alib\n";
  clrscr();
  /*   decorateMe("ALib");
    decorateMe("ALib", 2);
    decorateMe("ALib", 3, "+");
    decorateMe("ALib", 3, "+", true);
    decorateMe("ALib", 3, "+", false);

    std::cout << (consoleWidth());
    std::cout << std::endl;
    std::cout << (terminalWidth());
    std::cout << std::endl;

    std::cout << (consoleHeight());

  countdown(3, 1, true, false);
  showLoadingScreen();
  */

  countdown(1);
  countdown(3,true);
  countdown(5,1,true,true);
}
