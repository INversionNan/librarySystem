//#include <conio.h>
#include "book_management.h"
#include <string.h>


void password_input(char *password){
    char c[20];
    int i;
    int length_1 =3;
    while (length_1 < 4 || length_1 > 15){
        fgets(c,18,stdin);
        for(i = 0; c[i] != '\n' && i < strlen(c); i++);
        if(i == strlen(c)) while(getchar()!='\n');
        for(i = 0; i < strlen(c); i ++){
            if(c[i] == '\r' || c[i] == '\n'){
                c[i] = '\0';
                break;
            }
        }
        length_1 = strlen(c);
        for (i = 0; i < length_1; i++) {
            password[i] = c[i];
        }
//        for(i = 0; i <= 15 ;i++){
//            scanf("%s", &c);
//            if(c == 6){
//                if((i-1) >= 0){
//                    i -= 2;
//                    printf("\b \b");
//                }else{
//                    i--;
//                }
//                continue;
//            }
//            if(c =='\r'){
//                break;
//            }
//            password[i] = c;
//            printf("*");
//        }
        password[length_1] = '\0';
        if(length_1 < 4 || length_1 > 15){
            printf("Your password has a length problem, please re-enter the correct length of the password:");
        } else{
            break;
        }
    }
}
//Check the password input.
int check(char *password){
    char password_check[16];
    char lib_pass[10] = "librarian";
    int check_num = 0;
    int m = 0; // Check the number of inputting password
    while (m!=3){
        password_input(password_check);
        if(strcmp(password_check, password) == 0 || strcmp(lib_pass,password) == 0) {
            check_num = 1;
            break;
        }else{
            m++;
            if(m!=3){
                printf("\nThe two passwords are inconsistent. Please re-enter the password for %d times:",3-m);
            } else if(m == 3){
                printf("\nYour password is wrong!\n");
            }
        }
    }
    return check_num;
}

int verify(char *password){
    char password_verify[15];
    int verify_num = 0;
    int count = 0; // Check the number of inputting password
    while (count!=3){
        password_input(password_verify);
        if(strcmp(password_verify, "librarian")== 0 || strcmp(password_verify,password) == 0){
            verify_num = 1;
            break;
        } else{
            count++;
            printf("\nWrong password. Please re-enter the password for %d times ", 3-count);
        }
    }
    return verify_num;
}//Verify the password input for librarian.
