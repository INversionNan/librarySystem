#include "book_management.h"
#include <stdlib.h>
//#include <conio.h>

#include <string.h>

User *repeat(char *a ,char *b){

    User *user_p1 = User_h->next;
    while (user_p1){
        if(strcmp(a, user_p1->user_name)==0 && strcmp(b, user_p1->user_num)==0){
            return user_p1;
        }
        user_p1 = user_p1->next;
    }
    return NULL;
}

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
        printf("Because you have entered wrong number for 3 times, exit the registration system.");
        free(new);
        return;
    }
    printf("\nRegistered library account successfully!\n\n");
    p = User_h;
    while (p->next){
        p = p->next;
    }
    p->next = new;
    //user_save();
}

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
}

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
            printf("Please enter your password:");
            login_user = Lib_h->next;
            if(verify(login_user->user_pass) == 0){
                printf("You have entered three errors in a row and will exit the program.\n\n");
                return;
            }

            char op_1 = 1;
            while(op_1 != '5'){
                while (1){
                    int count = 0;
                    li_choice();
                    printf("Option:");
                    scanf("%c", &op_1);
                    while(getchar()!='\n') count++;
                    if(count > 0){
                        printf("Wrong input, please re-enter again.\n");
                        continue;
                    }else{
                        break;
                    }
                }
                switch (op_1) {
                    case '1':
                        book.title = ' ';
                        book.authors = ' ';
                        book.year = ' ';
                        book.copies = ' ';
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
                    case '3':search();break;
                    case '4':display();break;
                    case '5':
                        printf("\nLogging out...\n\n");
                        return;
                    default:
                        printf("Wrong input, please re-enter again.\n");break;
                }
            }
        }
        else{
            printf("Please enter your password:");
            if(check(login_user->user_pass) == 0){
                printf("You have entered three errors in a row and will exit the program.\n\n");
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
                        printf("Wrong input, please re-enter again.\n");
                        continue;
                    }else{
                        break;
                    }
                }
                switch (op) {
                    case '1':borrow(login_user);break;
                    case '2':return_book(login_user);break;
                    case '3':search();break;
                    case '4':display();break;
                    case '5':
                        printf("\nLogging out...\n\n");
                        return;
                    default:
                        printf("Wrong input, please re-enter again.\n");break;
                }
            }
        }
    }
}

User *User_load(){
    FILE *file;
    User *h=NULL,*t = h,*p_stu;
    int i;
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
//        printf("%s\n",p_stu->user_name);
        fscanf(file, "%s", p_stu->user_num);
//        printf("%s\n",p_stu->user_num);
        fscanf(file, "%s", p_stu->user_pass);
//        printf("%s\n",p_stu->user_pass);
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


void display(){
    Book *p2 = Book_h->next;
    if(!p2){
        printf("\nThere are no books in the library at present.\n\n");
        return;
    }
    Book *p1 = Book_h->next;
    printf("%s\t","ID");
    printf("%s\t","Title");
    printf("%s\t","Authors");
    printf("%s\t","Year");
    printf("%s\t","Copies");
    printf("\n");
    while(p1 != NULL){
        printf("%d\t %s\t %s\t %d\t %d\n",p1->id, p1->title, p1->authors, p1->year, p1->copies);
        p1 = p1->next;
    }
}

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
}


void borrow(User *user_bo){
    int i;
    int numborrow;
    int cot = 0;
    Book *borrow;
    for(i = 0; i < 10; i++){
        if(strcmp(user_bo->user_bor_book[i],"0") != 0)
            cot++;
    }
    if(cot == 10){
        printf("You have borrowed ten books, which is the maximum.\n");
        printf("Please return the borrowed books first.\n\n");
        return;
    }
    display();
    printf("\n\nYou have already borrowed %d books, and you can borrow %d more books.\n",cot, 10-cot);
    printf("Please enter the ID number of the book you want to borrow:\n");
    scanf("%d",&numborrow);
    getchar();
    borrow = exist(numborrow);
    if(!borrow){
        printf("Sorry ,the library does not have this book.\n ");
        printf("You failed to borrow it.\n");
        return;
    }
    if(borrow->copies == 0){
        printf("Sorry, this book is out of stock.\n");
        printf("You failed to borrow it.\n");
        return;
    }
    char user_borrow = (char)numborrow;
    if(judge(user_bo,&user_borrow)){
        printf("Sorry, you have borrowed it before.\n");
        printf("Do not borrow it again.\n");
        printf("You failed to borrow it.\n");
        return;
    }

    for(i = 0; i < 10; i++){
        if(strcmp(user_bo->user_bor_book[i],"0") == 0){
            user_bo->user_bor_book[i][0] = '\0';
            strcat(user_bo->user_bor_book[i],&user_borrow);
            borrow->copies--;
            break;
        }
    }
    printf("You have borrowed it successfully!\n\n");
    book_save();
    user_save();
    User *user_borrow_1 = User_h->next;
        for (i = 0; i < 10; ++i) {
            printf("%d\n",user_borrow_1->user_num[i]);
        }
}

