#include"head.h"

int main(int argc,char *argv[])
{
    int ms=0;
	student_head=(Student*)malloc(sizeof(Student));
    manager_head=(Manager*)malloc(sizeof(Manager));
    ques_head=(Question*)malloc(sizeof(Question));

	student_head->next=student_load();
    manager_head->next=manager_load();
    ques_head->next=ques_load();

    do{
		main_screen();
		printf("\n");
		scanf("%d",&ms);
		while(getchar()!='\n');

		switch(ms){
			case 1:
				student_port();
				break;
			case 2:
				manager_port();
				break;
			case 0:
				break;
		}

	}while(ms!=0);


	message_save();
	system("pause");

}
