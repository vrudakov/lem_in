cmake_minimum_required(VERSION 3.8)
project(vrudakov_lemin)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        includes/lem_in.h
        src/algo.c
        src/ant.c
        src/checkers.c
        src/main.c
        src/path.c
        src/path_processor.c
        src/serve.c
        src/sort.c
        src/way.c src/free_func.c)

add_executable(vrudakov_lemin ${SOURCE_FILES})
target_link_libraries(vrudakov_lemin ${CMAKE_SOURCE_DIR}/libft/libft.a)