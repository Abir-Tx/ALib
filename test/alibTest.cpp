/* Test cpp file for alib.hpp */

#include "rang.hpp"
#include "alib.hpp"

using namespace alib;
int main()
{
    std::cout<<"Alib";
    clrscr();
    decorateMe("ALib");
    decorateMe("ALib", 2);
    decorateMe("ALib", 3, "+");
	
	std::cout<<(consoleWidth());
    std::cout<<std::endl;
	std::cout<<(terminalWidth());
    std::cout<<std::endl;
    
	std::cout<<(consoleHeight());
}
