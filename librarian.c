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
        fprintf(file, "%d\n", book_p->copies);
        book_p = book_p->next;
    }
    t = (Book *) malloc(sizeof (Book));
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
    fprintf(file, "%d", book_p->copies);
    fclose(file);
    return 0;
}//Store the book information in the book linked list in a file

int load_books(FILE *file){
    int i ,j ,m;
    Book *k=NULL;
    Book *t = k;
    Book *a;
    //char *num;
    if(file == NULL){
        printf("Failed to open books file.\n");
        return -1;
    }
    if((file = fopen("books.txt","r")) == NULL){
        printf("Failed to open the file");
        exit(1);
    }
    getc(file);//If a character is read from a file, EOF is returned at the end of the file without data
    if(feof(file)){
        fclose(file);
        i = 0;
        return i;
    }//Check end of file on stream (read end of file)
    rewind(file);//Redirects the position pointer inside a file to the beginning of a stream (data stream/file)
    while(!feof(file)){
        a=(Book *)malloc(sizeof(Book));
        a->next=NULL;
        a->title = (char *)malloc(150);
        a->authors = (char *)malloc(150);
        fscanf(file,"%d",&a->id);
        fscanf(file,"%s",a->title);
        for(j = 0; j < strlen(a->title); j++){
            if(a->title[j] == '_'){
                a->title[j] = ' ';
            }
        }//Replace the underscore with a space

        fscanf(file,"%s",a->authors);
        for(m = 0; m < strlen(a->authors); m++){
            if(a->authors[m] == '_'){
                a->authors[m] = ' ';
            }
        }//Replace the underscore with a space
        fscanf(file,"%d",&a->year);
        fscanf(file,"%d",&a->copies);
        if(k == NULL){
            k = a;
        } else{
            t->next = a;
        }
        t = a;
    }//Read file information line by line into the linked list until the end of the file
    fclose(file);
    i = 1;
    return i;
}//Load the book information to the linked list

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
}//Check the repeated book

