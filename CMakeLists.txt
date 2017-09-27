cmake_minimum_required(VERSION 3.7)
project(lem_in)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES

        main.c
        includes/lem-in.h checkers.c serve.c algo.c)

add_executable(lem_in ${SOURCE_FILES})

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)