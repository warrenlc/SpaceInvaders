cmake_minimum_required(VERSION 3.22)
project(SpaceInvaders)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra")

set(SOURCE_FILES
    Alien.cpp
    Alien.h
    Boss.cpp
    Boss.h
    Collides.cpp
    Collides.h
    Component.cpp
    Component.h
    End_State.cpp
    End_State.h
    Entity.cpp
    Entity.h
    Game_State.cpp
    Game_State.h
    Global_Values.h
    Lives.cpp
    Lives.h
    main.cpp
    Menu_State.cpp
    Menu_State.h
    Missile.cpp
    Missile.h
    Movable.cpp
    Movable.h
    Player.cpp
    Player.h
    Random.cpp
    Random.h
    Shooting.cpp
    Shooting.h
    State.cpp
    State.h
    Static_Entity.cpp
    Static_Entity.h
    Statistics.cpp
    Statistics.h
    Texture_Manager.cpp
    Texture_Manager.h
    Textured.cpp
    Textured.h
    World.cpp
    World.h)

if ( DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/6.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc -6.1.0/ bin/g++)
    if (DEFINED ENV{SFML_ROOT})
        list( APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif ()
endif ()
# Välj vilka moduler i SFML som ska användas .
set(SFML_MODULES network graphics window system)
# Försök att hitta SFML genom att anropa 'FindSFML .cmake ' (om det finns ).
find_package (SFML 2 COMPONENTS ${SFML_MODULES})
include_directories (${SFML_INCLUDE_DIR})
# Om det inte finns hoppas vi på att SFML finns installerat ändå.
if (NOT (${SFML_FOUND} STREQUAL "TRUE "))
    set( SFML_LIBRARIES "")
    foreach (i ${SFML_MODULES})
        list(APPEND SFML_LIBRARIES "sfml-${i}")
    endforeach (i)
endif ()

set(SFML_MODULES network graphics window system)

foreach(i ${SFML_MODULES})
    list(APPEND SFML_LIBRARIES "sfml-${i}")
endforeach(i)




add_executable(SpaceInvaders ${SOURCE_FILES})

target_link_libraries(SpaceInvaders ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

