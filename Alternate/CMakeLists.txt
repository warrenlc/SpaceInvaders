cmake_minimum_required(VERSION 3.23)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled3 main.cpp State.cpp State.h Menu_State.cpp Menu_State.h Game_State.cpp Game_State.h World.cpp World.h Entity.cpp Entity.h Component.cpp Component.h Texture_Manager.cpp Texture_Manager.h Player.cpp Player.h Textured.h Textured.cpp Random.h Random.cpp Movable.h Movable.cpp Alien.h Alien.cpp Boss.h Boss.cpp Global_Values.h Shooting.cpp Shooting.h Missile.h Missile.cpp)
