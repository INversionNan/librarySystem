#include<stdio.h>
#include "interface.h"

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
    printf("Please choose an option");
    printf("1)Register an account");
    printf("2)Login");
    printf("3)Search for books");
    printf("4)Display all books");
    printf("5)Quit");
}

void stu_choice(){
    printf("Please choose an option");
    printf("1)Borrow a book");
    printf("2)Return a book");
    printf("3)Search for books");
    printf("4)Display all books");
    printf("5)Log out");
}

void li_choice(){
    printf("(logged in as librarian)");
    printf("Please choose an option");
    printf("1)Add a book");
    printf("2)Remove a book");
    printf("3)Search for books");
    printf("4)Display all books");
    printf("5)Log out");
}


