cmake_minimum_required(VERSION 3.21)
project(library C)

set(CMAKE_C_STANDARD 99)

include_directories(book_management.h user.h interface.h)
add_executable(library book_management.c user.c user.h librarian.c interface.h)
