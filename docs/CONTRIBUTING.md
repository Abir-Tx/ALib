# Contributing to ALib
Contributions are most welcomed to this project as any beginner level C++ programmer can contribute here. So I will be much happy if anyone contribute to this project.

There are a few rules and code conventions to follow to contribute for this project. By reading this documentation you will have a solid understanding of how to contribute to this project & also you will be able to maintain the source code so that everyone else can easily contribute and read your code changes easily.


# Some point to know before contributing

- **ALib** is a header only library. The main header file is named ```alib.hpp``` which is present in the ```include/alib``` folder. 
- **ALib** is function based library. So every feature you plan to add to the ```alib.hpp``` should be a function.
- You can create ***overloaded functions*** so that user can use the function with much more options
- Try adding ***functions*** which are not present in the C++ **STD** or **Built in** libraries.
- All the functions present in the ```alib.hpp``` are inside the ```alib``` **namespace**. You can create more nested **namespaces** if your functions need. Don't create unnecessary namespaces.
- You need to remember that **ALib** is ***cross-platform***. So the functions you add & libraries you use should work with all the major OS (Operating System) i.e **Windows, Linux, Mac OS**. Try adding support for both Windows and Linux at least.
- Before adding any function try to add clear **comments** which will describe your function works/dependecies/what your function can or can not. Commenting is important


# How do I contribute & submit my changes?

## Contributing Steps

- First **Fork** this repository from the Fork buttom of this repo's homepage (Fork button present on top right corner)
- Then clone the forked repo on your machine & create a new **branch** and then begin to add your idea's & awesome codes. When you are finished adding your codes then **save** the file.
- **commit** your changes with ***clear short commit message*** using ```git commit -m```
    ```bash
    git commit -m "you changes & commit message here"
    ```
- After commiting your changes it is time to **push** the chnages to github. use ```git push``` to push your new changes to github.

## Submitting Chnages

- When you are all done adding your changes an pushing them , open github in your browser and go to your forked ALib repo. You will see a **create pull request** button there.
- Create a pull request with a nice description of what you have done/added so that others can easily understand how much important your changes are. 
- After you have created the pull request, I will be able see the pull request and will be able to add those changes after reviewing.


If you are new to contributing to github project you can [read this](https://gist.github.com/MarcDiethelm/7303312#file-contributing-md) for further understanding. Also you can contact me directly using my email address - abirtx@yandex.com

# Code Conventions

It is very important to keep all the source code the same for all so that it is easier to read & is also convinent. So to achieve this the **ALib** project uses a ```.clang-format``` file which helps to format the code. 

You can use this file with clang format just before creating a pull request so it will be easier to review too.

# Thank You
Thanks a lot from Abir-Tx for your valuable contributions :-)