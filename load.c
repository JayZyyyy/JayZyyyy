#include"head.h"

//载入学生信息
Student* student_load(){

	FILE *fp;
	Student *h=NULL;
	Student *t=h;
	Student *p;

	if((fp=fopen("studentnode.txt","r"))==NULL){
		printf("文件打开失败");
		exit(1);
	}
	while(!feof(fp)){

		p=(Student*)malloc(sizeof(Student));

		p->next=NULL;
		fscanf(fp,"%s",p->stu_name);

		fscanf(fp,"%s",p->stu_num);
		fscanf(fp,"%s",p->stu_passw);
		fscanf(fp,"%s",p->stu_find_question);

		fscanf(fp,"%s",p->stu_find_passw);
		fscanf(fp,"%s",p->stu_tel);
//密码解密功能
		if(h==NULL){
			h=p;
			t=p;
		} else{
			t->next=p;
			t=p;
		}


	}
	fclose(fp);

	return h;
}

Question* ques_load(){
	FILE *fp;
	Question *h=NULL,*p1=h,*p2;
	if((fp=fopen("questionnode.txt","r"))==NULL){
		printf("打开失败");
		exit(1);
	}
	getc(fp);
	if(feof(fp)){
		fclose(fp);
		return NULL;
	}

	rewind(fp);

	while(!feof(fp)){

		p2=(Question*)malloc(sizeof(Question));
		p2->next=NULL;

		fscanf(fp,"%s",p2->ques_num);
		fscanf(fp,"%s",p2->ques_name);
		fscanf(fp,"%s",p2->ques_content);
		fscanf(fp,"%s",p2->ques_ans_A);
		fscanf(fp,"%s",p2->ques_ans_B);
		fscanf(fp,"%s",p2->ques_ans_C);
		fscanf(fp,"%d",p2->ans_num_A);
		fscanf(fp,"%d",p2->ans_num_B);
		fscanf(fp,"%d",p2->ans_num_C);
		if(h==NULL){

			h=p2;
			p1=h;
		}else{
			p1->next=p2;
			p1=p1->next;
		}

	}
	fclose(fp);

	return h;

}
//保存学生信息
void save_student(){
	FILE *fp=fopen("studentnode.txt","w+");
	Student *t=student_head->next;

	if(fp==NULL){
		printf("\n\t\t文件打开失败");
		exit(1);
	}

	if(t==NULL){
		return;
	}
	while(t->next){
		fprintf(fp,"%s\t",t->stu_name);
		fprintf(fp,"%s\t",t->stu_num);
		fprintf(fp,"%s\t",t->stu_passw);
		fprintf(fp,"%s\t",t->stu_find_question);
		fprintf(fp,"%s\t",t->stu_find_passw);
		fprintf(fp,"%s\t",t->stu_tel);
		t=t->next;
	}
	    fprintf(fp,"%s\t",t->stu_name);
		fprintf(fp,"%s\t",t->stu_num);
		fprintf(fp,"%s\t",t->stu_passw);
		fprintf(fp,"%s\t",t->stu_find_question);
		fprintf(fp,"%s\t",t->stu_find_passw);
		fprintf(fp,"%s\t",t->stu_tel);
	fclose(fp);
}

void save_student1(Student *p){
       FILE *fp=fopen("studentnode.txt","a+");
        if(fp==NULL){
                printf("\n\t\t文件打开失败");
                exit(1);
            }
    fprintf(fp,"%s\t",p->stu_name);
    fprintf(fp,"%s\t",p->stu_num);
    fprintf(fp,"%s\t",p->stu_passw);
    fprintf(fp,"%s\t",p->stu_find_question);
    fprintf(fp,"%s\t",p->stu_find_passw);
    fprintf(fp,"%s\t",p->stu_tel);
	fclose(fp);
}
Manager* manager_load(){
	FILE *fp;
	Manager *h=NULL,*t=h,*p;
	if((fp=fopen("managernode.txt","r"))==NULL){
		printf("\n\t\t打开失败");
		exit(1);
	}
	getc(fp);
	if(feof(fp)){
		fclose(fp);
		return NULL;
	}
	rewind(fp);
	while(!feof(fp)){
		p=(Manager*)malloc(sizeof(Manager));
		p->next=NULL;
		fscanf(fp,"%s",p->man_name);
		fscanf(fp,"%s",p->man_num);
		fscanf(fp,"%s",p->man_passw);
		if(h==NULL){
			h=p;
		}else{
			t->next=p;
		}
		t=p;
	}
	return h;
}

void save_ques(){
	FILE *fp;
	Question *t=ques_head->next;
	if(!t){
		return;
	}
	if((fp=fopen("questionnode.txt","a+"))==NULL){
		printf("\n\t\t打开失败");
		exit(1);
	}
	while(t){
		fprintf(fp,"%s\t",t->ques_num);
		fprintf(fp,"%s\t",t->ques_name);
		fprintf(fp,"%s\t",t->ques_content);
		fprintf(fp,"%s\t",t->ques_ans_A);
		fprintf(fp,"%s\t",t->ques_ans_B);
		fprintf(fp,"%s\t",t->ques_ans_C);
		fprintf(fp,"%d\t",t->ans_num_A);
		fprintf(fp,"%d\t",t->ans_num_B);
		fprintf(fp,"%d\t",t->ans_num_C);
		t=t->next;
	}
	fclose(fp);

}

void save_ques1(Question *t)
{
    FILE *fp;
    if((fp=fopen("questionnode.txt","a+"))==NULL){
		printf("\n\t\t打开失败");
		exit(1);
	}
	while(t){
		fprintf(fp,"%s\t",t->ques_num);
		fprintf(fp,"%s\t",t->ques_name);
		fprintf(fp,"%s\t",t->ques_content);
		fprintf(fp,"%s\t",t->ques_ans_A);
		fprintf(fp,"%s\t",t->ques_ans_B);
		fprintf(fp,"%s\t",t->ques_ans_C);
		fprintf(fp,"%d\t",t->ans_num_A);
		fprintf(fp,"%d\t",t->ans_num_B);
		fprintf(fp,"%d\t",t->ans_num_C);
	}
	fclose(fp);
}

//封装
void message_save(){
	save_student();
	save_ques();
}
