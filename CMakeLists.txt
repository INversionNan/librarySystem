cmake_minimum_required(VERSION 3.21)
project(library C)

set(CMAKE_C_STANDARD 99)

include_directories(book_management.h)
add_executable(library book_management.c user.c interface.c librarian.c password.c)
