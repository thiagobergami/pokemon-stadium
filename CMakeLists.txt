cmake_minimum_required(VERSION 3.5)
project(PokemonStadium)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(pokemon_stadium ${SOURCES})