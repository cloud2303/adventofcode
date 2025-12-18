cmake_minimum_required(VERSION 3.30)
project(adventofcode)

set(CMAKE_CXX_STANDARD 23)

find_package(fmt CONFIG REQUIRED)

add_executable(adventofcode
        main.cpp
)

target_link_libraries(adventofcode PRIVATE fmt::fmt)

