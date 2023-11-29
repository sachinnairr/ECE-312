cmake_minimum_required(VERSION 3.22)
project(project7)

set(CMAKE_CXX_STANDARD 14)

add_executable(project7 main.cpp project7.cpp Customer.h CustomerDB.cpp CustomerDB.h UTString.h)
