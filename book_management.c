#include "book_management.h"
#include <stdlib.h>
#include <string.h>

Book *Book_load(){
    FILE *file;
    Book *h=NULL,*t=h,*p;
    if((file=fopen("books.txt","r"))==NULL){
        printf("Failed to open books file.\n");
        exit(1);
    }
    getc(file);
    if(feof(file)){
        fclose(file);
        return NULL;
    }
    rewind(file);
    char *num;
    num = (char *) malloc(300 * sizeof (char));
    while(!feof(file)){
        p=(Book *)malloc(sizeof(Book));
        p->next=NULL;

        fscanf(file,"%d",p->id);
        fscanf(file,"%s",p->title);
        fscanf(file,"%s",p->authors);
        fscanf(file,"%d",p->year);
        fscanf(file,"%d",p->copies);
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        p->id = atoi(num);

//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        strcpy(p->title,num);
//        p->authors[strlen(p->title)-1] = '\0';
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        strcpy(p->authors,num);
//        p->authors[strlen(p->authors)-1] = '\0';

//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        p->year = atoi(num);
//
//        fgets(num,50,file);
//        num[strlen(num)-1] = '\0';
//        p->copies = atoi(num);


        if(h==NULL){
            h = p;
        }else{
            t->next=p;
        }
        t = p;
    }
    fclose(file);
    return h;
}
int main() {

    Book_h = (Book *)malloc(sizeof (Book));
    User_h = (User *) malloc(sizeof (User));
    Lib_h = (Librarian *) malloc(sizeof (Librarian));

    FILE *file = fopen("books.txt","r");
//    store_books(file);
    load_books(file);
    fclose(file);

    FILE *user = fopen("user.txt","w+");
    fclose(user);

    char lib_n[10] = "librarian";
    char lib_password[10] = "librarian";
    char lib_a[10] = "0";

    FILE *lib = fopen("librarian.txt","w+");
    fprintf(file,"%s\t", lib_n);
    fprintf(file,"%s\t", lib_password);
    fprintf(file,"%s\t", lib_a);
    fclose(lib);


    Book_h ->next = Book_load();
    User_h->next = User_load();
    Lib_h->next = Lib_load();
//


    char a = '1';
    welcome();
    while(a != 0){
        menu();
        printf("Option:");
        scanf("%c",&a);
        while(getchar()!='\n');
        switch (a) {
            case '1':reg(); break;
            case '2':login(); break;
            case '3':search(); break;
            case '4':display(); break;
            case '5':Save();break;
            default:
                printf("Sorry, the option you enter was invalid, please try again.\n");
        }
    }
    FILE *fp = fopen("books.txt","w+");
    store_books(fp);
    fclose(fp);
    return 0;
}