//
// Created by 10526 on 2022/3/22.
//

#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

typedef struct stu{
    char stu_acc[10];				//学生账号
    char stu_pass[15];				//学生密码
    char stu_find_question[30];		//密保问题
    char stu_find_pass[15];		//密保问题密码
    char stu_num[10];				//学生学号
    char stu_name[20];				//学生姓名
    char stu_tel[15];				//学生电话
    char stu_bor_book[10][20];		//所借书号
    struct stu *next;				//下位学生
}Student;

typedef struct librarian{
    char lib_name[15];				//管理员姓名
    char lib_acc[10];				//管理员账号
    char lib_pass[15];				//管理员密码
    struct librarian *next;			//下个管理员
}Librarian;

Student *Stu_h;
Librarian *Lib_h;

void stu();
#endif //LIBRARY_USER_H
