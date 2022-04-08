#include "book_management.h"
#include <stdlib.h>
//#include <conio.h>

#include <string.h>

User *repeat(char *a,char *b){

    User *user_p1 = User_h->next;
    while (user_p1){
        if(strcmp(a, user_p1->user_name)==0 || strcmp(b, user_p1->user_num)==0){
            return user_p1;
        }
        user_p1 = user_p1->next;
    }
    return NULL;
}//Check the book repeated

void reg(){
    int i;
    char password[15];
    User *p;
    User *new = (User *)malloc(sizeof (User));
    new->next = NULL;
//    printf("Please enter a username:");
    for(i = 0;i < 10; i++){
        new->user_bor_book[i][0] ='0';
        new->user_bor_book[i][1] ='\0';
    }
    for(i = 0;i< 10 ; i++){
        new->user_bor[i] = 0;
    }
//    new->user_bor[9] = '\0';
    printf("\nWelcome to the Register System\n\n");
    printf("Please enter a user name:");
    gets(new->user_name);
//    scanf("%s",new->user_name);
    if(strcmp(new->user_name,"librarian")== 0){
        printf("\nThis is the administrator account that has been registered.\n");
        printf("Please change your name.\n\n");
        return;
    }
    printf("Please enter your ID number:");
    scanf("%s",new->user_num);
    getchar();
    if(repeat(new->user_name,new->user_num)){
        printf("\nThis account and ID have been used, please change your name or ID.\n");
        printf("The program will return to the main menu.\n\n");
        return;
    }
    printf("Please enter a password:");
    password_input(new->user_pass);
    printf("To verify your password, please enter it again:");
    if(check(new->user_pass) == 0){
        printf("\nBecause you have entered wrong number for 3 times, exit the registration system.");
        free(new);
        return;
    }
    printf("\nRegistered library account successfully!\n\n");
    p = User_h;
    while (p->next){
        p = p->next;
    }
    p->next = new;
    user_save();
}//Register a new user

User *compare_name(char *login){
    User *p=User_h->next;
    char lib[10] = "librarian";
    while (p){
        if(strcmp(p->user_name,login) == 0){
            break;
        }
        if(strcmp(lib,login) == 0){
            break;
        }
        p = p->next;
    }
    return p;
}// Verify that the username is correct.

Book *exist(int Book_id){
    Book *Book_p = Book_h->next;
    while (Book_p){
        if(Book_p->id == Book_id){
            break;
        }
        Book_p = Book_p->next;
    }
    return Book_p;
}//check the book whether exist  or not by its ID

Book *exist_title(char *Book_title, char *Book_author){
    Book *Book_q = Book_h->next;
    while (Book_q){
        if(strcmp(Book_title,Book_q->title) == 0 && strcmp(Book_author,Book_q->authors)==0){
            break;
        }
        Book_q = Book_q->next;
    }
    return Book_q;
}//check the book whether exist or not by title and author

