#include "book_management.h"
#include <stdlib.h>
#include <string.h>

Book *Book_load(){
    int i,j;
    FILE *file;
    Book *h=NULL,*t=h,*p;
    if((file=fopen("books.txt","r"))==NULL){
        file = fopen("books.txt","w+");
    }
    getc(file);
    if(feof(file)){
        fclose(file);
        return NULL;
    }
    rewind(file);
//    char *num;
//    num = (char *) malloc(300 * sizeof (char));
    while(!feof(file)){
        p=(Book *)malloc(sizeof(Book));
        p->next=NULL;
        p->title = (char *)malloc(300 * sizeof (char ));
        p->authors = (char *)malloc(300 * sizeof (char));
        fscanf(file,"%d",&p->id);
        fscanf(file,"%s",p->title);
        for(i = 0; i < strlen(p->title); i ++){
            if(p->title[i] == '_'){
                p->title[i] = ' ';
            }
        }
        fscanf(file,"%s",p->authors);
        for(j = 0; j < strlen(p->authors); j ++){
            if(p->authors[j] == '_'){
                p->authors[j] = ' ';
            }
        }
//        printf("%s\n",p->title);
//        printf("%s\n",p->authors);
        fscanf(file,"%d",&p->year);
        fscanf(file,"%d",&p->copies);
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

    Book_h ->next = Book_load();
    User_h->next = User_load();
    Lib_h->next = Lib_load();

//    while(1){
//        printf("%s\n",User_h->user_name);
//        printf("%s\n",User_h->user_pass);
//        User_h = User_h->next;
//        if(!User_h){
//
//            break;
//        }
//    }
//    file = fopen("books.txt","w+");
//    store_books(file);
//    load_books(file);
//    fclose(file);



//    char lib_n[10] = "librarian";
//    char lib_password[10] = "librarian";
//    char lib_a[10] = "0";
//

//    fprintf(lib,"%s\t", lib_n);
//    fprintf(lib,"%s\t", lib_password);
//    fprintf(lib,"%s\t", lib_a);
//    fclose(lib);

//
    char a = '1';
    welcome();
    while(a != '5'){
        while (1){
            menu();
            printf("Option:");
            int count = 0;
            scanf("%c",&a);
            while(getchar()!='\n') count ++;
            if(count > 0){
                printf("Sorry, the option you enter was invalid, please try again.\n\n");
                continue;
            }else{
                break;
            }
        }
        switch (a) {
            case '1':reg(); break;
            case '2':login(); break;
            case '3':search(); break;
            case '4':display(); break;
            case '5':Save();break;
            default:
                printf("Sorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
    FILE *fp = fopen("books.txt","r");
    load_books(fp);
    fclose(fp);
    return 0;
}