/* 
alib is a header only library which offers many usefull and frequently used C++ functions which are not present in standard c++ library.
The library is under GPL3 license and is open for others to contribute to this project. This library supports multi platform. It works on both
windows and Linux operating system. 

The project is inspired from the rang project.

The project is maintained by Mushfiqur Rahman Abir aka Abir-Tx.


Current Version:    v1.0
Maintainer:         Mushfiqur Rahman Abir
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
#include <unistd.h>
#elif defined(WINDOWS)
#include <windows.h>
#endif

// Including platform independent files
#include "rang.hpp"
#include <iostream>
#include <vector>

// Functions
namespace alib
{
    // Function for dynamically decorating a text
    void decorateMe(std::string textToDecor)
    {
        using namespace rang;

        int charSize = textToDecor.capacity();
        std::cout << std::endl;
        std::cout << fg::red;
        for (int i = 0; i < (charSize * 2); i++)
        {
            std::cout << "_";
        }
        std::cout << fg::reset;
        std::cout << std::endl;

        std::cout << fg::blue << style::bold << textToDecor << style::reset << fg::reset;

        std::cout << std::endl;
        std::cout << fg::red;
        for (int i = 0; i < (charSize * 2); i++)
        {
            std::cout << "_";
        }
        std::cout << fg::reset;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void decorateMe(std::string textToDecor, unsigned short int lineBreaksNumber)
    {
        using namespace rang;

        int charSize = textToDecor.capacity();
        std::cout << std::endl;
        std::cout << fg::red;
        for (int i = 0; i < (charSize * 2); i++)
        {
            std::cout << "_";
        }
        std::cout << fg::reset;
        for (int i = 1; i <= lineBreaksNumber; i++)
        {
            std::cout << std::endl;
        }
        std::cout << fg::blue << style::bold << textToDecor << style::reset << fg::reset;

        for (int i = 1; i <= lineBreaksNumber; i++)
        {
            std::cout << std::endl;
        }
        std::cout << fg::red;
        for (int i = 0; i < (charSize * 2); i++)
        {
            std::cout << "_";
        }
        std::cout << fg::reset;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void decorateMe(std::string textToDecor, unsigned short int lineBreaksNumber, std::string decorator)
    {
        using namespace rang;

        int charSize = textToDecor.capacity();
        std::cout << std::endl;
        std::cout << fg::red;
        for (int i = 0; i < (charSize * 2); i++)
        {
            std::cout << decorator;
        }
        std::cout << fg::reset;
        for (int i = 1; i <= lineBreaksNumber; i++)
        {
            std::cout << std::endl;
        }
        std::cout << fg::blue << style::bold << textToDecor << style::reset << fg::reset;

        for (int i = 1; i <= lineBreaksNumber; i++)
        {
            std::cout << std::endl;
        }
        std::cout << fg::red;
        for (int i = 0; i < (charSize * 2); i++)
        {
            std::cout << decorator;
        }
        std::cout << fg::reset;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    /* Clears the screen depending on OS */
    void clrscr()
    {
        #if defined(LINUX) || defined(MAC)
        system("clear");
        #elif defined(WINDOWS)
        system("cls");
        #endif
    }

    void setConsoleTitle(std::string consoleTitle)
    {

        #if defined(LINUX) || defined(MAC)
        system(+consoleTitle.c_str());
        #elif defined(WINDOWS)
        std::cout<<"Hello windows";
        #endif
    }
    #define consoleTitle setConsoleTitle
} // end of namespace alib

// Undefining different platforms
#undef LINUX
#undef WINDOWS
#undef MAC

#endif // ALIB_DOT_HPP