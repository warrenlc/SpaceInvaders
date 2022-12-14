cmake_minimum_required(VERSION 3.22)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra")

set(SOURCE_FILES untitled3 main.cpp State.cpp Menu_State.cpp Game_State.cpp
        World.cpp Entity.cpp Component.cpp Texture_Manager.cpp
        Player.cpp Textured.cpp Random.cpp Movable.cpp Alien.cpp
        Boss.cpp Shooting.cpp Missile.cpp Collides.cpp Lives.cpp
        Static_Entity.cpp Statistics.cpp)
# På skolans Linux - system finns det två versioner av SFML. Se efter vilken som används :
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

add_executable(SpaceInvaders ${SOURCE_FILES})
target_link_libraries (untitled3 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
