cmake_minimum_required(VERSION 3.15)

project(Test)

include_directories(../src)
include_directories(../include)

set(SRC
    ../src/SimpleLogger.cpp
)
set(INC
    ../include/SimpleLogger.h
)
set(TEST
    main.cpp
)

add_executable(Test
    ${SRC} ${INC} ${TEST}
) 