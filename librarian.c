#include "book_management.h"
#include <string.h>
#include <stdlib.h>


int store_books(FILE *file) {
    Book *book_p, *p, *t;
    int i, j;
    if((file = fopen("books.txt","w+")) == NULL){
        printf("Failed to open books file.\n");
        exit(1);
    }
    book_p = Book_h;
    book_p = book_p->next;
    p = (Book *) malloc(sizeof (Book));
    while (book_p->next){
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
//        book_p->title[strlen(book_p->title)] = '\t';
//        fputs(book_p->title,file);
//        book_p->authors[strlen(book_p->authors)] = '\t';
//        fputs(book_p->authors,file);
        fprintf(file,"%s ",p->title);
        fprintf(file,"%s ",p->authors);
        fprintf(file, "%d ", book_p->year);
        fprintf(file, "%d\n", book_p->copies);
        book_p = book_p->next;
    }
    t = (Book *) malloc(sizeof (Book));
    t->title = (char *) malloc(300 * sizeof (char));
    t->authors = (char *) malloc(300 * sizeof (char));
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
    fprintf(file, "%d", book_p->copies);
    fclose(file);
    return 0;
}

int load_books(FILE *file){
    int i ,j ,m;
    Book *k=NULL;
    Book *t = k;
    Book *a;
    char *num;
    if(file == NULL){
        printf("Failed to open books file.\n");
        return -1;
    }
    if((file = fopen("books.txt","r")) == NULL){
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
        a=(Book *)malloc(sizeof(Book));
        a->next=NULL;
        a->title = (char *)malloc(300 * sizeof (char));
        a->authors = (char *)malloc(300 * sizeof (char));
        fscanf(file,"%d",&a->id);
        fscanf(file,"%s",a->title);
        for(j = 0; j < strlen(a->title); j++){
            if(a->title[j] == '_'){
                a->title[j] = ' ';
            }
        }

        fscanf(file,"%s",a->authors);
        for(m = 0; m < strlen(a->authors); m++){
            if(a->authors[m] == '_'){
                a->authors[m] = ' ';
            }
        }
        fscanf(file,"%d",&a->year);
        fscanf(file,"%d",&a->copies);
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
    p = (char *) malloc(300 * sizeof (char ));
    t = (char *) malloc(300 * sizeof (char ));
//    add->next = NULL;
//    add_1->next = NULL;
//    book.next = NUll;

    while(addb != '3'){
        Book *book_p3, *book_p4;
        book_p3 = Book_h;
        Book *add = (Book *) malloc(sizeof (Book));
        add->title = (char *) malloc(sizeof (add->title));
        add->authors = (char *)malloc(sizeof (add->authors));
        add->next = NULL;
        Book *add_1 = (Book *) malloc(sizeof (Book));
        add_1->title = (char *) malloc(sizeof (add->title));
        add_1->authors = (char *)malloc(sizeof (add->authors));
        add_1->next = NULL;
        while (1){
            add_choice();
            printf("\nOption:");
            int count_3 = 0;
            scanf("%c",&addb);
            while(getchar()!='\n') count_3 ++;
            if(count_3 > 0){
                printf("Sorry, the option you enter was invalid, please try again.\n");
                continue;
            }else{
                break;
            }
        }
        switch (addb) {
            case '1':
                display();
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

                while (1){
                    printf("Enter the year of the book you wish to add:\n");
                    fflush(stdin);
                    gets(t);
                    book.year = atoi(t);
                    if(book.year > 0 && book.year <= 2022){
                        break;
                    } else{
                        printf("\nWrong year, please enter year again.\n\n");
                        continue;
                    }
                }

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
//                printf("1111111111\n");
                strcpy(add->title,book.title);
                strcpy(add->authors,book.authors);
//                add->title = book.title;
//                add->authors = book.authors;
                add->year = book.year;
                add->copies = book.copies;
                add->id = book.id + 1;
                while (1){
                    if(book_p3->next == NULL){
                        add->next = NULL;
                        book_p3->next = add;
                        break;
                    }
                    add->id = book_p3->next->id;
                    add->id++;
                    book_p3 = book_p3->next;
                }
                book_save();
                //store_books(file);
                break;
            case '2':
                display();
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
                gets(p);
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

                printf("Enter the copies of the book you wish to add:\n");
//                scanf("%d",&add->copies);
//                getchar();
//                book.copies = add->copies;
                fflush(stdin);
                gets(p);
                book.copies = atoi(p);

                strcpy(add_1->title,book.title);
                strcpy(add_1->authors,book.authors);
//                add_1->title = book.title;
//                add_1->authors = book.authors;
                add_1->year = book.year;
                add_1->copies = book.copies;

//                while (add_1->next){
//                    add = add_1->next;
//                }
//                add_1->next = add_1;

                book_p4 = repeated(book.authors,book.title,book.year);
                book_p4->copies += book.copies;

                store_books(file);
                break;

            case '3':break;
            default:
                printf("Sorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
    return 1;
}

int remove_book(Book book){
    int i;
    Book *book_remove = Book_h;
    Book *p = Book_h->next;
    User *user_borrow = User_h;
    if(book.id == 0){
        printf("\nThe book was not found in the library.\n");
        return -2;
    }
    while(user_borrow){
        for (i = 0; i < 10; ++i) {
            if(user_borrow->user_bor[i] == book.id){
                printf("\nYou can not remove this book, because some student has borrowed the book.\n");
                return -2;
            }
        }
        user_borrow = user_borrow ->next;
    }

    while (1){
        if(book_remove == NULL || p == NULL){
            printf("\nThe book was not found in the library.\n");
            return -2;
        }
        if(book_remove->id == book.id-1) {
            book_remove->next = p->next;
            free(p);
            break;
        }
        book_remove = book_remove->next;
        p = book_remove->next;
    }
    printf("\nYou have deleted this book successfully!\n");
    book_save();
    return 0;
}

Librarian *Lib_load(){
    FILE *file;
    Librarian *q=NULL;
    Librarian *t = q;
    Librarian *p_lib;
    int i;
    if((file = fopen("librarian.txt","r"))==NULL){
        file = fopen("librarian.txt","w+");
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