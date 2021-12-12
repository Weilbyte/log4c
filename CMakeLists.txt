cmake_minimum_required(VERSION 3.13)
project(log4c)

add_library(log4c log4c/main.c log4c/log4c.h)
add_executable(example_log4c log4c.Example/main.c)

target_link_libraries(example_log4c PUBLIC log4c)
target_include_directories(example_log4c PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/log4c"
                          )