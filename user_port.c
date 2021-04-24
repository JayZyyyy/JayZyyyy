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

//��½����
void student_login(){
	int s1=1;
	char enter_num[50];
	//char enter_passw[20];
	int l=1;
	Student *enter_stu;

	while(l!=6){
		printf("\n�������˺ţ�");
		scanf("%s",enter_num);
		while(getchar()!='\n');
		l= strlen(enter_num);
		if(l!=6){
			printf("\n���볤������,����������");
		}
	}

	enter_stu=find_num(enter_num);

	if(enter_stu==NULL){
		printf("\n���˺Ų�����");
		Sleep(300);
		return;
	}else{
		printf("\n����������:");
	}
	//printf("\n%s",temp_stu->stu_passw);
	if(password_text_find(enter_stu->stu_passw)==0){
		printf("\n������������������Σ������˳�ϵͳ");
		return;
	}
	printf("\n���ڵ�½...");
	Sleep(500);
	printf("\n��½�ɹ�!");
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
				printf("�����������������룺");
				Sleep(3000);
				break;
		}
	}
}

//�˺�ע��
void student_signup(){
	printf("\n2");
	Student *h;
	Student *p=(Student*)malloc(sizeof(Student));
	p->next=NULL;
	printf("\n\t\t��ӭ����ע��ϵͳ��\n");
	Sleep(500);
	printf("\t\t���ڼ��ء�����\n");
	Sleep(500);
	printf("\t\t������������Ϣ\n");
	printf("\t\tѧ��(6λ)��");
	scanf("%s",p->stu_num);

	while(find_num(p->stu_num)){
		printf("\t\t���˺��ѱ�ע�ᣬ���������룺");
		scanf("%s",p->stu_num) ;
	}

	printf("\t\t������");
	scanf("%s",p->stu_name);
	printf("\t\t�绰��");
	scanf("%s",p->stu_tel);
	printf("\t\t���룺");
	password_input(p->stu_passw);
	printf("\t\t���ٴ��������룺");

	if(password_text(p->stu_passw)==0){
		printf("\n\t\t�Ѿ���������������󣬽��˳�ע��ϵͳ...");
		free(p);
		return;
	}
	printf("\n\n\t\t�ܱ����������һ�����\n");
	printf("\t\t�磺\n");
	printf("\t\t    ��ĸ�׵������ǣ�\n");
	printf("\t\t    �Ҹ��׵������ǣ�\n");
	printf("\t\t    �ҵ������ǣ�\n");
	printf("\n\t\t�ܱ����⣺");
	scanf("%s",p->stu_find_question);
	printf("\t\t�ܱ��������룺");
	password_input(p->stu_find_passw);
	printf("\t\t���ٴ������ܱ����룺");
	if(password_text(p->stu_find_passw)==0){
		printf("\n\t\t���Ѿ���������������Σ����˳�ע��ϵͳ...");
		free(p);
		return;
	}
	printf("\n����ע��...");
	printf("\nע��ɹ�!");
	printf("\n\t\t�����˺��ǣ�%s",p->stu_num);
	printf("\n\t\t���μ���������");
    save_student1(*p);
	h=student_head;
	while(h->next){
		h=h->next;
	}
	h->next=p;
	printf("\n\n\t��������˳�");
	getch();

}

//ͨ���ܱ��һ�����
void find_password(){
	Student *find_temp;
	char num_temp[50];
	//char password_find[20];
	printf("\n\t\t��ӭ�����һ�����ϵͳ��");
	int l=1;
	while(l!=6){
		printf("\n\t\t��������λ�˺ţ�");
		gets(num_temp);
		l=strlen(num_temp);
		if(l!=6){
			printf("\n\t\t������˺ų�����������������");
		}
	}
	num_temp[6]='\0';
	find_temp=find_num(num_temp);
	if(find_temp==NULL){
		printf("\n\t\t��Ǹ���޴��˺�");
		printf("\n\t\t�����˳���½ϵͳ...");
		Sleep(3000);
		return;
	}
	printf("\n\t\t%s,���",find_temp->stu_name);
	printf("\n\t\t�����õ��ܱ������ǣ�%s",find_temp->stu_find_question);
	printf("\t\n\n�����������ܱ����룺");
	if(password_text_find(find_temp->stu_find_passw)==0){
		printf("\t\n\n���Ѿ���������������Σ������˳��һ�����ϵͳ...");
		return;
	}
	printf("\n\t\t���ڲ���...");
	printf("\t\n\n���ã����������ǣ�%s",find_temp->stu_passw);
	printf("\n\t\t���μ���������");
	printf("\n\t\t��������˳�");
	getch();
}

