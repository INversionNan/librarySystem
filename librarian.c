#include "book_management.h"
#include <string.h>
#include <stdlib.h>


int store_books(FILE *file) {
//    int i, f;
//    char g;
//    char e[100];
    Book *book_p;
    if(file == NULL){
        printf("Failed to open books file.\n");
        return -1;
    }
    book_p = Book_h;
    book_p = book_p->next;
//    if(!book_p->next){
//        fprintf(file, "%d\n", book_p->id);
//        book_p->title[strlen(book_p->title)] = '\n';
//        fputs(book_p->title,file);
//        book_p->authors[strlen(book_p->authors)] = '\n';
//        fputs(book_p->authors,file);
//        fprintf(file, "%d\n", book_p->year);
//        fprintf(file, "%d\n", book_p->copies);
//    }
//    while (book_p->next){
//        fprintf(file, "%d\n", book_p->id);
//        book_p->title[strlen(book_p->title)] = '\n';
//        fputs(book_p->title,file);
//        book_p->authors[strlen(book_p->authors)] = '\n';
//        fputs(book_p->authors,file);
//        fprintf(file, "%d\n", book_p->year);
//        fprintf(file, "%d\n", book_p->copies);
//
//        book_p = book_p->next;
//    }
    if(!book_p->next){
        fprintf(file, "%d\t", book_p->id);
//        book_p->title[strlen(book_p->title)] = '\t';
//        fputs(book_p->title,file);
//        book_p->authors[strlen(book_p->authors)] = '\t';
//        fputs(book_p->authors,file);
        fprintf(file,"%s\t",book_p->title);
        fprintf(file,"%s\t",book_p->authors);
        fprintf(file, "%d\t", book_p->year);
        fprintf(file, "%d\t", book_p->copies);
    }
    while (book_p->next){
        fprintf(file, "%d\t", book_p->id);
//        book_p->title[strlen(book_p->title)] = '\t';
//        fputs(book_p->title,file);
//        book_p->authors[strlen(book_p->authors)] = '\t';
//        fputs(book_p->authors,file);
        fprintf(file,"%s\t",book_p->title);
        fprintf(file,"%s\t",book_p->authors);
        fprintf(file, "%d\t", book_p->year);
        fprintf(file, "%d\t", book_p->copies);

        book_p = book_p->next;
    }
    fclose(file);
    return 0;
//    while (1) {
//        memset(e, '\0', sizeof e);
//        printf("Enter the title of the book:");
//        gets(e);
//        for (i = 0; e[i] != '\0'; i++) {
//            if (e[i] == ' ') {
//                e[i] = '_';
//            }
//        }
//        fprintf(file, "%s\t", e); // write a title of the book
//
//        memset(e, '\0', sizeof e);
//        printf("Enter the author of the book:");
//        gets(e);
//        for (i = 0; e[i] != '\0'; i++) {
//            if (e[i] == ' ') {
//                e[i] = '_';
//            }
//        }
//        fprintf(file, "%s\t", e); // write an author of the book
//
//        memset(e, '\0', sizeof e);
//        printf("Enter the year of the book:");
//        scanf("%d", &f);
//        fprintf(file, "%d\t", f); // write the year of the book
//
//        printf("Enter the copies of the book:");
//        scanf("%d", &f);
//        fprintf(file, "%d\t", f); // write the copies of the book
//
//        memset(e, '\0', sizeof e);
//        printf("Enter the type of the book:");
//        gets(e);
//        fprintf(file, "%s\t", e); // write the type of the book
//
//        printf("Continue to store books? Please enter (y or n).");
//        scanf("%s", &g);
//        if(g =='n') {
//            break;
//        }
//    }
}

