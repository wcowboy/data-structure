# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
typedef struct Student {
	char name[20];				//����
	int num;					//ѧ��
	int room;					//�����
	struct Student *next;
} Stu;
/***********��������********/
void exchange(Stu *p,Stu *q);
void sort_num(Stu *head);
void sort_room(Stu *head);
void sort_name(Stu *head);
void putone(Stu *p);
void output(Stu *head);
void read_file();
void write_file(Stu *head);
int  lenth(Stu * head);
int  menu_select();
int  getvalue(Stu *head,int n,int sign);
Stu  *edit(Stu *head);
Stu  *fun(Stu* head);
Stu  *getpoint(Stu *head,int possion);
Stu  *creat(Stu *head);
Stu  *input(Stu *head);
Stu  *del(Stu *head);
Stu  *search(Stu *head,int key,int sign);

int main() {
	Stu *head,*p;
	head = NULL;
//	head = input(head);
//	head = input(head);
//	head = input(head);
	head = creat(head);
	sort_num(head);
	output(head);
	printf("%d",getvalue(head,0,1));
//	output(search(head,3,1));


//	while(1) {
//		head = fun(head);
//	}


}
Stu *fun(Stu *head) {
	int n,sign = 0,x;
	Stu *p;
	p = NULL;
	n = menu_select();
	switch(n) {
		case 0: {
			printf("ллʹ��:\n");
			exit(1);
			break;
		}
		case 1: {
			head = input(head);
			system("pause");
			break;
		}
		case 2: {
			output(head);
			system("pause");
			break;
		}
		case 3: {
			printf("\n\t\t��ѡ������ؼ���(1-3):\n");
			printf("\t\t1.����\n");
			printf("\t\t2.ѧ��\n");
			printf("\t\t3.����\n");
			scanf("%d",&sign);
			switch(sign) {
				case 1: {
					sort_name(head);
					break;
				}
				case 2: {
					sort_num(head);
					break;
				}
				case 3: {
					sort_room(head);
					break;
				}
			}
			output(head);
			system("pause");
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			printf("\n\t\t��ѡ����ҹؼ���(1-2):\n");
			printf("\t\t1.ѧ��\n");
			printf("\t\t2.����\n");
			scanf("%d",&sign);
			printf("�����������Ϣ:\n");
			scanf("%d",&x);
			switch(sign) {
				case 1: {
					sort_num(head);
					putone(search(head,x,1));
					system("pause");
					break;
				}
				case 2: {
					sort_room(head);
					putone(search(head,x,2));
					system("pause");
					break;
				}
			}
			break;
		}
		case 6: {
			printf("������ѧ��:\n");
			scanf("%d",&x);
			sort_num(head);
			p = search(head,x,1);
			putone(p);
			p = edit(p);

			system("pause");
			break;
		}
	}

	return head;
}

