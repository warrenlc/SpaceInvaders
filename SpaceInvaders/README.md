Welcome to Space Invaders-- !

This project was developed for the course TDP005
Object Oriented Programming at Linköping University.

Our game is a simplified approach to the classic we
all know. 

The design uses the Entity/Component pattern. 
The design is based on the demonstration from our instructor 
Filip Strömbäck, adapted to our own version of Space Invaders.
In this version, the aliens move in a rectangular pattern, shooting
at regular intervals. They do not collide with the player.

*INSTALLATION*
You need to have sfml, a c++ compiler, 
and cmake already installed on your system.

Clone this repository to a folder of your choice. 
Then:
    
    $ cmake .
    $ make

To run the game:
    ./SpaceInvaders

**NOTE** Depending on your version of cmake, 
you MAY need to update the required version in the
file CMakeLists.txt

If this is you, do:
    $ nano CMakeLists.txt

    At the top, where it says: cmake_minimum_required(VERSION 3.XX)
    change <XX> to the version it said in the terminal error message.

GAMEPLAY:
    
    After launching the game, the player is controlled with arrow keys
    to move right or left. Player shoots with space bar.
    Press Q to pause the game, change level, or exit the game.

    A player has 10 lives.
    The "Boss" has 10 lives.
    Aliens have 5 lives.

Enjoy!





