cmake_minimum_required(VERSION 3.7)
project(lem_in)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES

        src/main.c
        src/checkers.c
        src/serve.c
        src/algo.c
        src/way.c
        src/sort.c
        src/path.c
        src/ant.c
        includes/lem_in.h
        )

add_executable(lem_in ${SOURCE_FILES})

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)