int load_books(FILE *file){
    int i;
    Book *k=NULL;
    Book *t = k;
    Book *a;
    char *num;
    if((file = fopen("books.txt","w+")) == NULL){
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

        fscanf(file,"%d",a->id);
        fscanf(file,"%s",a->title);
        fscanf(file,"%s",a->authors);
        fscanf(file,"%d",a->year);
        fscanf(file,"%d",a->copies);

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

Book *repeated(char *a ,char *b, unsigned int c){
    Book *book_p1 = Book_h->next;
    while (book_p1){
        if(strcmp(a, book_p1->title)==0 && strcmp(b, book_p1->authors)==0
           && (c == book_p1->year)){
            return book_p1;
        }
        book_p1 = book_p1->next;
    }
    return NULL;
}

int add_book(Book book){
    FILE  *file = fopen("books.txt","w+");
    char addb = '1';
    char *t, *p;
    Book *book_p3;
    p = (char *) malloc(300 * sizeof (char ));
    t = (char *) malloc(300 * sizeof (char ));
    Book *add = (Book *) malloc(sizeof (Book));
    add->next = NULL;
    Book *add_1 = (Book *) malloc(sizeof (Book));
    add->next = NULL;
//    add->next = NULL;
//    add_1->next = NULL;
//    book.next = NUll;

    while(addb != '0'){
        add_choice();
        printf("\nOption:");
        scanf("%c", &addb);
        while (getchar()!='\n');
        switch (addb) {
            case'1':
                printf("\nEnter the title of the book you wish to add:\n");
                fflush(stdin);
                gets(t);
                book.title = (char *) malloc(300 * sizeof (char));
                strcpy(book.title,t);

                printf("Enter the author of the book you wish to add:\n");
                fflush(stdin);
                gets(t);
                book.authors = (char *) malloc(300 * sizeof (char));
                strcpy(book.authors,t);

                printf("Enter the year of the book you wish to add:\n");
                fflush(stdin);
                gets(t);
                book.year = atoi(t);

//                scanf("%d",&add->year);
//                getchar();
//                book.year = add->year;

                if(repeated(book.title,book.authors,book.year)){
                    printf("This book has already existed, so no new book can be added\n");
                    printf("If you want to add it, please choose option 2.\n");
                    free(add);
                    break;
                }

                printf("Enter the copies of the book you wish to add:\n");
//                scanf("%d",&add->copies);
//                getchar();
//                book.copies = add->copies;
                fflush(stdin);
                gets(t);
                book.copies = atoi(t);

                add->title = book.title;
                add->authors = book.authors;
                add->year = book.year;
                add->copies = book.copies;

//                unsigned int id = 0;
//                Book *book_p2 = Book_h->next;
//                while(1){
//                    if(book_p2 == NULL){
//                        book_p2->id = id +1;
//                        book_p2->next = NULL;
//                        break;
//                    }
//                    id = book_p2->id;
//                    book_p2 = book_p2->next;
//                }
//                while(1){
//                    if(book_p2 == NULL){
//                        book_p2 = (Book *) malloc(sizeof (Book));
//                        book_p2->id = id + 1;
//                        book_p2->title = book.title;
//                        book_p2->authors = book.authors;
//                        book_p2->year = book.year;
//                        book_p2->copies = book.copies;
//                        book_p2->type = book.type;
//                        book_p2->next = NULL;
//                        break;
//                    }
//                    id = book_p2->id;
//                    book_p2 = book_p2->next;
//                }
                book_p3 = Book_h;
                while (book_p3->next){
                    book_p3->id += 1;
                    book_p3 = book_p3->next;
                }
                add->id = book_p3->id;
                book_p3->next = add;
                book_save();
               //store_books(file);
                break;
            case '2':
                printf("\nEnter the title of the book you wish to add:\n");
                fflush(stdin);
                gets(p);
                book.title = (char *) malloc(300 * sizeof (char));
                strcpy(book.title,p);

                printf("Enter the author of the book you wish to add:\n");
                fflush(stdin);
                gets(p);
                book.authors = (char *) malloc(300 * sizeof (char));
                strcpy(book.authors,p);

                printf("Enter the year of the book you wish to add:\n");
                fflush(stdin);
                gets(t);
                book.year = atoi(p);

//                scanf("%d",&add->year);
//                getchar();
//                book.year = add->year;

                if(repeated(book.title,book.authors,book.year) == NULL){
                    printf("This book does not exist in stock.\n");
                    printf("If you want to add it, please choose option 1,\n");
                    free(add_1);
                    break;
                }

                add_1->title = book.title;
                add_1->authors = book.authors;
                add_1->year = book.year;

                printf("Enter the copies of the book you wish to add:\n");
//                scanf("%d",&add->copies);
//                getchar();
//                book.copies = add->copies;
                fflush(stdin);
                gets(t);
                book.copies = atoi(p);
                add_1->copies = book.copies;

                while (add_1->next){
                    add = add_1->next;
                }
                add_1->next = add_1;

                Book *book_p3 = repeated(book.authors,book.title,book.year);
                book_p3->copies += book.copies;
                store_books(file);
                break;

            case '3':break;
            default:
                printf("Sorry, the option you enter was invalid, please try again.\n");
                break;
        }
        if(addb == '3'){
            break;
        }
    }
    return 1;
}

int remove_book(Book book){

}

Librarian *Lib_load(){
    FILE *file;
    Librarian *q=NULL;
    Librarian *t = q;
    Librarian *p_lib;
    int i;
    if((file = fopen("librarian.txt","r"))==NULL){
        printf("Failed to open librarian file.\n");
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
        fscanf(file, "%s", p_lib->lib_name);
        fscanf(file, "%s", p_lib->lib_pass);
        fscanf(file, "%s", p_lib->lib_acc);
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