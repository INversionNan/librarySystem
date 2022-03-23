#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book_management.h"

int store_books(FILE *file) {
    int i, f;
    char g;
    char e[100];
    while (1) {
        memset(e, '\0', sizeof e);
        printf("Enter the title of the book:");
        gets(e);
        for (i = 0; e[i] != '\0'; i++) {
            if (e[i] == ' ') {
                e[i] = '_';
            }
        }
        fprintf(file, "%s\t", e); // write a title of the book

        memset(e, '\0', sizeof e);
        printf("Enter the author of the book:");
        gets(e);
        for (i = 0; e[i] != '\0'; i++) {
            if (e[i] == ' ') {
                e[i] = '_';
            }
        }
        fprintf(file, "%s\t", e); // write an author of the book

        memset(e, '\0', sizeof e);
        printf("Enter the year of the book:");
        scanf("%d", &f);
        fprintf(file, "%d\t", f); // write the year of the book

        printf("Enter the copies of the book:");
        scanf("%d", &f);
        fprintf(file, "%d\t", f); // write the copies of the book

        memset(e, '\0', sizeof e);
        printf("Enter the type of the book:");
        gets(e);
        fprintf(file, "%s\t", e); // write the type of the book

        printf("Continue to store books? Please enter (y or n).");
        scanf("%s", &g);
        if(g =='n') {
            break;
        }
    }
}
int load_books(FILE *file){
    int i;
    Book *k=NULL;
    Book *t = k;
    Book *a;
    if((file = fopen("Books.txt","w+")) == NULL){
        printf("Failed to open the file");
        exit(1);
    }
    getc(file);
    if(feof(file)){
        fclose(file);
        i = 0;
        return i;
    }
    rewind(file);
    while(!feof(file)){
        a = (Book *)malloc(sizeof(Book));
        a->next = NULL;
        fscanf(file,"%s",a->title);
        fscanf(file,"%s",a->authors);
        fscanf(file,"%d",&a->year);
        fscanf(file,"%d",&a->copies);
        fscanf(file,"%s",a->type);
        if(k == NULL){
            k = a;
        } else{
            t->next = a;
        }
        t = a;
    }
    fclose(file);
    i = 1;
    return i;
}
int add_book(Book book){

}

Librarian *Lib_load(){
    FILE *file;
    Librarian *q=NULL;
    Librarian *t = q;
    Librarian *p_lib;
    int i;
    if((file = fopen("Librarian.txt","r"))==NULL){
        printf("Failed to open it.");
        exit(1);
    }
    getc(file);
    if(feof(file)){
        fclose(file);
        return NULL;
    }
    rewind(file);
    while (!feof(file)){
        p_lib = (Librarian *) malloc(sizeof (Librarian));
        p_lib->next = NULL;
        fscanf(file, "%s", p_lib->lib_acc);
        fscanf(file, "%s", p_lib->lib_name);
        fscanf(file, "%s", p_lib->lib_pass);
//        int length = strlen(p_stu->user_pass);
        if(q == NULL){
            q = p_lib;
        } else{
            t->next = p_lib;
        }
        t = p_lib;
    }
    fclose(file);
    return q;
}
void lib(){
    char c ='1';
    while(c != '0'){
        li_choice();
        scanf("%c",&c);
        while(getchar() != '\n');
        switch (c) {
            case '1':
//                add_book(book);
            case '2':
//                remove_book();
            case '3':

            case '4':
            case '5':
            default:
                printf("");
        }
    }
}