int add_book(Book book){
    FILE  *file = fopen("books.txt","w+");
    char addb = '1';
    char *t, *p;
    int a, i;
    int j = 0;
    p = (char *) malloc(150);
    t = (char *) malloc(150);

    while(addb != '3'){
        Book *book_p3, *book_p4;
        book_p3 = Book_h;
        Book *add = (Book *) malloc(sizeof (Book));
        add->title = (char *) malloc(150);
        add->authors = (char *)malloc(150);
        add->next = NULL;
        Book *add_1 = (Book *) malloc(sizeof (Book));
        add_1->title = (char *) malloc(150);
        add_1->authors = (char *)malloc(150);
        add_1->next = NULL;
        while (1){
            add_choice();
            printf("\nOption:");
            int count_3 = 0;
            scanf("%c",&addb);
            while(getchar()!='\n') count_3 ++;
            if(count_3 > 0){
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                continue;
            }else{
                break;
            }
        }
        switch (addb) {
            case '1':
                display();
                while(j == 0){
                    printf("\nEnter the title of the book you wish to add:\n");
                    fgets(t,50,stdin);
                    for(i = 0; t[i] != '\n' && i < strlen(t); i++);
                    if(i == strlen(t)) while(getchar()!='\n');
                    for(i = 0; i < strlen(t); i ++){
                        if(t[i] == '\r' || t[i] == '\n'){
                            t[i] = '\0';
                            break;
                        }
                    }
                    if(strlen(t) > 40){
                        printf("\nYour title is too long, please enter title again which should keep under 40 words\n");
                        continue;
                    }
                    //book.title = (char *) malloc(150);
                    strcpy(book.title,t);
                    j = 1;
                }
                j = 0;

                while (j == 0){
                    printf("Enter the author of the book you wish to add:\n");
                    fgets(t,50,stdin);
                    for(i = 0; t[i] != '\n' && i < strlen(t); i++);
                    if(i == strlen(t)) while(getchar()!='\n');
                    for(i = 0; i < strlen(t); i ++){
                        if(t[i] == '\r' || t[i] == '\n'){
                            t[i] = '\0';
                            break;
                        }
                    }
                    if(strlen(t) > 40){
                        printf("\nYour authors are too long, please enter authors again which should keep under 40 words\n");
                        continue;
                    }
                   // book.authors = (char *) malloc(150);
                    strcpy(book.authors,t);
                    j = 1;
                }
                j = 0;
//                while (1){
//                    printf("Enter the year of the book you wish to add:\n");
//                    fflush(stdin);
//                    gets(t);
//                    book.year = atoi(t);
//                    if(book.year > 0 && book.year <= 2022){
//                        break;
//                    } else{
//                        printf("\nWrong year, please enter year again.\n\n");
//                        continue;
//                    }
//                }

                while (1){
                    printf("Enter the year of the book you wish to add:\n");
                    fflush(stdin);
                    fgets(t,50,stdin);
                    for(i = 0; t[i] != '\n' && i < strlen(t); i++);
                    if(i == strlen(t)) while(getchar()!='\n');
                    for(i = 0; i < strlen(t); i ++){
                        if(t[i] == '\r' || t[i] == '\n'){
                            t[i] = '\0';
                            break;
                        }
                    }
                    for (i = 0; i < strlen(t); ++i) {
                        if(t[i] < '0' || t[i] > '9'){
                            printf("\nWrong year, please enter year again.\n\n");
                            i = -1;
                            break;
                        }
                    }
                    if(i == -1) continue;
                    a = atoi(t);
                    if(a > 0 && a <= 2022){
                        book.year = a;
                        break;
                    } else{
                        printf("\nWrong year, please enter year again.\n\n");
                        continue;
                    }
                }
                if(repeated(book.title,book.authors,book.year)){
                    printf("\nThis book has already existed, so no new book can be added\n");
                    printf("If you want to add it, please choose option 2.\n");
                    free(add);
                    break;
                }//Check the book has existed in the library.

                while(1){
                    printf("Enter the copies of the book you wish to add:\n");
                    fflush(stdin);
                    fgets(t,50,stdin);
                    for(i = 0; t[i] != '\n' && i < strlen(t); i++);
                    if(i == strlen(t)) while(getchar()!='\n');
                    for(i = 0; i < strlen(t); i ++){
                        if(t[i] == '\r' || t[i] == '\n'){
                            t[i] = '\0';
                            break;
                        }
                    }
                    for (i = 0; i < strlen(t); ++i) {
                        if(t[i] < '0' || t[i] > '9'){
                            printf("\nWrong copies, please enter copies again which at least more than 1.\n\n");
                            i = -1;
                            break;
                        }
                    }
                    if(i == -1) continue;
                    a = atoi(t);
                    if(a > 0){
                        book.copies = a;
                        break;
                    } else{
                        printf("\nWrong copies, please enter copies again which at least more than 1.\n\n");
                    }
                }

                strcpy(add->title,book.title);
                strcpy(add->authors,book.authors);
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
                printf("\nYou have added this book successfully.\n");
                //store_books(file);
                break;
            case '2':
                display();
                printf("\nEnter the title of the book you wish to add:\n");
                fflush(stdin);
                fgets(p,50,stdin);
                for(i = 0; p[i] != '\n' && i < strlen(p); i++);
                if(i == strlen(p)) while(getchar()!='\n');
                for(i = 0; i < strlen(p); i ++){
                    if(p[i] == '\r' || p[i] == '\n'){
                        p[i] = '\0';
                        break;
                    }
                }
                book.title = (char *) malloc(150);
                strcpy(book.title,p);

                printf("Enter the author of the book you wish to add:\n");
                fflush(stdin);
                fgets(p,50,stdin);
                for(i = 0; p[i] != '\n' && i < strlen(p); i++);
                if(i == strlen(p)) while(getchar()!='\n');
                for(i = 0; i < strlen(p); i ++){
                    if(p[i] == '\r' || p[i] == '\n'){
                        p[i] = '\0';
                        break;
                    }
                }
                book.authors = (char *) malloc(150);
                strcpy(book.authors,p);

                printf("Enter the year of the book you wish to add:\n");
                fflush(stdin);
                fgets(p,50,stdin);
                for(i = 0; p[i] != '\n' && i < strlen(p); i++);
                if(i == strlen(p)) while(getchar()!='\n');
                for(i = 0; i < strlen(p); i ++){
                    if(p[i] == '\r' || p[i] == '\n'){
                        p[i] = '\0';
                        break;
                    }
                }
                for (i = 0; i < strlen(p); ++i) {
                    if(p[i] < '0' || p[i] > '9'){
                        printf("This book does not exist in stock.\n");
                        printf("If you want to add it, please choose option 1,\n");
                        i = -1;
                        break;
                    }
                }
                if(i == -1) break;
                book.year = atoi(p);

                if(repeated(book.title,book.authors,book.year) == NULL){
                    printf("This book does not exist in stock.\n");
                    printf("If you want to add it, please choose option 1,\n");
                    free(add_1);
                    break;
                }

                while(1){
                    printf("Enter the copies of the book you wish to add:\n");
                    fflush(stdin);
                    fgets(p,50,stdin);
                    for(i = 0; p[i] != '\n' && i < strlen(p); i++);
                    if(i == strlen(p)) while(getchar()!='\n');
                    for(i = 0; i < strlen(p); i ++){
                        if(p[i] == '\r' || p[i] == '\n'){
                            p[i] = '\0';
                            break;
                        }
                    }
                    for (i = 0; i < strlen(p); ++i) {
                        if(p[i] < '0' || p[i] > '9'){
                            printf("\nWrong copies, please enter copies again which at least more than 1.\n\n");
                            i = -1;
                            break;
                        }
                    }
                    if(i == -1) continue;
                    a = atoi(p);
                    if(a > 0){
                        book.copies = a;
                        break;
                    } else{
                        printf("\nWrong copies, please enter copies again which at least more than 1.\n\n");
                    }
                }

                strcpy(add_1->title,book.title);
                strcpy(add_1->authors,book.authors);
                add_1->year = book.year;
                add_1->copies = book.copies;

                book_p4 = repeated(book.authors,book.title,book.year);
                book_p4->copies += book.copies;

                store_books(file);
                printf("\nYou have added the copies of this book successfully.\n");
                break;

            case '3':break;
            default:
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
    return 1;
}//Add new books and add books stock.

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
}//Remove books by ID

Librarian *Lib_load(){
    FILE *file;
    Librarian *q=NULL;
    Librarian *t = q;
    Librarian *p_lib;
    //int i;
    if((file = fopen("librarian.txt","r"))==NULL){
        file = fopen("librarian.txt","w+");
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
}//Load the librarian information to the linked list

void Lib_Manage(){
    char lib_1 = '1';
    while(lib_1 != '4'){
        while (1){
            lib_choice();
            int count = 0;
            scanf("%c",&lib_1);
            while(getchar()!='\n') count ++;
            if(count > 0){
                printf("\nSorry, the option you enter was invalid, please try again.\n\n");
                continue;
            }else{
                break;
            }
        }
        switch (lib_1) {
            case '1':Lib_Display(); break;
            case '2':Lib_return(); break;
            case '3':Lib_delete(); break;
            case '4': break;
            default:
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
}
void Lib_Display(){
    User *user = User_h->next;
    int i ,len_username = 8, len_ID = 2, len_pass = 8;
    if(!user){
        printf("\nSorry,no user has registered for the time being.\n");
        return;
    }
    while (user){
            if (strlen(user->user_name) > len_username) {
                len_username = strlen(user->user_name);
            }
            if (strlen(user->user_num) > len_ID) {
                len_ID = strlen(user->user_num);
            }
            if (strlen(user->user_pass) > len_pass) {
                len_pass = strlen(user->user_pass);
            }
        user = user->next;
    }
    printf("%-*s    ",len_username,"Username");
    printf("%-*s    ",len_ID,"ID");
    printf("%-*s    ",len_pass,"Password");
    printf("%s","Borrowed books number");
    printf("\n");
    User *user_1 = User_h->next;
    int cot = 0;
    while (user_1){
        for(i = 0; i < 10 ; i++){
            if(user_1->user_bor[i] != 0){
                cot++;
            }
        }
        printf("%-*s    %-*s    %-*s    %-4d\n",len_username,user_1->user_name, len_ID, user_1->user_num,len_pass, user_1->user_pass, cot);
        user_1 = user_1->next;
        cot = 0;
    }
}

User *exist_user(char *user_id){
    User *p = User_h->next;
    while (p){
        if(strcmp(p->user_num,user_id) == 0){
            break;
        }
        p = p->next;
    }
    return p;
}

void Lib_return(){
    int i;
    char id[20];
    Book *re;
    User *user_return;
    Lib_Display();
    printf("\nPlease enter the ID of the user you wish forcibly returned books:");
    fgets(id,25,stdin);
    for(i = 0; id[i] != '\n' && i < strlen(id); i++);
    if(i == strlen(id)) while(getchar()!='\n');
    for(i = 0; i < strlen(id); i ++){
        if(id[i] == '\r' || id[i] == '\n'){
            id[i] = '\0';
            break;
        }
    }
    user_return = exist_user(id);
    if(!user_return){
        printf("\nSorry,the student does not exist.\n");
        return;
    }
    int cot = 0;
    for (i = 0; i < 10; i++) {
        if(user_return->user_bor[i] != 0){
            cot++;
        }
    }
    if(cot == 0){
        printf("\nSorry, the student does not borrow any book.\n");
        return;
    }
    for(i = 0;i < 10; i++){
        if(user_return->user_bor[i] != 0){
            re = exist(user_return->user_bor[i]);
            re->copies++;
            user_return->user_bor[i] = 0;
        }
        if(strcmp(user_return->user_bor_book[i],"0") != 0){
            user_return->user_bor_book[i][0] = '0';
            user_return->user_bor_book[i][1] = '\0';
        }
    }
    user_save();
    book_save();
    printf("\nYou have forced book return successfully.\n");
}

void Lib_delete(){
    User *user_delete;
    User *head = User_h;
    Book *p;
    int i;
    char id_1[20];
    Lib_Display();
    printf("\nPlease enter the ID number of the student you wish to delete:");
    fgets(id_1,30,stdin);
    for(i = 0; id_1[i] != '\n' && i < strlen(id_1); i++);
    if(i == strlen(id_1)) while(getchar()!='\n');
    for(i = 0; i < strlen(id_1); i ++){
        if(id_1[i] == '\r' || id_1[i] == '\n'){
            id_1[i] = '\0';
            break;
        }
    }
    user_delete = exist_user(id_1);
    if(!user_delete){
        printf("\nSorry,the student does not exist.\n");
        return;
    }
    for(i = 0; i < 10; i ++){
        if(user_delete->user_bor[i] != 0){
            p = exist(user_delete->user_bor[i]);
            p->copies++;
        }
    }
    User *user_de = User_h->next;
    while (user_de){
        if(strcmp(id_1, user_de->user_num) == 0){
            head->next = user_de->next;
            free(user_de);
            break;
        }
        head = user_de;
        user_de = user_de->next;
    }
    user_save();
    book_save();
    printf("\nYou succeeded to delete this student.\n");
}