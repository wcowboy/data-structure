# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
typedef struct Student
{ 
	char name[20];				//����     
    int num;					//ѧ�� 
    int room;					//����� 
    struct Student *next;		
}Stu;
//��������
void output(Stu *head);
int lenth(Stu * head);
int menu_select();     
Stu *find(Stu *head);
Stu *input(Stu *head);     s
Stu* del(Stu *head);

int main(){
//	Stu *input(int n);
//	menu_select();				//�˵�ѡ���� 
	Stu *head,*p;
	head = NULL;
	head = input(head);
	printf("len = %d\n",lenth(head));
	output(head);
	head = input(head);
	printf("len = %d\n",lenth(head));
	output(head);
	del(head);
	output(head);	
} 
Stu *input(Stu * head){         //�����Ϣ 	
	Stu *l,*p; 
	l = (Stu *)malloc(sizeof(Stu));
	printf("\t\t����:");
	scanf("%s",&l->name);
	printf("\t\tѧ��:");
	scanf("%d",&l->num);
	printf("\t\t�����:");
	scanf("%d",&l->room);
	printf("\n");
	l->next = NULL;
	if(head == NULL){
		head = l;
		return head;
	} 
	else{
		p = head;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = l;
		return head;
	}
}
Stu* del(Stu *head){ 			//ɾ����Ϣ 
	int i,n;
	printf("������Ҫɾ����ѧ��λ��:\n");
	scanf("%d",&n);
	Stu *p,*q;
	p = head;
	for(i = 1;i < n && p -> next != NULL;i++){
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	free(q);
}
Stu * find(Stu *head){ 			//��ѧ�Ų��Һ��� 
	int num; 
	Stu *p = head;
	printf("������Ҫ���ҵ�ѧ��ѧ��:\n");
	scanf("%d",&num);
	int i = 1;
	while ( p!=NULL && p->num != num ){
		p = p->next;
	}
	return p;
	
}
int lenth(Stu * head){			//��� 
	Stu * p = head;				//pָ��head 
	int j = 0;
	while(p){
		p = p -> next;			//��ǰƿpָ���j���ڵ� 
		j ++;
	}
	return j;					//���ر� 
}
int menu_select(){      		//�˵�����ѡ�� 
 	int a;
    do{
        system("cls");			//���� 
        printf("\n\n\t\t----------------------ѧ���������ϵͳ----------------------\n\n");
        printf("\t\t��� 1. ���ѧ����Ϣ                        ���\n\n");
        printf("\t\t��� 2. ��ʾѧ����Ϣ                        ���\n\n");
        printf("\t\t��� 3. ����Ϣ������ʾ                    ���\n\n");
        printf("\t\t��� 4. ����ѧ����Ϣ                        ���\n\n");
        printf("\t\t��� 5. ����ѧ����Ϣ                        ���\n\n");
        printf("\t\t��� 6. �޸�ѧ����Ϣ                        ���\n\n");
        printf("\t\t��� 7. ɾ��ѧ����Ϣ                        ���\n\n");
        printf("\t\t��� 8. ����Ϣд���ļ�                      ���\n\n");
        printf("\t\t��� 9. ��ȡ�ļ��е���Ϣ                    ���\n\n");
		printf("\t\t��� 0. �˳�ϵͳ                            ���\n\n");
        printf("\t\t------------------------------------------------------------\n");
        printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
        scanf("%d",&a);
    }while(a<0||a>9);		//������Ч���� 
    return a;
}
void output(Stu *head){			//������� 
	printf("-----------------------------------------\n");
	printf(" ����		ѧ��		����� \n");
	printf("------------------------------------------\n");
	Stu *p;
	p=head;
	if(head==NULL){
		printf("\n\t\t\tѧ����ϢΪ�գ�\n");
	}
	else{
		do{
			printf("%3s%20d%10d%\n",p->name,p->num,p->room);
			p=p->next;
		}while(p!=NULL);
	} 
}
void edit(Stu * head){			//�༭���� 
	
} 




