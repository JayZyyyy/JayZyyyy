#include"head.h"
//<time.h>�е�tm�ṹ���˵��
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
//��ʾ������
void main_screen(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);


	printf("\n\n############################################");
	printf(" ");
	printf("\n               ��ӭʹ���ʾ�������          ");
	printf(" ");
	printf("\n");
	printf("\n       ʱ�䣺%4d��%2d��%2d�� %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n1->ѧ�����");
	printf("\n2->����Ա���");
	printf("\n0->Exit");
	printf("\n\n");
	printf("\n#############################################\n");

}

//��ʾ�û�����
void student_screen(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                �װ����û� ");
	printf("\n##############################################");
	printf(" ");
	printf("\n               ��ӭʹ���ʾ�������          ");
	printf(" ");
	printf("\n");
	printf("\n       ʱ�䣺%4d��%2d��%2d�� %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n1->��½");
	printf("\n2->ע��");
	printf("\n3->��������");
	printf("\n0->����");
	printf("\n#############################################\n");
}

//��ʾѧ������̨
void student_console(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                �װ����û� ");
	printf("\n##############################################");
	printf(" ");
	printf("\n               ��ӭʹ���ʾ�������          ");
	printf(" ");
	printf("\n");
	printf("\n       ʱ�䣺%4d��%2d��%2d�� %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n");
	printf("\n1->�������");
	printf("\n2->��������");
	printf("\n3->��˳��鿴����");
	printf("\n4->�ش�����");
	printf("\n5->�޸�����");
	printf("\n0->back");
	printf("\n#############################################\n");
}

//��ʾ����Ա����
void manager_screen(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                �𾴵Ĺ���Ա ");
	printf("\n##############################################");
	printf(" ");
	printf("\n               ��ӭʹ���ʾ�������          ");
	printf(" ");
	printf("\n");
	printf("\n       ʱ�䣺%4d��%2d��%2d�� %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n");
	printf("\n1->��½");
	printf("\n0->����");
	printf("\n#############################################\n");
}

//��ʾ����Ա����̨
void manager_console(){
	system("CLS");

	time_t timer;
	struct tm *lt;
	time(&timer);
	lt=localtime(&timer);

	printf("\n                �𾴵Ĺ���Ա");
	printf("\n##############################################");
	printf(" ");
	printf("\n               ��ӭʹ���ʾ�������          ");
	printf(" ");
	printf("\n");
	printf("\n       ʱ�䣺%4d��%2d��%2d�� %02d:%02d:%02d    ",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("\n");
	printf("\n");
	printf("\n1->��˳��鿴����");
	printf("\n2->�������");
	printf("\n3->ɾ������");
	printf("\n4->�鿴�ʾ����");
	printf("\n0->back");
	printf("\n#############################################\n");
}

//��ӡ�ʾ�
int print_question(){
	int result=0;
	Question *t=ques_head->next;
	if(t==NULL){
		printf("\n\t\t��Ǹ�������ʾ�");
		return result;
	}
	printf("\n**********************************************");
	printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,"���","��������","��������","Aѡ��","Bѡ��","Cѡ��");
	while(t){
		printf("\n%-20s%-20s%-20s%-20s%-20s%-20s"
		,t->ques_num,t->ques_name,t->ques_content
		,t->ques_ans_A,t->ques_ans_B,t->ques_ans_C);
		t=t->next;
	}
	printf("\n**********************************************");
	return 1;
}

//��ӡ�ʾ���
int print_question_final(Question *t){
	int result=0;
	//Question *t=ques_head->next;
	if(t==NULL){
		printf("\n\t\t��Ǹ�������ʾ�");
		return result;
	}
	printf("\n**********************************************");
    printf("\n\t\t��%dѡ��A",t->ans_num_A[0]);
    printf("\n\t\t��%dѡ��B",t->ans_num_B[0]);
    printf("\n\t\t��%dѡ��C",t->ans_num_C[0]);
	printf("\n**********************************************");
	return 1;
}

