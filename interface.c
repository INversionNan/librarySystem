#include<stdio.h>
#include "book_management.h"

void welcome(){
//    int libraryOpen = 1;
//    int option;
//
//    while () {
//        printf("*************************Welcome to the JJY Library.*************************\n");
//        printf("-------------------------------------\n");
//        printf("\n Main menu options(Please choose your option)\n 1 User login\n 2 Librarian login\n 3 Exit system\n Choice:");
//    }
    printf("*************************Welcome to the JJY Library.*************************\n");
}

void menu(){
    printf("Please choose an option\n");
    printf("1)Register an account\n");
    printf("2)Login\n");
    printf("3)Search for books\n");
    printf("4)Display all books\n");
    printf("5)Quit\n");
}

void stu_choice(){
    printf("Please choose an option\n");
    printf("1)Borrow a book\n");
    printf("2)Return a book\n");
    printf("3)Search for books\n");
    printf("4)Display all books\n");
    printf("5)Log out\n");
}

void li_choice(){
    printf("(logged in as librarian)\n");
    printf("Please choose an option\n");
    printf("1)Add a book\n");
    printf("2)Remove a book\n");
    printf("3)Search for books\n");
    printf("4)Display all books\n");
    printf("5)Log out\n");
}


