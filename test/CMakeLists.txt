cmake_minimum_required(VERSION 3.15)

project(Test)

include_directories(../src)
include_directories(../include)

set(SRC
    ../src/SimpleLogger.cpp
)
set(INCL
    ../include/SimpleLogger.h
)
set(TEST
    main.cpp
)

add_executable(Test
    ${SRC} ${INCL} ${TEST}
) 