#include"head.h"

void student_port(){
	int sp=2;
	while(sp!=0){
		student_screen();

		scanf("%d",&sp);

		while(getchar()!='\n');

		switch(sp){
			case 1:
				student_login();
				break;
			case 2:
				student_signup();
				break;
			case 3:
				find_password();
				break;
			case 0:
				sp=0;
				break;
			default:
				printf("\nplease input again");
				Sleep(1500);
				break;
		}
	}
}

//登陆函数
void student_login(){
	int s1=1;
	char enter_num[50];
	//char enter_passw[20];
	int l=1;
	Student *enter_stu;

	while(l!=6){
		printf("\n请输入账号：");
		scanf("%s",enter_num);
		while(getchar()!='\n');
		l= strlen(enter_num);
		if(l!=6){
			printf("\n输入长度有误,请重新输入");
		}
	}

	enter_stu=find_num(enter_num);

	if(enter_stu==NULL){
		printf("\n此账号不存在");
		Sleep(300);
		return;
	}else{
		printf("\n请输入密码:");
	}
	//printf("\n%s",temp_stu->stu_passw);
	if(password_text_find(enter_stu->stu_passw)==0){
		printf("\n您已连续输入错误三次，即将退出系统");
		return;
	}
	printf("\n正在登陆...");
	Sleep(500);
	printf("\n登陆成功!");
	Sleep(500);

//student_console()
	while(s1){
		student_console();
		printf(" ");
		scanf("%d",&s1);
		fflush(stdin);
		switch(s1){
			case 1:
				add_question(enter_stu);
				break;
			case 2:
				find_question(enter_stu);
				break;
			case 3:
				sort_question_by_num(enter_stu);
				break;
			case 4:
				choose_answer(enter_stu);
				break;
			case 5:
				stu_changepassw(enter_stu);
				break;
			case 0:
				break;
			default :
				printf("输入有误，请重新输入：");
				Sleep(3000);
				break;
		}
	}
}

//账号注册
void student_signup(){
	printf("\n2");
	Student *h;
	Student *p=(Student*)malloc(sizeof(Student));
	p->next=NULL;
	printf("\n\t\t欢迎来到注册系统！\n");
	Sleep(500);
	printf("\t\t正在加载···\n");
	Sleep(500);
	printf("\t\t请输入以下信息\n");
	printf("\t\t学号(6位)：");
	scanf("%s",p->stu_num);

	while(find_num(p->stu_num)){
		printf("\t\t该账号已被注册，请重新输入：");
		scanf("%s",p->stu_num) ;
	}

	printf("\t\t姓名：");
	scanf("%s",p->stu_name);
	printf("\t\t电话：");
	scanf("%s",p->stu_tel);
	printf("\t\t密码：");
	password_input(p->stu_passw);
	printf("\t\t请再次输入密码：");

	if(password_text(p->stu_passw)==0){
		printf("\n\t\t已经连续三次输入错误，将退出注册系统...");
		free(p);
		return;
	}
	printf("\n\n\t\t密保问题用于找回密码\n");
	printf("\t\t如：\n");
	printf("\t\t    我母亲的生日是？\n");
	printf("\t\t    我父亲的生日是？\n");
	printf("\t\t    我的生日是？\n");
	printf("\n\t\t密保问题：");
	scanf("%s",p->stu_find_question);
	printf("\t\t密保问题密码：");
	password_input(p->stu_find_passw);
	printf("\t\t请再次输入密保密码：");
	if(password_text(p->stu_find_passw)==0){
		printf("\n\t\t您已经连续输入错误三次，将退出注册系统...");
		free(p);
		return;
	}
	printf("\n正在注册...");
	printf("\n注册成功!");
	printf("\n\t\t您的账号是：%s",p->stu_num);
	printf("\n\t\t请牢记您的密码");
    save_student1(*p);
	h=student_head;
	while(h->next){
		h=h->next;
	}
	h->next=p;
	printf("\n\n\t按任意键退出");
	getch();

}