void display_borrow(){

    Book *p2 = Book_h->next;
    if(!p2){
        printf("\nThere are no books in the library at present.\n\n");
        return;
    }
    Book *p1 = Book_h->next;
    printf("%s\t","ID");
    printf("%s\t","Title");
    printf("%s\t","Authors");
    printf("%s\t","Year");
    printf("%s\t","Copies");
    printf("\n");
    while(p1 != NULL){
        printf("%d\t %s\t %s\t %d\t %d\n",p1->id, p1->title, p1->authors, p1->year, p1->copies);
        p1 = p1->next;
    }
}

void return_book(User *user_re){
//    display_borrow();
    int i;
    int num_return;
    int cot_1 = 0;
    int cot_2 = 0;
    Book *book_return;
    for(i = 0; i < 10; i++){
        if(strcmp(user_re->user_bor_book[i],"0") != 0)
            cot_1 = 1;
        break;
    }
    if(cot_1 == 0){
        printf("You should not return one book because no book are borrowed by you.\n");
        return;
    }
    printf("\nPlease enter the ID number of the book you want to return:\n");
    scanf("%d",&num_return);
    getchar();

    char num_re = (char) num_return;
    for(i = 0; i < 10 ; ++i){
        if(strcmp(user_re->user_bor_book[i], &num_re) == 0){
            cot_2 = 1;
            break;
        }
    }
    if(cot_2 == 0){
        printf("Sorry, you have not borrowed this book.[n");
        printf("Your enter is wrong.\n");
        return;
    }

    for(i = 0; i < 10; ++i){
        if(strcmp(user_re->user_bor_book[i], &num_re) == 0){
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
    printf("You have returned it successfully!\n\n");
    book_save();
}

BookList find_book_by_title (const char *title){
    int title_num = 0;
    Book *book_title = Book_h->next;
    while (1){
        if(!book_title){
            if(title_num == 0){
                printf("Sorry, there are no books which are called as this title in the library.\n\n");
                break;
            }
            break;
        }
        if(strcmp(title,book_title->title) == 0){
            if(title_num == 0){
                printf("%s\t","ID");
                printf("%s\t","Title");
                printf("%s\t","Authors");
                printf("%s\t","Year");
                printf("%s\t\n","Copies");
            }
            title_num ++;
            printf("%d\t",book_title->id);
            printf("%s\t",book_title->title);
            printf("%s\t",book_title->authors);
            printf("%d\t",book_title->year);
            printf("%d\t\n",book_title->copies);
        }
        book_title = book_title->next;
    }
}

BookList find_book_by_author (const char *author){
    int author_num = 0;
    Book *book_author = Book_h->next;
    while (1){
        if(!book_author){
            if(author_num == 0){
                printf("Sorry, there are no books which are called as this author(these authors) in the library.\n\n");
                break;
            }
            break;
        }
        if(strcmp(author,book_author->title) == 0){
            if(author_num == 0){
                printf("%s\t","ID");
                printf("%s\t","Title");
                printf("%s\t","Authors");
                printf("%s\t","Year");
                printf("%s\t\n","Copies");
            }
            author_num ++;
            printf("%d\t",book_author->id);
            printf("%s\t",book_author->title);
            printf("%s\t",book_author->authors);
            printf("%d\t",book_author->year);
            printf("%d\t\n",book_author->copies);
        }
        book_author = book_author->next;
    }
}

BookList find_book_by_year (unsigned int year){
    int year_num = 0;
    Book *book_year = Book_h->next;
    while (1){
        if(!book_year){
            if(year_num == 0){
                printf("Sorry, there are no books which are called as this title in the library.\n\n");
                break;
            }
            break;
        }
        if(book_year->year == year){
            if(year_num == 0){
                printf("%s\t","ID");
                printf("%s\t","Title");
                printf("%s\t","Authors");
                printf("%s\t","Year");
                printf("%s\t\n","Copies");
            }
            year_num ++;
            printf("%d\t",book_year->id);
            printf("%s\t",book_year->title);
            printf("%s\t",book_year->authors);
            printf("%d\t",book_year->year);
            printf("%d\t\n",book_year->copies);
        }
        book_year = book_year->next;
    }
}


void search(){
    Book *search = Book_h->next;
    char book_search = 1;
    char *search_title, *search_authors;
    int search_year;
    while (book_search != '4'){
        while (1){
            int count_2 = 0;
            search_choice();
            scanf("%c",&book_search);
            while (getchar()!='\n') count_2 ++;
            if(count_2 > 0){
                printf("Sorry, the option you enter was invalid, please try again.\n");
                continue;
            } else{
                break;
            }
        }
        switch (book_search) {
            case '1':
                search_title = (char *) malloc(sizeof (char));
                printf("Please enter the title you want to search:\n");
                gets(search_title);
                find_book_by_title(search_title);
                break;
            case '2':
                search_authors = (char *) malloc(sizeof (char));
                printf("Please enter the authors you want to search:\n");
                gets(search_authors);
                find_book_by_author(search_authors);
                break;
            case '3':
                printf("Please enter the title you want to search:\n");
                scanf("%d",&search_year);
                getchar();
                find_book_by_year(search_year);
                break;
            case '4':
                break;
            default:
                printf("Sorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
}