int menu_select() {      		//�˵�����ѡ��
	int a;
	do {
		system("cls");			//����
		printf("\n\n\t\t----------------------ѧ���������ϵͳ----------------------\n\n");
		printf("\t\t* *  1. �����Ϣ                        * *  \n\n");
		printf("\t\t* *  2. ��ʾ��Ϣ                        * *  \n\n");
		printf("\t\t* *  3. ����Ϣ������ʾ                    * *  \n\n");
		printf("\t\t* *  4. ������Ϣ                        * *  \n\n");
		printf("\t\t* *  5. ������Ϣ                        * *  \n\n");
		printf("\t\t* *  6. �޸���Ϣ                        * *  \n\n");
		printf("\t\t* *  7. ɾ����Ϣ                        * *  \n\n");
		printf("\t\t* *  8. ����Ϣд���ļ�                      * *  \n\n");
		printf("\t\t* *  9. ��ȡ�ļ��е���Ϣ                    * *  \n\n");
		printf("\t\t* *  0. �˳�ϵͳ                            * *  \n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
		scanf("%d",&a);
	} while(a<0||a>9);		//������Ч����
	return a;
}

Stu *input(Stu * head) {        //�����Ϣ
	Stu *l,*p;
	l = (Stu *)malloc(sizeof(Stu));
	printf("��������������ѧ������:\n");
	scanf("%s%d%d",&l->name,&l->num,&l->room);
	printf("\n");
	l->next = NULL;
	if(head == NULL) {
		head = l;
		return head;
	} else {
		p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = l;
		return head;
	}
}
Stu* del(Stu *head) { 			//ɾ����Ϣ
	Stu * p,*q;
	int i,n;
	printf("������Ҫɾ����ѧ��λ��:\n");
	scanf("%d",&n );
	if(n == 1) {
		q = head;
		if(head != NULL) {
			printf("1\n");
			head = head->next;
			putone(head);
		} else return NULL;
		free(q);
		return head;

	}
	p = getpoint(head,n - 1);
	if(p == NULL) {
		printf("��%d��ѧ��������\n",n );
		return NULL;
	} else if(p->next == NULL) {
		printf("��%d��ѧ��������\n",n );
		return NULL;
	} else {
		q = p->next;
		p->next = q->next; /*��������ɾ��*/
		free(q); /*�ͷű�ɾ����� */
		return head;
	}
}

int  getvalue(Stu *head,int n,int sign) {				//��n��Ԫ�ص�ֵ
	int j=0;
	Stu *p;
	p = head;
	while(p != NULL && j < n) {
		p = p->next;
		j++;
	}
	if(sign = 1)
		return p->num;
	else
		return p->room;				//����ѧ�Ż�������
}

Stu *getpoint(Stu *head,int n) { 					//��n��Ԫ�ص�ָ��
	int i = 1;
	Stu *p = head;
	while(p != NULL && i < n) {
		p = p->next;
		i ++;
	}
	if(i == n)
		return p;
	else return NULL;
}

Stu *search(Stu *head,int key,int sign) {			//����
	int low = 1,high = length(head);
	int mid = 0;
	while(low<=high) {
		mid = (low + high) / 2;
		if(key == getvalue(head,mid,sign))
			return getpoint(head,mid);
		else if(key < getvalue(head,mid,sign))
			high = mid-1;
		else low = mid+1;
	}
	return NULL;
}

int length(Stu * head) {			//���
	Stu * p = head;				//pָ��head
	int j = 0;
	while(p) {
		p = p -> next;			//��ǰƿpָ���j���ڵ�
		j ++;
	}
	return j;					//���ر�
}

void output(Stu *head) {			//�������
	printf("-----------------------------------------\n");
	printf(" ����		ѧ��		����� \n");
	printf("------------------------------------------\n");
	Stu *p;
	p=head;
	if(head==NULL) {
		printf("\n\t\t\tѧ����ϢΪ�գ�\n");
	} else {
		do {
			printf("%3s%20d%10d%\n",p->name,p->num,p->room);
			p=p->next;
		} while(p!=NULL);
	}
}
Stu *edit(Stu * p) {			//�༭����
	if(p == NULL) {
		printf("ѧ�Ŵ���\n");
		return NULL;
	} else {
		printf("��������������ѧ������:\n");
		scanf("%s%d%d",&p->name,&p->num,&p->room);
		return p;
	}

}
void sort_num(Stu *head) {		//��ѧ������
	/********************��ѧ��******************/
	Stu *p,*q;
	for(p = head ; p != NULL; p = p->next)
		for(q = head; q != NULL; q = q->next) {
			if(p->num < q->num) {
				exchange(p,q);

			}
		}
}

void sort_room(Stu *head) {		//����������
	Stu *p,*q;
	/********************������****************/
	for(p = head ; p != NULL; p = p->next)
		for(q = head; q != NULL; q = q->next) {
			if(p->room < q->room) {
				exchange(p,q);
			}
		}
}

void sort_name(Stu *head) {			//������������
	Stu *p,*q;
	/*	int n;


		switch(n) {*/
	/********************������******************/
	for(p = head ; p != NULL; p = p->next)
		for(q = head; q != NULL; q = q->next) {
			if(strcmp(p->name,q->name) < 0 ) {
				exchange(p,q);
			}
		}
}
void exchange(Stu *p,Stu *q) {	//���ݽ���
	char temp[20];
	p->num = p->num + q->num;
	q->num = p->num - q->num;
	p->num = p->num - q->num;
	p->room = p->room + q->room;
	q->room = p->room - q->room;
	p->room = p->room - q->room;
	strcpy(temp,p->name);
	strcpy(p->name,q->name);
	strcpy(q->name,temp);
}

void putone(Stu *p) {
	if(p == NULL) {
		printf("\n\t\t\tѧ����ϢΪ�գ�\n");
	} else {
		printf("-----------------------------------------\n");
		printf(" ����		ѧ��		����� \n");
		printf("------------------------------------------\n");
		printf("%3s%20d%10d%\n",p->name,p->num,p->room);
	}
}
Stu *creat(Stu *head) {
	Stu *p,*q;
	p = (Stu *)malloc(sizeof(Stu));
	q = (Stu *)malloc(sizeof(Stu));
	head = p;
	strcpy(p->name,"abc");
	p->num = 4;
	p->room = 3;
	p->next = q;
	p = q;
	q = (Stu *)malloc(sizeof(Stu));
	strcpy(p->name,"acd");
	p->num = 3;
	p->room = 1;
	p->next = q;

	strcpy(q->name,"aad");
	q->num = 5;
	q->room = 2;
	q->next = NULL;
	return head;
}

void write_file(Stu *head) {
	FILE *fp;
	Stu *p;
	if((fp=fopen("Data.txt","at+"))==NULL) {
		printf("�ļ���ʧ�ܣ�\n");
		return ;
	}
	p=head;
	while(p != NULL) {
		fprintf(fp,"%s\t",p->name);
		fprintf(fp,"%d\t",p->num);
		fprintf(fp,"%d\t",p->room);
		p = p->next;
	}
	printf("д��ɹ�\n");
}

void read_file(Stu *head) {
	FILE *fp;
	char name[20];
	int num;
	int room;
	fp=fopen("Data.txt","rb+");
	if(fp == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
	}
	printf("-----------------------------------------\n");
	printf(" ����		ѧ��		����� \n");
	printf("------------------------------------------\n");
	fscanf(fp,"%s\t%d\t%d",name,&num,&room);
//	while(fscanf(fp,"%s\t%d\t%d",&name,&num,&room) != EOF){

	printf("%3s%20d%10d%\n",name,num,room);
//	}

	printf("1\n");



	fflush(fp);
	fclose(fp);
}

