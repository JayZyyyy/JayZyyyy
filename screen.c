#include"head.h"
//<time.h>中的tm结构体的说明
/*struct tm{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};*/
//显示主界面
void main_screen(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);


	printf("\n\n############################################");
	printf(" ");
	printf("\n               欢迎使用问卷调查程序          ");
	printf(" ");
	printf("\n");
	printf("\n       时间：%4d年%2d月%2d日 %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n1->学生入口");
	printf("\n2->管理员入口");
	printf("\n0->Exit");
	printf("\n\n");
	printf("\n#############################################\n");

}

//显示用户界面
void student_screen(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                亲爱的用户 ");
	printf("\n##############################################");
	printf(" ");
	printf("\n               欢迎使用问卷调查程序          ");
	printf(" ");
	printf("\n");
	printf("\n       时间：%4d年%2d月%2d日 %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n1->登陆");
	printf("\n2->注册");
	printf("\n3->忘记密码");
	printf("\n0->返回");
	printf("\n#############################################\n");
}

//显示学生控制台
void student_console(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                亲爱的用户 ");
	printf("\n##############################################");
	printf(" ");
	printf("\n               欢迎使用问卷调查程序          ");
	printf(" ");
	printf("\n");
	printf("\n       时间：%4d年%2d月%2d日 %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n");
	printf("\n1->添加问题");
	printf("\n2->查找问题");
	printf("\n3->按顺序查看问题");
	printf("\n4->回答问题");
	printf("\n5->修改密码");
	printf("\n0->back");
	printf("\n#############################################\n");
}

//显示管理员界面
void manager_screen(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                尊敬的管理员 ");
	printf("\n##############################################");
	printf(" ");
	printf("\n               欢迎使用问卷调查程序          ");
	printf(" ");
	printf("\n");
	printf("\n       时间：%4d年%2d月%2d日 %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n");
	printf("\n1->登陆");
	printf("\n0->返回");
	printf("\n#############################################\n");
}

//显示管理员控制台
void manager_console(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                尊敬的管理员");
	printf("\n##############################################");
	printf(" ");
	printf("\n               欢迎使用问卷调查程序          ");
	printf(" ");
	printf("\n");
	printf("\n       时间：%4d年%2d月%2d日 %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n");
	printf("\n1->按顺序查看问题");
	printf("\n2->添加问题");
	printf("\n3->删除问题");
	printf("\n4->查看问卷及结果");
	printf("\n0->back");
	printf("\n#############################################\n");
}

//打印问卷
int print_question(){
	int result=0;
	Question *t=ques_head->next;
	if(t==NULL){
		printf("\n\t\t抱歉，暂无问卷");
		return result;
	}
	printf("\n**********************************************");
	printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,"编号","问题名字","问题内容","A选项","B选项","C选项");
	while(t){
		printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,t->ques_num,t->ques_name,t->ques_content
		,t->ques_ans_A,t->ques_ans_B,t->ques_ans_C);
		t=t->next;
	}
	printf("\n**********************************************");
	return 1;
}

//打印问卷结果
int print_question_final(Question *t){
	int result=0;
	//Question *t=ques_head->next;
	if(t==NULL){
		printf("\n\t\t抱歉，暂无问卷");
		return result;
	}
	printf("\n**********************************************");
    printf("\n\t\t有%d选择A",t->ans_num_A[0]);
    printf("\n\t\t有%d选择B",t->ans_num_B[0]);
    printf("\n\t\t有%d选择C",t->ans_num_C[0]);
	printf("\n**********************************************");
	return 1;
}

