#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<conio.h>


typedef struct ques{
	char ques_num[10];
	char ques_name[20];
	char ques_content[100];
	char ques_ans_A[50];
	char ques_ans_B[50];
	char ques_ans_C[50];
	int ans_num_A[1];
	int ans_num_B[1];
	int ans_num_C[1];
	struct ques *next;
}Question;

typedef struct manager{
	char man_name[20];
	char man_num[10];
	char man_passw[15];
	struct manager *next;
}Manager;

typedef struct stu{
	char stu_num[10];
	char stu_passw[15];
	char stu_find_question[30];
	char stu_find_passw[15];
	char stu_name[20];
	char stu_tel[15];
	struct stu *next;
}Student;

Student *student_head;
Manager *manager_head;
Question *ques_head;

//管理员部分
void manager_port();
void manager_login();
Manager* check_manager(char* manager_num);

//屏幕显示部分
void main_screen();
void student_screen();
void manager_screen();
void student_console();
void manager_console();

//学生部分
void student_port();
void student_signup();
void student_login();
void find_password();
void stu_changepassw();
Student* find_num(char *enter_number);

//学生控制台部分
void student_console_screen();
int password_text_find(char *password);
int password_text(char *password);
void password_input(char *password);
void stu_changepassw(Student *enter_stu);

//加载部分
Student* student_load();
Manager* manager_load();
Question* ques_load();
void save_student();
void save_manager();
void save_ques();
void message_save();
void save_student1();
void save_ques1();


//问题部分
void add_question();
void find_question();
int print_question();
void delete_question();
void sort_question_by_num();
void choose_answer();
int print_question_final();
#endif // HEAD_H_INCLUDED
