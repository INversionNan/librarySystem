#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"

Book *Book_load(){
    FILE *fp;
    Book *h=NULL,*t=h,*p;
    if((fp=fopen("Booknode.txt","r"))==NULL){
        printf("\t\t打开失败\n");
        exit(1);
    }
    getc(fp);
    if(feof(fp)){
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while(!feof(fp)){
        p=(Book *)malloc(sizeof(Book));
        p->next=NULL;
        fscanf(fp,"%s",p->title);
        fscanf(fp,"%s",p->authors);
        fscanf(fp,"%d",p->year);
        fscanf(fp,"%d",p->copies);
        fscanf(fp,"%s",&p->type);
        if(h==NULL)
            h=p;
        else
            t->next=p;
        t=p;
    }
    fclose(fp);
    return h;
}
int main() {
//    Book *Book_h;
//    User *User_h;
//    Librarian *Lib_h;
//    Book_h = (Book *)malloc(sizeof (Book));
//    User_h = (User *) malloc(sizeof (User));
//    Lib_h = (Librarian *) malloc(sizeof (Librarian));

    FILE *file = fopen("books.txt","w+");
    fclose(file);

    FILE *user;
    user = fopen("books.txt","w+");
    fclose(user);

//    Book_h ->next = Book_load();
//    User_h->next = User_load();
//    Lib_h->next = Lib_load();

    char a = '1';
    while(a != 0){
        welcome();
        menu();
        scanf("%c",&a);
        while(getchar()!='\n');
        switch (a) {
            case '1':reg();
            case '2':login();
            case '3':search();
            case '4':display();
            case '5':exit(0);
            default:
                printf("Sorry, the option you enter was invalid, please try again.");
        }
    }
    return 0;
}
