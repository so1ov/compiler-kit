cmake_minimum_required(VERSION 3.12)
project(shunting_yard)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        include/ExpressionParser.hpp src/ExpressionParser.cpp
        include/Lexeme.hpp src/Lexeme.cpp
        include/LexemeType.hpp)

add_library(ExpressionParser ${SOURCES})
target_include_directories(ExpressionParser PUBLIC include)

add_executable(shunting_yard test.cpp)
target_link_libraries(shunting_yard ExpressionParser)