void login(){
    Book book, book_1;
    int i;
    char *p_ID;
    char login_name[20];
    User *login_user;
    char lib[10] = "librarian";
    while(1){
        printf("\nPlease enter your name:");
        gets(login_name);
        login_user = compare_name(login_name);
        if(login_user == NULL && strcmp(lib , login_name) !=0 ){
            printf("\nSorry, it is a wrong username.\n");
        }
        else if(strcmp(lib, login_name) == 0){
            login_user = Lib_h->next;
            printf("Please enter your password:");
            if(verify(login_user->user_pass) == 0){
                printf("\nYou have entered three errors in a row and will exit the program.\n\n");
                return;
            }

            char op_1 = 1;
            while(op_1 != '6'){
                while (1){
                    int count = 0;
                    li_choice();
                    printf("Option:");
                    scanf("%c", &op_1);
                    while(getchar()!='\n') count++;
                    if(count > 0){
                        printf("\nWrong input, please re-enter again.\n");
                        continue;
                    }else{
                        break;
                    }
                }
                switch (op_1) {
                    case '1':
                        book.title = (char *) malloc(sizeof (book.title));
                        book.authors = (char *) malloc(sizeof (book.authors));
                        book.year = ' ';
                        book.copies = ' ';
                        book.id = 0;
                        add_book(book);
                        break;
                    case '2':
                        if(Book_h->next == NULL){
                            printf("\nThere are no boos in the library so you cannot remove any books.\n");
                            break;
                        }
                        display();
                        printf("Please enter the ID of the book which you wish to remove:");
                        p_ID = (char *) malloc(sizeof (char));
                        fflush(stdin);
                        gets(p_ID);
                        book_1.id = atoi(p_ID);
                        remove_book(book_1);
                        fflush(stdin);break;
                    case '3':
                        printf("\nLoading search menu...\n\n");
                        search();break;
                    case '4':display();break;
                    case '5':Lib_Manage();break;
                    case '6':
                        printf("\nLogging out...\n");
                        return;
                    default:
                        printf("\nWrong input, please re-enter again.\n");break;
                }
            }
        }
        else{
            printf("Please enter your password:");
            if(verify(login_user->user_pass) == 0){
                printf("\nYou have entered three errors in a row and will exit the program.\n\n");
                return;
            }
            printf("\n(logged in %s)\n\n",login_name);
            char op = '1';
            while(op != '5'){
                while (1){
                    int count_1 = 0;
                    user_choice();
                    printf("Option:");
                    scanf("%c", &op);
                    while(getchar()!='\n') count_1++;
                    if(count_1 > 0){
                        printf("\nWrong input, please re-enter again.\n");
                        continue;
                    }else{
                        break;
                    }
                }
                switch (op) {
                    case '1':borrow(login_user);break;
                    case '2':return_book(login_user);break;
                    case '3':
                        printf("\nLoading search menu...\n\n");
                        search();break;
                    case '4':display();break;
                    case '5':
                        printf("\nLogging out...\n");
                        return;
                    default:
                        printf("\nWrong input, please re-enter again.\n");break;
                }
            }
        }
    }
}//Log option menu for librarian and users

