#include "book_management.h"
#include<stdio.h>


void welcome(){
    printf("\n*************************Welcome to the JJY Library*************************\n");
}

void menu(){
    printf("\nPlease choose an option\n\n");
    printf("1)Register an account\n");
    printf("2)Login\n");
    printf("3)Search for books\n");
    printf("4)Display all books\n");
    printf("5)Quit\n\n");
}

void user_choice(){
    printf("Please choose an option\n\n");
    printf("1)Borrow a book\n");
    printf("2)Return a book\n");
    printf("3)Search for books\n");
    printf("4)Display all books\n");
    printf("5)Log out\n\n");
}

void li_choice(){
    printf("\n(logged in as librarian)\n\n");
    printf("Please choose an option\n");
    printf("1)Add a book\n");
    printf("2)Remove a book\n");
    printf("3)Search for books\n");
    printf("4)Display all books\n");
    printf("5)Manage users\n");
    printf("6)Log out\n\n");
}

void add_choice(){
    printf("\nPlease choose an option\n\n");
    printf("1)Add a new book\n");
    printf("2)Increase the stock of existing books\n");
    printf("3)Quit\n");
}

void borrow_choice(){
    printf("\nPlease choose an option\n\n");
    printf("1)Borrow a book by ID\n");
    printf("2)Borrow a book by Title and Authors\n");
    printf("3)Quit\n");
    printf("Option:");
}

void search_choice(){
    printf("\nPlease choose an option:\n\n");
    printf("1)Find books by title\n");
    printf("2)Find books by authors\n");
    printf("3)Find books by year\n");
    printf("4)Quit\n");
    printf("Option:");
}
void goodbye(){
    printf("\nThank you for using the library!\n");
    printf("Goodbye~\n");
}

void lib_choice(){
    printf("\nPlease choose an option:\n\n");
    printf("1)Display the user list\n");
    printf("2)Force user to return books\n");
    printf("3)Delete user numbers and return all books\n");
    printf("4)Quit\n");
    printf("Option:");
}
