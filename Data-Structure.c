# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
typedef struct Student {
	char name[20];				//姓名
	int num;					//学号
	int room;					//房间号
	struct Student *next;
} Stu;
/***********函数声明********/
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
			printf("谢谢使用:\n");
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
			printf("\n\t\t请选择排序关键字(1-3):\n");
			printf("\t\t1.姓名\n");
			printf("\t\t2.学号\n");
			printf("\t\t3.宿舍\n");
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
			printf("\n\t\t请选择查找关键字(1-2):\n");
			printf("\t\t1.学号\n");
			printf("\t\t2.宿舍\n");
			scanf("%d",&sign);
			printf("请输入查找信息:\n");
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
			printf("请输入学号:\n");
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

int menu_select() {      		//菜单功能选择
	int a;
	do {
		system("cls");			//清屏
		printf("\n\n\t\t----------------------学生宿舍管理系统----------------------\n\n");
		printf("\t\t* *  1. 添加信息                        * *  \n\n");
		printf("\t\t* *  2. 显示信息                        * *  \n\n");
		printf("\t\t* *  3. 按信息排序并显示                    * *  \n\n");
		printf("\t\t* *  4. 插入信息                        * *  \n\n");
		printf("\t\t* *  5. 查找信息                        * *  \n\n");
		printf("\t\t* *  6. 修改信息                        * *  \n\n");
		printf("\t\t* *  7. 删除信息                        * *  \n\n");
		printf("\t\t* *  8. 将信息写入文件                      * *  \n\n");
		printf("\t\t* *  9. 读取文件中的信息                    * *  \n\n");
		printf("\t\t* *  0. 退出系统                            * *  \n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t请选择您要运行的选项按(0-9):");
		scanf("%d",&a);
	} while(a<0||a>9);		//过滤无效输入
	return a;
}

Stu *input(Stu * head) {        //添加信息
	Stu *l,*p;
	l = (Stu *)malloc(sizeof(Stu));
	printf("请依次输入姓名学号宿舍:\n");
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
Stu* del(Stu *head) { 			//删除信息
	Stu * p,*q;
	int i,n;
	printf("请输入要删除的学生位置:\n");
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
		printf("第%d个学生不存在\n",n );
		return NULL;
	} else if(p->next == NULL) {
		printf("第%d个学生不存在\n",n );
		return NULL;
	} else {
		q = p->next;
		p->next = q->next; /*从链表中删除*/
		free(q); /*释放被删除结点 */
		return head;
	}
}

int  getvalue(Stu *head,int n,int sign) {				//第n个元素的值
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
		return p->room;				//返回学号或者姓名
}

Stu *getpoint(Stu *head,int n) { 					//第n个元素的指针
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

Stu *search(Stu *head,int key,int sign) {			//查找
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

int length(Stu * head) {			//求表长
	Stu * p = head;				//p指向head
	int j = 0;
	while(p) {
		p = p -> next;			//当前瓶p指向第j个节点
		j ++;
	}
	return j;					//返回表长
}

void output(Stu *head) {			//输出函数
	printf("-----------------------------------------\n");
	printf(" 姓名		学号		房间号 \n");
	printf("------------------------------------------\n");
	Stu *p;
	p=head;
	if(head==NULL) {
		printf("\n\t\t\t学生信息为空！\n");
	} else {
		do {
			printf("%3s%20d%10d%\n",p->name,p->num,p->room);
			p=p->next;
		} while(p!=NULL);
	}
}
Stu *edit(Stu * p) {			//编辑函数
	if(p == NULL) {
		printf("学号错误\n");
		return NULL;
	} else {
		printf("请依次输入姓名学号宿舍:\n");
		scanf("%s%d%d",&p->name,&p->num,&p->room);
		return p;
	}

}
void sort_num(Stu *head) {		//按学号排序
	/********************按学号******************/
	Stu *p,*q;
	for(p = head ; p != NULL; p = p->next)
		for(q = head; q != NULL; q = q->next) {
			if(p->num < q->num) {
				exchange(p,q);

			}
		}
}

void sort_room(Stu *head) {		//按宿舍排序
	Stu *p,*q;
	/********************按宿舍****************/
	for(p = head ; p != NULL; p = p->next)
		for(q = head; q != NULL; q = q->next) {
			if(p->room < q->room) {
				exchange(p,q);
			}
		}
}

void sort_name(Stu *head) {			//按姓名排序函数
	Stu *p,*q;
	/*	int n;


		switch(n) {*/
	/********************按姓名******************/
	for(p = head ; p != NULL; p = p->next)
		for(q = head; q != NULL; q = q->next) {
			if(strcmp(p->name,q->name) < 0 ) {
				exchange(p,q);
			}
		}
}
void exchange(Stu *p,Stu *q) {	//数据交换
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
		printf("\n\t\t\t学生信息为空！\n");
	} else {
		printf("-----------------------------------------\n");
		printf(" 姓名		学号		房间号 \n");
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
		printf("文件打开失败！\n");
		return ;
	}
	p=head;
	while(p != NULL) {
		fprintf(fp,"%s\t",p->name);
		fprintf(fp,"%d\t",p->num);
		fprintf(fp,"%d\t",p->room);
		p = p->next;
	}
	printf("写入成功\n");
}

void read_file(Stu *head) {
	FILE *fp;
	char name[20];
	int num;
	int room;
	fp=fopen("Data.txt","rb+");
	if(fp == NULL) {
		printf("文件打开失败！\n");
	}
	printf("-----------------------------------------\n");
	printf(" 姓名		学号		房间号 \n");
	printf("------------------------------------------\n");
	fscanf(fp,"%s\t%d\t%d",name,&num,&room);
//	while(fscanf(fp,"%s\t%d\t%d",&name,&num,&room) != EOF){

	printf("%3s%20d%10d%\n",name,num,room);
//	}

	printf("1\n");



	fflush(fp);
	fclose(fp);
}