User *User_load(){
    FILE *file;
    User *h=NULL,*t = h,*p_stu;
    int i ,j;
    if((file = fopen("user.txt","r"))==NULL){
        file = fopen("user.txt","w+");
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
        fscanf(file, "%s", p_stu->user_name);
        fscanf(file, "%s", p_stu->user_num);
        fscanf(file, "%s", p_stu->user_pass);
        for(j = 0; j < 10 ; ++j){
            fscanf(file, "%d", &p_stu->user_bor[j]);
        }
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
}//Load the user information to the linked list


void display(){
    Book *p2 = Book_h->next;
    int a, len, ID_len = 2, title_len = 5, authors_len = 7;
    if(!p2){
        printf("\nThere are no books in the library at present.\n");
        return;
    }
    Book *p3 = Book_h->next;
    while(p3){
        len = 0;
        a = p3->id;
        while (a > 0){
            a /= 10;
            len++;
        }
        if(len > ID_len){
            ID_len = len;
        }
        if(strlen(p3->title) > title_len){
            title_len = strlen(p3->title);
        }
        if(strlen(p3->authors) > authors_len){
            authors_len = strlen(p3->authors);
        }
        p3 = p3->next;
    }
    Book *p1 = Book_h->next;
    printf("%-*s    ",ID_len,"ID");
    printf("%-*s    ",title_len,"Title");
    printf("%-*s    ",authors_len,"Authors");
    printf("%s    ","Year");
    printf("%s","Copies");
    printf("\n");
    while(p1 != NULL){
        printf("%-*d    %-*s    %-*s    %-4d    %d\n",ID_len,p1->id, title_len,p1->title,authors_len, p1->authors, p1->year, p1->copies);
        p1 = p1->next;
    }
}//display all books

int judge(User *user_bo, char *Book_borrow){
    int judge_count = 0;
    int i;
    for (i = 0; i < 10; ++i) {
        if(strcmp(user_bo->user_bor_book[i],Book_borrow)==0){
            judge_count = 1;
            return judge_count;
        }
    }
    return judge_count;
}//judge the user's borrow book in user list

int find_title(char *title,char *author){
    int id_num;
    Book *book_find = Book_h->next;
    while (book_find){
        if(strcmp(title,book_find->title) == 0 && strcmp(author,book_find->authors) == 0){
            id_num = book_find->id;
        }
        book_find = book_find->next;
    }
    return id_num;
}//judge the borrow book's title and author in book list
int judge_Id(User *user_bo, int Book_borrowId){
    int judge_count = 0;
    int i;
    for (i = 0; i < 10; ++i) {
        if(user_bo->user_bor[i] == Book_borrowId){
            judge_count = 1;
            return judge_count;
        }
    }
    return judge_count;
}// judge the borrow book's ID in book list


void borrow(User *user_bo){
    int i;
    int numborrow;
    char *borrow_title, *borrow_author;
    int cot = 0;
    Book *borrow;
    char borrow_option = '1';
    while(borrow_option != '3'){
//        for(i = 0; i < 10; i++){
//            if(strcmp(user_bo->user_bor_book[i],"0") != 0)
//                cot++;
//        }
        for(i = 0; i < 10 ; i++){
            if(user_bo->user_bor[i] != 0){
                cot++;
            }
        }//calculate the number of borrowed book
        if(cot == 10){
            printf("\nYou have borrowed ten books, which is the maximum.\n");
            printf("Please return the borrowed books first.\n\n");
            return;
        }
        while(1){
            borrow_choice();
            int count_4 = 0;
            scanf("%c",&borrow_option);
            while(getchar()!='\n') count_4 ++;
            if(count_4 > 0){
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                continue;
            }else{
                break;
            }
        }
        borrow_title = (char *) malloc(sizeof (borrow_title));
        borrow_author = (char *) malloc(sizeof (borrow_author));
        switch (borrow_option) {
            case '1':
                display();
                printf("\n\nYou have already borrowed %d books, and you can borrow %d more books.\n",cot, 10-cot);
                printf("Please enter the ID number of the book you want to borrow:\n");
                fflush(stdin);
                while(1){
                    int count_5 = 0;
                    scanf("%d",&numborrow);
                    while(getchar()!='\n') count_5 ++;
                    if(count_5 > 3){
                        printf("\nSorry, the option you enter was invalid, please try again.\n");
                        continue;
                    }else{
                        break;
                    }
                }
                borrow = exist(numborrow);
                if(!borrow){
                    printf("\nSorry ,the library does not have this book.\n");
                    printf("You failed to borrow it.\n");
                    break;
                }
                if(borrow->copies == 0){
                    printf("\nSorry, this book is out of stock.\n");
                    printf("You failed to borrow it.\n");
                    break;
                }
                if(judge_Id(user_bo,numborrow)){
                    printf("\nSorry, you have borrowed it before.\n");
                    printf("Do not borrow it again.\n");
                    printf("You failed to borrow it.\n\n");
                    break;
                }
                for(i = 0; i < 10; i++){
                    if(user_bo->user_bor[i]== 0){
                        user_bo->user_bor[i] = numborrow;
                        borrow->copies--;
                        break;
                    }
                }
                printf("\nYou have borrowed it successfully!\n");
                book_save();
                user_save();
                cot = 0;
               break;
            case '2':
                display();
                printf("\n\nYou have already borrowed %d books, and you can borrow %d more books.\n",cot, 10-cot);
                printf("Please enter the title of the book you want to borrow:\n");
                fflush(stdin);
                gets(borrow_title);
                printf("Please enter the authors of the book you want to borrow:\n");
                fflush(stdin);
                gets(borrow_author);
                borrow = exist_title(borrow_title,borrow_author);
                if(!borrow){
                    printf("\nSorry ,the library does not have this book.\n ");
                    printf("You failed to borrow it.\n");
                    free(borrow_title);
                    break;
                }
                if(borrow->copies == 0){
                    printf("\nSorry, this book is out of stock.\n");
                    printf("You failed to borrow it.\n");
                    free(borrow_title);
                    break;
                }
                int id_num = find_title(borrow_title,borrow_author);
                strcat(borrow_title,borrow_author);
                int n;
                for(n = 0; n < strlen(borrow_title);n++){
                    if(borrow_title[n] == ' '){
                        borrow_title[n] = '_';
                    }
                }
                if(judge(user_bo,borrow_title) || judge_Id(user_bo,id_num)){
                    printf("\nSorry, you have borrowed it before.\n");
                    printf("Do not borrow it again.\n");
                    printf("You failed to borrow it.\n\n");
                    free(borrow_title);
                    break;
                }
                int j;
                for(i = 0; i < 10; i++){
                    if(strcmp(user_bo->user_bor_book[i],"0") == 0){
                        user_bo->user_bor_book[i][0] = '\0';
                        strcat(user_bo->user_bor_book[i],borrow_title);
                        for(j = i ; j < 10; j++){
                            if(user_bo->user_bor[j] == 0){
                                user_bo->user_bor[j] = borrow->id;
                                break;
                            }
                        }
                        borrow->copies--;
                        break;
                    }
                }
                printf("\nYou have borrowed it successfully!\n");
                book_save();
                user_save();
                cot = 0;
                break;
            case '3':break;
            default:
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
}//Borrow books by ID or Title and authors

void display_borrow(User *user_re){
    int i;
    int a, len, ID_len = 2, title_len = 5, authors_len = 7;
    Book *p4 = Book_h->next;
    while (p4){
        for(i = 0 ; i < 10 ;i ++){
            if(user_re->user_bor[i] == p4->id){
                len = 0;
                a = p4->id;
                while (a > 0){
                    a /= 10;
                    len++;
                }
                if(len > ID_len){
                    ID_len = len;
                }
                if(strlen(p4->title) > title_len){
                    title_len = strlen(p4->title);
                }
                if(strlen(p4->authors) > authors_len){
                    authors_len = strlen(p4->authors);
                }
            }
        }
        p4 = p4->next;
    }
    Book *p3 = Book_h->next;
    printf("%-*s    ",ID_len,"ID");
    printf("%-*s    ",title_len,"Title");
    printf("%-*s    ",authors_len,"Authors");
    printf("%s    ","Year");
    printf("%s","Copies");
    printf("\n");
    while (p3 != NULL){
        for(i = 0; i < 10; i++){
            if(user_re->user_bor[i] == p3->id){
                printf("%-*d    %-*s    %-*s    %-4d    %d\n",ID_len,p3->id, title_len,p3->title,authors_len, p3->authors, p3->year, p3->copies);
            }
        }
        p3 = p3->next;
    }
}//display borrowed books

void return_book(User *user_re){
    int i;
    int num_return;
    int cot_1 = 0;
    int cot_2 = 0;
    Book *book_return;
    for(i = 0; i < 10 ; i++){
        if(user_re->user_bor[i] != 0)
            cot_1 = 1;
        break;
    }
    for(i = 0; i < 10; i++){
        if(strcmp(user_re->user_bor_book[i],"0") != 0)
            cot_1 = 1;
        break;
    }
    if(cot_1 == 0){
        printf("\nYou should not return one book because no book are borrowed by you.\n\n");
        return;
    }
    display_borrow(user_re);
    printf("\nPlease enter the ID number of the book you want to return:\n");
    while(1){
        int count_6 = 0;
        scanf("%d",&num_return);
        while(getchar()!='\n') count_6 ++;
        if(count_6 > 3){
            printf("\nSorry, the option you enter was invalid, please try again.\n");
            continue;
        }else{
            break;
        }
    }
    for(i = 0; i < 10 ; ++i){
        if(user_re->user_bor[i] == num_return){
            cot_2 = 1;
            break;
        }
    }
    if(cot_2 == 0){
        printf("\nSorry, you have not borrowed this book.\n");
        printf("Your enter is wrong.\n");
        return;
    }

    for(i = 0; i < 10; ++i){
        if(user_re->user_bor_book[i], num_return){
            user_re->user_bor[i] = 0;
            user_re->user_bor_book[i][0] = '0';
            user_re->user_bor_book[i][1] = '\0';
            break;
        }
    }
    book_return = Book_h->next;
    while (book_return){
        if(num_return == book_return->id){
            break;
        }
        book_return = book_return->next;
    }
    book_return->copies++;
    printf("\nYou have returned it successfully!\n\n");
    book_save();
}

BookList find_book_by_title (const char *title){
    BookList list_title;
    int title_num = 0;
    int a, len, ID_len = 2, title_len = 5, authors_len = 7;;
    Book *p5 = Book_h->next;
    while (p5) {
            len = 0;
            a = p5->id;
            while (a > 0) {
                a /= 10;
                len++;
            }
            if (len > ID_len) {
                ID_len = len;
            }
            if (strlen(p5->title) > title_len) {
                title_len = strlen(p5->title);
            }
            if (strlen(p5->authors) > authors_len) {
                authors_len = strlen(p5->authors);
            }
        p5 = p5->next;
    }
    Book *book_title = Book_h->next;
    while (1){
        if(!book_title){
            if(title_num == 0){
                printf("\nSorry, there are no books which are called as this title in the library.\n\n");
                break;
            }
            break;
        }
        if(strcmp(title,book_title->title) == 0){
            if(title_num == 0){
                printf("%-*s    ",ID_len,"ID");
                printf("%-*s    ",title_len,"Title");
                printf("%-*s    ",authors_len,"Authors");
                printf("%s    ","Year");
                printf("%s","Copies");
                printf("\n");
            }
            title_num ++;
            printf("%-*d    ",ID_len,book_title->id);
            printf("%-*s    ",title_len,book_title->title);
            printf("%-*s    ",authors_len,book_title->authors);
            printf("%-4d    ",book_title->year);
            printf("%d    \n",book_title->copies);
        }
        book_title = book_title->next;
    }
    list_title.length = title_num;
    return list_title;
}

BookList find_book_by_author (const char *author){
    BookList list_author;
    int author_num = 0;
    int a, len, ID_len = 2, title_len = 5, authors_len = 7;;
    Book *p6 = Book_h->next;
    while (p6) {
            len = 0;
            a = p6->id;
            while (a > 0) {
                a /= 10;
                len++;
            }
            if (len > ID_len) {
                ID_len = len;
            }
            if (strlen(p6->title) > title_len) {
                title_len = strlen(p6->title);
            }
            if (strlen(p6->authors) > authors_len) {
                authors_len = strlen(p6->authors);
            }
        p6 = p6->next;
    }
    Book *book_author = Book_h->next;
    while (1){
        if(!book_author){
            if(author_num == 0){
                printf("\nSorry, there are no books which are called as this author(these authors) in the library.\n\n");
                break;
            }
            break;
        }
        if(strcmp(author,book_author->authors) == 0){
            if(author_num == 0){
                printf("%-*s    ",ID_len,"ID");
                printf("%-*s    ",title_len,"Title");
                printf("%-*s    ",authors_len,"Authors");
                printf("%s    ","Year");
                printf("%s","Copies");
                printf("\n");
            }
            author_num ++;
            printf("%-*d    ",ID_len,book_author->id);
            printf("%-*s    ",title_len,book_author->title);
            printf("%-*s    ",authors_len,book_author->authors);
            printf("%-4d    ",book_author->year);
            printf("%d    \n",book_author->copies);
        }
        book_author = book_author->next;
    }
    list_author.length = author_num;
    return list_author;
}

BookList find_book_by_year (unsigned int year){
    BookList list_year;
    int year_num = 0;
    int a, len, ID_len = 2, title_len = 5, authors_len = 7;;
    Book *p7 = Book_h->next;
    while (p7) {
            len = 0;
            a = p7->id;
            while (a > 0) {
                a /= 10;
                len++;
            }
            if (len > ID_len) {
                ID_len = len;
            }
            if (strlen(p7->title) > title_len) {
                title_len = strlen(p7->title);
            }
            if (strlen(p7->authors) > authors_len) {
                authors_len = strlen(p7->authors);
            }
        p7 = p7->next;
    }
    Book *book_year = Book_h->next;
    while (1){
        if(!book_year){
            if(year_num == 0){
                printf("\nSorry, there are no books which are called as this year in the library.\n\n");
                break;
            }
            break;
        }
        if(book_year->year == year){
            if(year_num == 0){
                printf("%-*s    ",ID_len,"ID");
                printf("%-*s    ",title_len,"Title");
                printf("%-*s    ",authors_len,"Authors");
                printf("%s    ","Year");
                printf("%s","Copies");
                printf("\n");
            }
            year_num ++;
            printf("%-*d    ",ID_len,book_year->id);
            printf("%-*s    ",title_len,book_year->title);
            printf("%-*s    ",authors_len,book_year->authors);
            printf("%-4d    ",book_year->year);
            printf("%d    \n",book_year->copies);
        }
        book_year = book_year->next;
    }
    list_year.length = year_num;
    return list_year;
}


void search(){
    char book_search = 1;
    char *search_title, *search_authors, *search_years;
    int search_year;
    while (book_search != '4'){
        while (1){
            int count_2 = 0;
            search_choice();
            scanf("%c",&book_search);
            while (getchar()!='\n') count_2 ++;
            if(count_2 > 0){
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                continue;
            } else{
                break;
            }
        }
        switch (book_search) {
            case '1':
                search_title = (char *) malloc(300*sizeof (char));
                printf("Please enter the title you want to search:\n");
                gets(search_title);
                find_book_by_title(search_title);
                break;
            case '2':
                search_authors = (char *) malloc(300*sizeof (char));
                printf("Please enter the authors you want to search:\n");
                gets(search_authors);
                find_book_by_author(search_authors);
                break;
            case '3':
                search_years = (char *) malloc(sizeof (char));
                printf("Please enter the year you want to search:\n");
                gets(search_years);
                search_year = atoi(search_years);
                find_book_by_year(search_year);
                break;
            case '4':
                break;
            default:
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
}// search option menu