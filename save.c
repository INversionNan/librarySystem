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
//    file= fopen("user.txt","w+");
    while (user_p->next){
//        printf("%s\n\n\n",user_p->user_name);
//        printf("%s",User_h->next->user_name);
        fprintf(file,"%s ",user_p->user_name);
        fprintf(file,"%s ",user_p->user_num);
        fprintf(file,"%s ",user_p->user_pass);
//        fprintf(file,"%s",p->user_name);
//        fprintf(file,"%s",p->user_num);
//        fprintf(file,"%s",p->user_pass);
        for(j = 0; j < 10 ;j++){
            fprintf(file,"%d ",user_p->user_bor[j]);
        }
        for(i = 0; i < 9; i++){
            fprintf(file,"%s ",user_p->user_bor_book[i]);
//            fprintf(file,"%s",p->user_bor_book[i]);
        }
        fprintf(file,"%s\n",user_p->user_bor_book[9]);
//        fprintf(file,"%s\n",p->user_bor_book[9]);
//        fclose(file);
    user_p = user_p->next;
    }
//    printf("%s\n\n\n",user_p->user_name);
//    printf("%s",User_h->next->user_name);
    fprintf(file,"%s ",user_p->user_name);
    fprintf(file,"%s ",user_p->user_num);
    fprintf(file,"%s ",user_p->user_pass);
//    fputs(user_p->user_name,file);
//    fputs(user_p->user_num,file);
//    fputs(user_p->user_pass,file);
    int k,l;
    for(l = 0; l < 10; l++){
        fprintf(file,"%d ",user_p->user_bor[l]);
    }
    for (k = 0; k < 9; k++) {
        fprintf(file,"%s ",user_p->user_bor_book[k]);
    }
    fprintf(file,"%s",user_p->user_bor_book[9]);
//    user_p->next = NULL;
    fclose(file);
}

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
//    Book *book_t = Book_h->next;
//    while(book_t){
//        t->title = (char *) malloc(sizeof (t->title));
//        t->authors = (char *) malloc(sizeof (t->authors));
//        strcpy(t->title,book_t->title);
//        strcpy(t->authors,book_t->authors);
//        for(i = 0; i < strlen(t->title); i++){
//            if(t->title[i] == ' '){
//                t->title[i] = '_';
//            }
//        }
//        for(j = 0; j < strlen(t->authors); j++){
//            if(t->authors[j] == ' '){
//                t->authors[j] = '_';
//            }
//        }
//        fprintf(file, "%d ", book_t->id);
//        fprintf(file,"%s ",t->title);
//        fprintf(file,"%s ",t->authors);
//        fprintf(file, "%d ", book_t->year);
//        fprintf(file, "%d\n", book_t->copies);
//        book_t = book_t->next;
//    }
//    free(book_t);
    while (book_p->next){
        t->title = (char *) malloc(sizeof (t->title));
        t->authors = (char *) malloc(sizeof (t->authors));
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
//        book_p->title[strlen(book_p->title)] = '\t';
//        fputs(book_p->title,file);
//        book_p->authors[strlen(book_p->authors)] = '\t';
//        fputs(book_p->authors,file);
        fprintf(file,"%s ",t->title);
        fprintf(file,"%s ",t->authors);
        fprintf(file, "%d ", book_p->year);
        fprintf(file, "%d\n", book_p->copies);
        book_p = book_p->next;
    }
    p->title = (char *) malloc(300 * sizeof (char));
    p->authors = (char *) malloc(300 * sizeof (char));
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
//    free(p);
    fclose(file);
}

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
//    while ( lib_p ->next){
//        fprintf(file,"%s\t",lib_p->lib_name);
//        fprintf(file,"%s\t",lib_p->lib_pass);
//        fprintf(file,"%s\n",lib_p->lib_acc);
//        lib_p = lib_p->next;
//    }
//    fprintf(file,"%s\t",lib_p->lib_name);
//    fprintf(file,"%s\t",lib_p->lib_pass);
//    fprintf(file,"%s\t",lib_p->lib_acc);
    fclose(file);
}

void Save(){
    book_save();
    user_save();
    lib_save();
    goodbye();
    exit(0);
}

//void load_User(){
//    FILE *file;
//    User *h=NULL,*t = h,*p_stu;
//    int i;
//    if((file = fopen("user.txt","r"))==NULL){
//        file = fopen("user.txt","w+");
//    }
//    getc(file);
//    if(feof(file)){
//        fclose(file);
//        return;
//    }
//    rewind(file);
//    while(!feof(file)){
//        while (1){
//            fscanf()
//        }

//        a = (Book *)malloc(sizeof(Book));
//        a->next = NULL;
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        a->id = atoi(num);
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        strcpy(a->title,num);
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        strcpy(a->authors,num);
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        a->year = atoi(num);
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        a->copies = atoi(num);

//        if(k == NULL){
//            k = a;
//        } else{
//            t->next = a;
//        }
//        t = a;
//    }
//    fclose(file);
//}