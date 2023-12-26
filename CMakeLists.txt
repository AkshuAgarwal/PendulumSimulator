cmake_minimum_required( VERSION 3.7 )
project( pendulum )

set( pendulum_VERSION_MAJOR 1 )
set( pendulum_VERSION_MINOR 0 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

option( pendulum_SDL_VENDORED "Use vendored SDL" ON )

if( pendulum_SDL_VENDORED )
  add_subdirectory( lib/SDL EXCLUDE_FROM_ALL )
else()
  find_package( SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2-shared )
endif()

add_executable( pendulum main.cpp )

target_link_libraries( pendulum PRIVATE SDL2::SDL2 )
