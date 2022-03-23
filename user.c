#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "book_management.h"

void reg(){
    int i;
    char password[15];
    User *new = (User *)malloc(sizeof (User));
//    printf("Please enter a username:");
    for(i = 0;i < 15; i++){
        new->user_bor_book[i][0] ='0';
        new->user_bor_book[i][1] ='\0';
    }
    printf("Welcome to the Register System\n\n");
    printf("Please enter a user name:");
    scanf("%s",new->user_name);
    printf("Please enter your ID number:");
    scanf("%s",new->user_num);
    printf("Please enter a password:");
    password_input(new->user_pass);
    printf("To verify your password, please enter it again:");
    check(new->user_pass);
}

void login(){

}

User *User_load(){
    FILE *file;
    User *h=NULL;
    User *t = h;
    User *p_stu;
    int i;
    if((file = fopen("Student.txt","r"))==NULL){
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
        p_stu = (User *) malloc(sizeof (User));
        p_stu->next = NULL;
        fscanf(file, "%s", p_stu->user_acc);
        fscanf(file, "%s", p_stu->user_pass);
        fscanf(file, "%s", p_stu->user_num);
        fscanf(file, "%s", p_stu->user_name);
        fscanf(file, "%s", p_stu->user_tel);
        for (i = 0; i < 10; ++i) {
            fscanf(file, "%s", p_stu->user_bor_book[i]);
        }
//        int length = strlen(p_stu->user_pass);
        if(h == NULL){
            h = p_stu;
        } else{
            t->next = p_stu;
        }
        t = p_stu;
    }
    fclose(file);
    return h;
}
void user(){
    char b = '1';
    while(b != '0'){
        stu_choice();
        scanf("%c",&b);
        while(getchar() != '\n');
        switch (b) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            default:
                printf("");
        }
    }
}

void search(){

}

void display(){
//    Book *p1 = Book_h->next;
//    while(p1 != NULL){
//        printf("%d %s %s %d %d %s\n",p1->id, p1->title, p1->authors, p1->year, p1->copies,p1->type);
//        p1 = p1->next;
//    }
}


