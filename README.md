# Bowling project
Application code is available: [bowling-app](https://github.com/WojtekMs/testing/tree/master/bowling)

This repository contains a simple app which is counting points in a bowling game. This project was created in order to practice TDD methodology. 
Program loads input from a folder to which path must be given as a command-line argument. 
Optionally user can give a second argument as the name of the file where games results will be saved.
In case user doesn't know how to properly use the application, there is a manual available that is activated by passing one of the flags:
* -h
* --help

### How to build app
1. `git clone https://github.com/WojtekMs/testing`
2. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make -j`
5. `./bowling ../games`

### Technologies
* C++ Filesystem library
* TDD methodology

### Authors
* [Tomonike](https://github.com/Tomonike/)
* [Marcinati](https://github.com/Marcinati)
* [WojtekMs](https://github.com/WojtekMs/)
