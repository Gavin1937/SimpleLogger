cmake_minimum_required(VERSION 3.15)

project(Test)

set(CMAKE_CXX_STANDARD 14)

include_directories(../src)
include_directories(../include)

set(SRC
    ../src/SimpleLogger.cpp
)
set(INCL
    ../includes/SimpleLogger.h
)
set(TEST
    Test.cpp
)

add_executable(Test
    ${SRC} ${INCL} ${TEST}
) 