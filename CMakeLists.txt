cmake_minimum_required(VERSION 3.15)

project(SimpleLogger)

set(SRC
    ./src/SimpleLogger.cpp
)
set(INC
    ./include/SimpleLogger.h
)
set(TEST
    ./test/main.cpp
)

add_executable(SimpleLogger
    ${SRC} ${INC} ${TEST}
) 