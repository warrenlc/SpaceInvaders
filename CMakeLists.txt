cmake_minimum_required(VERSION 3.23)
project(space_invaders)

set(CMAKE_CXX_STANDARD 17)

add_executable(space_invaders main.cpp movement.h Game_Object.h Game_Object.cpp Building.h Building.cpp Moving_Object.h Player.h Missile.h Enemy.h Boss.h Alien.h Player.cpp Missile.cpp Moving_Object.cpp Game.h Game.cpp State.h State.cpp Menu_state.h Menu_state.cpp Game_state.h)
