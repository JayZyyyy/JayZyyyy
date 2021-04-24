#include"head.h"

void manager_port(){
	int mp=1;

	while(mp!=0){
		manager_screen();

		printf("\n");

		scanf("%d",&mp);

		while(getchar()!='\n');

		switch(mp){
		case 1:
			manager_login();
			break;
		case 0:
			mp=0;
			break;
		default :
			printf("\n����������������룺");
			break;
		}
	}
}

void manager_login(){
	char manager_num[20];
	int m1=1;
	Manager *enter_manager;
	printf("\n�˺ţ�");
	gets(manager_num);
	fflush(stdin);
	enter_manager=check_manager(manager_num);

	if(!enter_manager){
		printf("\n����Ա������");
		printf("\n��������˳�");
		getch();
		return;
	}
	printf("\n���룺");
	if(password_text_find(enter_manager->man_passw)==0){
		printf("\n���Ѿ�����������������");
		printf("\n��������˳�");
		getch();
		return;
	}
	printf("\n��¼��");
	printf("...");
	printf("\n��½�ɹ���");
	while(m1!=0){
		manager_console();
		printf("\n");
		scanf("%d",&m1);
		fflush(stdin);
		switch(m1){
		case 1:
			sort_question_by_num();
			break;
		case 2:
            add_question();
			break;
		case 3:
  		    delete_question();
			break;
		case 4:
			break;
		}
	}
}

//����ԱѰַ
Manager *check_manager(char *manager_num){
	Manager* t;
	t=manager_head->next;
	while(t){
		if(strcmp(t->man_num,manager_num)==0){
			break;
		}
		t=t->next;
	}

	return t;
}

//ɾ���ʾ�
void delete_question(){
	Question *p1=ques_head;
	Question *p2;
	char delete_num[10];
	printf("\n\t\t��ӭ����ɾ������ҳ��");
	printf("\n\t\tɾ��ǰ�����������£�");
	print_question();
	printf("\n\t\t������Ҫɾ������ı�ţ�");
	gets(delete_num);
	fflush(stdin);
	while(p1->next){
		if(strcmp(delete_num,p1->next->ques_num)==0){
			p2=p1->next;
			break;
		}
		p1=p1->next;
	}
	p1->next=p2->next;
	free(p2);

	printf("\n\t\tɾ���ɹ�");
	printf("\n\t\tɾ���������������£�");
	print_question();
	printf("\n\t\t�����������");
	getch();

}

//�������鿴����
void sort_question_by_num(){
	if(ques_head->next==NULL){
		printf("\n\t\t��������");
		printf("\n\t\t��������˳�");
        getch();
		return;
	}
	if(ques_head->next->next==NULL){
		print_question();
		printf("\n\t\t��������˳�");
		getch();
		return;
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
	printf("\n\t\t��������˳�");
	getch();
}
