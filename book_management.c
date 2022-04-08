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
    getc(file);//If a character is read from a file, EOF is returned at the end of the file without data

    if(feof(file)){
        fclose(file);
        return NULL;
    }//Check end of file on stream (read end of file)

    rewind(file);//Redirects the position pointer inside a file to the beginning of a stream (data stream/file)
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
        }//Replace the underscore with a space
        fscanf(file,"%s",p->authors);
        for(j = 0; j < strlen(p->authors); j ++){
            if(p->authors[j] == '_'){
                p->authors[j] = ' ';
            }
        }//Replace the underscore with a space
        fscanf(file,"%d",&p->year);
        fscanf(file,"%d",&p->copies);
        if(h==NULL){
            h = p;
        }else{
            t->next=p;
        }
        t = p;
    }//Read file information line by line into the linked list until the end of the file
    fclose(file);
    return h;
}
int main(int argc, char ** argv) {
    char info[265];
    memset(info, '\0',sizeof info);
    char *book_file = NULL;
    char *user_file = NULL;
    int d = 1;
    int b = 1;
    int c = 0;
    while (d < argc){
        if(c == 0){
            if((strlen(argv[d])) > 259){
                printf("The maximum word length of the file name is exceeded.\n");
                break;
            }
            strcpy(info, argv[d]);
            c = 1;
        }else{
            if((strlen(info)+ strlen(argv[d]) + 2) > 259){
                printf("The maximum word length of the file name is exceeded.\n");
                break;
            }
            strcat(info," ");
            strcat(info, argv[d]);
        }
        if(strlen(info) < 4){
            d++;
            continue;
        }
        if(info[strlen(info) - 1] != 't' || info[strlen(info) - 2] != 'x'|| info[strlen(info) - 3] != 't' || info[strlen(info) - 4] != '.'){
            d++;
            continue;
        }else{
            if(b == 1){
                book_file = (char *) malloc(strlen(info)+1);
                strcpy(book_file, info);
                b++;
            } else if(b == 2){
                user_file = (char *) malloc(strlen(info)+1);
                strcpy(user_file, info);
                b++;
            }else if(b == 3){
                printf("This is an invalid input which has been ignored! \n");
                break;
            }
            memset(info, '\0',sizeof info);
            c = 0;
        }
        d++;
    }//Command line parameter operation initialize

    if(!book_file){
        printf("\nPlease enter a valid book filename which should end with .txt: ");
        while (1){
            fgets(info,265,stdin);
            int i;
            for(i = 0; i < strlen(info); i ++){
                if(info[i] == '\r' || info[i] == '\n'){
                    info[i] = '\0';
                    break;
                }
            }
            if(strlen(info) < 4){
                printf("\nPlease re-enter a valid book filename which should end with .txt: ");
                continue;
            }else if(info[strlen(info) - 1] == 't' && info[strlen(info) - 2] == 'x' && info[strlen(info) - 3] == 't' && info[strlen(info) - 4] == '.' ){
                book_file = (char *) malloc(strlen(info) + 1);
                strcpy(book_file,info);
                break;
            }else{
                printf("\nPlease re-enter a valid book filename which should end with .txt: ");
            }
        }
    }//Command line parameter operation on book file

    if(!user_file){
        printf("\nPlease enter a valid user filename which should end with .txt: ");
        while (1){
            fgets(info,265,stdin);
            int j;
            for(j = 0; j < strlen(info); j ++){
                if(info[j] == '\r' || info[j] == '\n'){
                    info[j] = '\0';
                    break;
                }
            }
            if(info[strlen(info) - 1] == 't' && info[strlen(info) - 2] == 'x' && info[strlen(info) - 3] == 't' && info[strlen(info) - 4] == '.'){
                user_file = (char *) malloc(strlen(info) + 1);
                strcpy(user_file, info);
                break;
            } else{
                printf("\nPlease re-enter a valid user filename which should end with .txt: ");
            }
        }
    }//Command line parameter operation on user file


    Book_h = (Book *)malloc(sizeof (Book));
    User_h = (User *) malloc(sizeof (User));
    Lib_h = (Librarian *) malloc(sizeof (Librarian));

    Book_h ->next = Book_load();
    User_h->next = User_load();
    Lib_h->next = Lib_load();
    //Get the head node
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