//�������뺯��
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

//�޸�����
void stu_changepassw(Student *enter_stu){
	char password_temp[20];
	printf("\n\t\t������");
	printf("...");
	printf("\n\t\t������ԭ����:");
	if(password_text_find(enter_stu->stu_passw)==0){
		printf("\n\t\t�Ѿ�����������������,���˳��޸�����ϵͳ");
		return;
	}
	printf("\n\t\t������������:");
	password_input(password_temp);
	printf("\n\t\t���ٴ�����������:");
	if(password_text_find(password_temp)==0){
		printf("\n\t\t�Ѿ����������������,���˳��޸�����ϵͳ...");
		return;
	}
	enter_stu->stu_passw[0]='\0';
	printf("\n\t\t���Ե�,�����޸�");
	Sleep(500);
	printf("...");
		strcat(enter_stu->stu_passw,password_temp);
	Sleep(500);
	printf("\n\t\t�޸ĳɹ�");
	printf("\n\t\t��������˳�");
	getch() ;
}

//�˺�Ѱַ������
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

//���ע������
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
			printf("\n�������,������%d�λ���",2-n);
			n++;
		}
	}

	return temp;
}

//��֤��½����
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
			printf("\n��������㻹��%d�λ���",2-n);
			n++;
		}

	}

	return temp;
}

//�ϴ��ʾ�
void add_question(){
	printf("\n\t\t������������Ϣ��");
	Question *p=(Question*)malloc(sizeof(Question));
	p->next=NULL;
	Question *h=ques_head;


	printf("\n\t\t�ʾ��ţ�");
	gets(p->ques_num);
	printf("\t\t�������ƣ�");
	gets(p->ques_name);
	printf("\t\t�������ݣ�");
	gets(p->ques_content);
	printf("\t\t����ѡ��A��");
	gets(p->ques_ans_A);
	printf("\t\t����ѡ��B��");
	gets(p->ques_ans_B);
	printf("\t\t����ѡ��C��");
	gets(p->ques_ans_C);
	printf("\t\tĿǰѡ��A��������");
	gets(p->ans_num_A);
	printf("\t\tĿǰѡ��B��������");
	gets(p->ans_num_B);
	printf("\t\tĿǰѡ��C��������");
	gets(p->ans_num_C);
	save_ques1(*p);
	while(h->next){
		h=h->next;
	}
	h->next=p;
	printf("��������˳�");
	getch();
}



//��������
void find_question(){
	Question *t=ques_head->next;
	char ques_na[20];
	if(t==NULL){
		printf("\n\t\t��Ǹ�������ʾ�");
		printf("\n\t\t��������˳�");
		getch();
		return;
	}
	printf("\n\t\t��������Ҫ���ҵ�����:");
	gets(ques_na);
	fflush(stdin);
	while(t!=NULL){
		if(strcmp(ques_na,t->ques_name)==0){
			break;
		}
		t=t->next;
	}
	if(t==NULL){
		printf("\n\t\t��Ǹ,�޴�����");
		printf("\n\t\t��������˳�");
		getch();
		return;
	}
	printf("\n\t\t������");
	printf("...");
	printf("\n**********************************************");
	printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,"���","��������","����","ѡ��A","ѡ��B","ѡ��C");
	printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,t->ques_num,t->ques_name,t->ques_content
		,t->ques_ans_A,t->ques_ans_B,t->ques_ans_C);
	printf("\n**********************************************");
	printf("\n\t\t��������˳�");
	getch();

}

//�鿴���Ⲣ�ش�����
void choose_answer(){
    Question *t=ques_head->next;
    char a[20];
    char ch;
    int b=1;
	if(ques_head->next==NULL){
		printf("\n\t\t��������");
		printf("\n\t\t��������˳�");
        getch();

	}
	if(ques_head->next->next==NULL){
		print_question();
		printf("\n\t\t��������");
		printf("\n\t\t��������˳�");
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
    printf("\n\t\tѡ��ش�����ı��:");
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
        printf("\n\t\t���ѡ����(�������д��ĸ):");
        fflush(stdin);
        scanf("%c",&ch);
        printf("\n\t\t������ɸ�����");
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
        printf("\n\t\t�޴˱���ʾ� ��������˳�");
        getch();
    }
}

