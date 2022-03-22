#include <stdio.h>
#include <stdlib.h>

#include "book_management.h"
#include "user.h"
#include "interface.h"

int main() {
    Book_h = (Book *)malloc(sizeof (Book));
    Stu_h = (Student *) malloc(sizeof (Student));
    Lib_h = (Librarian *) malloc(sizeof (Librarian));

    char a = '1';
    while(a != 0){
        welcome();
        scanf("%c",&a);
        while(getchar()!='\n');
        switch (a) {
            case '1':Stu
        }
    }
    return 0;
}
