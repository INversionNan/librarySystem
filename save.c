//
// Created by 10526 on 2022/3/24.
//
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

void user_save(){
    int i,j;
    FILE *file;
    User *user_p = User_h->next;
    if(!user_p){
        return;
    }
    if ((file= fopen("user.txt","w+")) == NULL){
        printf("Failed to open the user file.\n");
        exit(1);
    }

    while (user_p->next){
        fprintf(file,"%s ",user_p->user_name);
        fprintf(file,"%s ",user_p->user_num);
        fprintf(file,"%s ",user_p->user_pass);
        for(j = 0; j < 10 ;j++){
            fprintf(file,"%d ",user_p->user_bor[j]);
        }
        for(i = 0; i < 9; i++){
            fprintf(file,"%s ",user_p->user_bor_book[i]);
        }
        fprintf(file,"%s\n",user_p->user_bor_book[9]);
    user_p = user_p->next;
    }
    fprintf(file,"%s ",user_p->user_name);
    fprintf(file,"%s ",user_p->user_num);
    fprintf(file,"%s ",user_p->user_pass);
    int k,l;
    for(l = 0; l < 10; l++){
        fprintf(file,"%d ",user_p->user_bor[l]);
    }
    for (k = 0; k < 9; k++) {
        fprintf(file,"%s ",user_p->user_bor_book[k]);
    }
    fprintf(file,"%s",user_p->user_bor_book[9]);
    fclose(file);
}//Store the user information in the user linked list in a file

void book_save(){
    FILE *file;
    Book *book_p = Book_h->next;
    Book *t;
    t = (Book *) malloc(sizeof (Book));
    Book *p = (Book *) malloc(sizeof (Book));
    int i,j;
    if(!book_p){
        return;
    }
    if((file = fopen("books.txt","w+")) == NULL){
        printf("Failed to open books file.\n");
        exit(1);
    }
    while (book_p->next){
        t->title = (char *) malloc(150);
        t->authors = (char *) malloc(150);
        strcpy(t->title,book_p->title);
        strcpy(t->authors,book_p->authors);
        for(i = 0; i < strlen(t->title); i++){
            if(t->title[i] == ' '){
                t->title[i] = '_';
            }
        }
        for(j = 0; j < strlen(t->authors); j++){
            if(t->authors[j] == ' '){
                t->authors[j] = '_';
            }
        }
        fprintf(file, "%d ", book_p->id);
        fprintf(file,"%s ",t->title);
        fprintf(file,"%s ",t->authors);
        fprintf(file, "%d ", book_p->year);
        fprintf(file, "%d\n", book_p->copies);
        book_p = book_p->next;
    }
    p->title = (char *) malloc(150);
    p->authors = (char *) malloc(150);
    strcpy(p->title,book_p->title);
    strcpy(p->authors,book_p->authors);
    for(i = 0; i < strlen(p->title); i++){
        if(p->title[i] == ' '){
            p->title[i] = '_';
        }
    }
    for(j = 0; j < strlen(p->authors); j++){
        if(p->authors[j] == ' '){
            p->authors[j] = '_';
        }
    }
    fprintf(file, "%d ", book_p->id);
    fprintf(file,"%s ",p->title);
    fprintf(file,"%s ",p->authors);
    fprintf(file, "%d ", book_p->year);
    fprintf(file, "%d", book_p->copies);
    fclose(file);
}//Store the book information in the book linked list in a file

void lib_save(){
    FILE *file;
    char lib_n[10] = "librarian";
    char lib_password[10] = "librarian";
    char lib_a[10] = "0";
    Librarian *lib_p = Lib_h->next;
    if((file = fopen("librarian.txt","w+")) == NULL){
        printf("Failed to open books file.\n");
        exit(1);
    }
    fprintf(file,"%s\t", lib_n);
    fprintf(file,"%s\t", lib_password);
    fprintf(file,"%s\n", lib_a);
    if(!lib_p){
        fprintf(file,"%s\t", lib_n);
        fprintf(file,"%s\t", lib_password);
        fprintf(file,"%s\n", lib_a);
    }
    fclose(file);
}//Store the information in the librarian linked list in a file

void Save(){
    book_save();
    user_save();
    lib_save();
    goodbye();
    exit(0);
}//Save all the information and show the goodbye menu