//通过密保找回密码
void find_password(){
	Student *find_temp;
	char num_temp[50];
	//char password_find[20];
	printf("\n\t\t欢迎来到找回密码系统：");
	int l=1;
	while(l!=6){
		printf("\n\t\t请输入六位账号：");
		gets(num_temp);
		l=strlen(num_temp);
		if(l!=6){
			printf("\n\t\t输入的账号长度有误，请重新输入");
		}
	}
	num_temp[6]='\0';
	find_temp=find_num(num_temp);
	if(find_temp==NULL){
		printf("\n\t\t抱歉，无此账号");
		printf("\n\t\t即将退出登陆系统...");
		Sleep(3000);
		return;
	}
	printf("\n\t\t%s,你好",find_temp->stu_name);
	printf("\n\t\t您设置的密保问题是：%s",find_temp->stu_find_question);
	printf("\t\n\n请输入您的密保密码：");
	if(password_text_find(find_temp->stu_find_passw)==0){
		printf("\t\n\n您已经连续输入错误三次，即将退出找回密码系统...");
		return;
	}
	printf("\n\t\t正在查找...");
	printf("\t\n\n您好，您的密码是：%s",find_temp->stu_passw);
	printf("\n\t\t请牢记您的密码");
	printf("\n\t\t按任意键退出");
	getch();
}

//密码输入函数
void password_input(char *password){
	char ch;
	int i;
	for(i=0;i<20;i++){
		ch=getch();
		if(ch==8){
			if((i-1)>=0){
				i-=2;
				printf("\b \b");
			}else{
				i-=1;
			}
			continue;
		}else if(ch=='\r'){
			break;
		}
		password[i]=ch;
		printf("*");
	}
	password[i]='\0';
}

//修改密码
void stu_changepassw(Student *enter_stu){
	char password_temp[20];
	printf("\n\t\t加载中");
	printf("...");
	printf("\n\t\t请输入原密码:");
	if(password_text_find(enter_stu->stu_passw)==0){
		printf("\n\t\t已经错误输入密码三次,浆退出修改密码系统");
		return;
	}
	printf("\n\t\t请输入新密码:");
	password_input(password_temp);
	printf("\n\t\t请再次输入新密码:");
	if(password_text_find(password_temp)==0){
		printf("\n\t\t已经输入错误密码三次,将退出修改密码系统...");
		return;
	}
	enter_stu->stu_passw[0]='\0';
	printf("\n\t\t请稍等,正在修改");
	Sleep(500);
	printf("...");
		strcat(enter_stu->stu_passw,password_temp);
	Sleep(500);
	printf("\n\t\t修改成功");
	printf("\n\t\t按任意键退出");
	getch() ;
}

//账号寻址函数，
Student* find_num(char *student_num){

	Student *t=student_head;
	while(t){
		if(strcmp(t->stu_num,student_num)==0){
			break;
		}else{
			t=t->next;
		}
	}
	return t;

}

//检测注册密码
int password_text(char *password){
	char temp_password[20];
	int temp=0;
	int n=0;

	while(n!=3){
		password_input(temp_password);
		if(strcmp(temp_password,password)==0){
			temp=1;
			break;
		}else{
			printf("\n输入错误,您还有%d次机会",2-n);
			n++;
		}
	}

	return temp;
}

//验证登陆密码
int password_text_find(char *password){
	int temp=0;
	int n=0;
	char temp_password[20];

	while(n!=3){
		fflush(stdin);
		password_input(temp_password);
		if(strcmp(temp_password,password)==0){
			temp=1;
			break;
		}else{
			printf("\n密码错误，你还有%d次机会",2-n);
			n++;
		}

	}

	return temp;
}

