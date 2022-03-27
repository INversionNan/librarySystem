#include "book_management.h"
#include <stdlib.h>
//#include <conio.h>

#include <string.h>


void reg(){
    int i;
    char password[15];
    User *p;
    User *new = (User *)malloc(sizeof (User));
    new->next = NULL;
//    printf("Please enter a username:");
    for(i = 0;i < 15; i++){
        new->user_bor_book[i][0] ='0';
        new->user_bor_book[i][1] ='\0';
    }
    printf("\nWelcome to the Register System\n\n");
    printf("Please enter a user name:");
    scanf("%s",new->user_name);
    if(strcmp(new->user_name,"librarian")== 0){
        printf("This is the administrator account that has been registered.\n");
        printf("Please change your name.\n\n");
        return;
    }
    printf("Please enter your ID number:");
    scanf("%s",new->user_num);
    getchar();
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
    user_save();
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
}

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
    Book book;
    char op_2;
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
                printf("You have entered three errors in a row and will exit the program.\n");
                return;
            }

            char op_1 = '1';
            while(op_1 != '0'){
                li_choice();
                printf("Option:");
                scanf("%c", &op_1);
                strcpy(op_2,op_1);
                while(getchar()!='\n');
                switch (op_1) {
                    case '1':
                        book.title = ' ';
                        book.authors = ' ';
                        book.year = ' ';
                        book.copies = ' ';
                        add_book(book);
                    case '2':remove_book(book);break;
                    case '3':search();break;
                    case '4':display();break;
                    case '5':return;
                    default:
                        printf("Wrong input, please re-enter again.\n");break;
                }
                if(op_1 !='1' && op_1 !='2'&& op_1 !='3'&& op_1 !='4'&& op_1 !='5' ){
                    break;
                }
            }
            if(op_2 !='1' && op_2 !='2'&& op_2 !='3'&& op_2 !='4'&& op_2 !='5' ){
                break;
            }
        }
        else{
            printf("Please enter your password:");
            if(check(login_user->user_pass) == 0){
                printf("You have entered three errors in a row and will exit the program.");
                return;
            }
            printf("\n(logged in %s)\n\n",login_name);
            char op = '1';
            while(op != '0'){
                user_choice();
                printf("Option:");
                scanf("%c", &op);
                strcpy(op_2,op);
                while(getchar()!='\n');
                switch (op) {
                    case '1':borrow(login_user);break;
                    case '2':return_book();
                    case '3':search();break;
                    case '4':display();break;
                    case '5':return;
                    default:
                        printf("Wrong input, please re-enter again.\n");break;
                }
                if(op !='1' && op !='2'&& op !='3'&& op !='4'&& op !='5' ){
                    break;
                }
            }
            if(op_2 !='1' && op_2 !='2'&& op_2 !='3'&& op_2 !='4'&& op_2 !='5' ){
                break;
            }
        }
    }
}

User *User_load(){
    FILE *file;
    User *h=NULL,*t = h,*p_stu;
    int i;
    if((file = fopen("user.txt","r"))==NULL){
        printf("Failed to open user file.\n");
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
//        fscanf(file, "%s", p_stu->user_acc);
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


void display(){
    Book *p2 = Book_h;
    if(!p2){
        printf("There are no books in the library at present.\n");
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
    printf("You have already borrowed %d books, and you can borrow %d more books.\n",cot, 10-cot);
    printf("Please enter the ID number of the book you want to borrow:\n");
    scanf("%c",&numborrow);
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
    }
//    if(){
//
//    }
    for(i = 0; i < 10; i++){
        if(strcmp(user_bo->user_bor_book[i],"0") == 0){

            user_bo->user_bor_book[i][0] = '\0';
            strcat(user_bo->user_bor_book[i],numborrow);
            borrow->copies--;
            break;
        }
    }
}

void return_book(){

}

BookList find_book_by_title (const char *title){
    int title_num = 0;
    Book *book_title = Book_h;
    while (1){
        if(!book_title){
            if(title_num == 0){
                printf("Sorry, there are no books which are called as this title in the library.\n\n");
                break;
            }
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
    Book *book_author = Book_h;
    while (1){
        if(!book_author){
            if(author_num == 0){
                printf("Sorry, there are no books which are called as this author(these authors) in the library.\n\n");
                break;
            }
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
    Book *book_year = Book_h;
    while (1){
        if(!book_year){
            if(year_num == 0){
                printf("Sorry, there are no books which are called as this title in the library.\n\n");
                break;
            }
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

}