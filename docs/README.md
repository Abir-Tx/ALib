<h1 align="center">ALib</h1>


[![Windows & Linux Build](https://github.com/Abir-Tx/ALib/actions/workflows/build_test.yml/badge.svg)](https://github.com/Abir-Tx/ALib/actions/workflows/build_test.yml) [![CodeFactor](https://www.codefactor.io/repository/github/abir-tx/alib/badge)](https://www.codefactor.io/repository/github/abir-tx/alib) [![CodeQL](https://github.com/Abir-Tx/ALib/actions/workflows/codeql.yml/badge.svg)](https://github.com/Abir-Tx/ALib/actions/workflows/codeql.yml) ![AUR version](https://img.shields.io/aur/version/alib?logo=archlinux)


Modern cross platform C++ header only library which features many useful utility functions which can be used in your personal project.
ALib provides many usefull functions which are not available in the **built in** or **standard** C++ library like decorating a text.

The motivation of this project is to get rid of writing most/frequently needed functions/codes again & again for different project. Which is tedious & not the progrmmatic way of doing things. Also this library packs some decorating functions.

# Features

- Cross Platform - The same function works on Windows, Linux and Mac OS
- Extremely extensible - The **ALib** is very modular as it is function based. So you can easily change or add features to a function as you need by modifying the source code.
- Supports colored decorations - ALib uses a 3rd Party library called **rang** to produce colored text output.


# Provided Functions:
 ```- decorateMe
 - clrscr
 - consoleWidth/terminalWidth
 - consoleHeight/terminalHeight
 - countdown
 - showLoadingScreen
 - horizontalLine
 - verticalLine
```

# Installation

## Linux
Download the `alib.hpp` from the **[Releases](https://github.com/Abir-Tx/ALib/releases)** section & copy it to the `/usr/include` folder & that's it
### Arch Linux
Arch users can install the library from [AUR](https://aur.archlinux.org/packages/alib) easily using `yay`
```bash
yay -S alib
```

# Contributing 
Contributions are always welcomed to this project. Contributing to this project is very easy and needed too. Any beginner level C++ programmer can contribute to this project. Any bug report or bug fix or addition of new features to this library will be very helpful.

You can learn more about contributin to this project by reading [this](CONTRIBUTING.md) documentation

## Submit Issues
If you face any issue or want to submit new ideas to be implemented in **ALib** please open a new issue by clicking [here](https://github.com/Abir-Tx/ALib/issues/new)

# Note For Developers
It is recommended to use the `dev` branch while doing developement works and then make a pull request