//上传问卷
void add_question(){
	printf("\n\t\t请输入以下信息：");
	Question *p=(Question*)malloc(sizeof(Question));
	p->next=NULL;
	Question *h=ques_head;


	printf("\n\t\t问卷编号：");
	gets(p->ques_num);
	printf("\t\t问题名称：");
	gets(p->ques_name);
	printf("\t\t问题内容：");
	gets(p->ques_content);
	printf("\t\t问题选项A：");
	gets(p->ques_ans_A);
	printf("\t\t问题选项B：");
	gets(p->ques_ans_B);
	printf("\t\t问题选项C：");
	gets(p->ques_ans_C);
	printf("\t\t目前选择A的人数：");
	gets(p->ans_num_A);
	printf("\t\t目前选择B的人数：");
	gets(p->ans_num_B);
	printf("\t\t目前选择C的人数：");
	gets(p->ans_num_C);
	save_ques1(*p);
	while(h->next){
		h=h->next;
	}
	h->next=p;
	printf("按任意键退出");
	getch();
}



//查找问题
void find_question(){
	Question *t=ques_head->next;
	char ques_na[20];
	if(t==NULL){
		printf("\n\t\t抱歉，暂无问卷");
		printf("\n\t\t按任意键退出");
		getch();
		return;
	}
	printf("\n\t\t请输入需要查找的问题:");
	gets(ques_na);
	fflush(stdin);
	while(t!=NULL){
		if(strcmp(ques_na,t->ques_name)==0){
			break;
		}
		t=t->next;
	}
	if(t==NULL){
		printf("\n\t\t抱歉,无此问题");
		printf("\n\t\t按任意键退出");
		getch();
		return;
	}
	printf("\n\t\t加载中");
	printf("...");
	printf("\n**********************************************");
	printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,"编号","问题名称","内容","选项A","选项B","选项C");
	printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,t->ques_num,t->ques_name,t->ques_content
		,t->ques_ans_A,t->ques_ans_B,t->ques_ans_C);
	printf("\n**********************************************");
	printf("\n\t\t按任意键退出");
	getch();

}

//查看问题并回答问题
void choose_answer(){
    Question *t=ques_head->next;
    char a[20];
    char ch;
    int b=1;
	if(ques_head->next==NULL){
		printf("\n\t\t暂无问题");
		printf("\n\t\t按任意键退出");
        getch();

	}
	if(ques_head->next->next==NULL){
		print_question();
		printf("\n\t\t暂无问题");
		printf("\n\t\t按任意键退出");
        getch();
	}
	Question *p1,*p2,*p3;
	Question *head=ques_head;
	Question *end=NULL;
	while(head->next!=end){
		for(p1=head,p2=p1->next,p3=p2->next;p3!=end;p1=p1->next,p2=p1->next,p3=p2->next){
			if((strcmp(p2->ques_num,p3->ques_num))>0){
				p2->next=p3->next;
				p1->next=p3;
				p3->next=p2;
			}
		}
		end=p2;
	}
	print_question();
    printf("\n\t\t选择回答问题的编号:");
    gets(a);
    while(t!=NULL){
		if(strcmp(a,t->ques_num)==0){
            b=0;
			break;
		    }
        t=t->next;
    }
     if(b==0)
    {
        printf("\n\t\t你的选项是(请输入大写字母):");
        fflush(stdin);
        scanf("%c",&ch);
        printf("\n\t\t您已完成该问题");
        while(1)
        {
            if(strcmp(a,t->ques_num)==0)
           {
           if(ch=='A')
           {
               t->ans_num_A[0]++;
            }
            if(ch=='B')
           {
               t->ans_num_B[0]++;
            }
            if(ch=='C')
           {
               t->ans_num_C[0]++;
           }
           break;
            }
            else t=t->next;
       }
        print_question_final(*t);
        fflush(stdin);
        scanf("%c",&ch);
    }
    if(b!=0)
    {
        printf("\n\t\t无此编号问卷 按任意键退出");
        getch();
    }
}

