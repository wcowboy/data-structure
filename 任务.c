# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
typedef struct Student
{ 
	char name[20];				//姓名     
    int num;					//学号 
    int room;					//房间号 
    struct Student *next;		
}Stu;
//函数声明
void output(Stu *head);
int lenth(Stu * head);
int menu_select();     
Stu *find(Stu *head);
Stu *input(Stu *head);     s
Stu* del(Stu *head);

int main(){
//	Stu *input(int n);
//	menu_select();				//菜单选择函数 
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
Stu *input(Stu * head){         //添加信息 	
	Stu *l,*p; 
	l = (Stu *)malloc(sizeof(Stu));
	printf("\t\t姓名:");
	scanf("%s",&l->name);
	printf("\t\t学号:");
	scanf("%d",&l->num);
	printf("\t\t房间号:");
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
Stu* del(Stu *head){ 			//删除信息 
	int i,n;
	printf("请输入要删除的学生位置:\n");
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
Stu * find(Stu *head){ 			//按学号查找函数 
	int num; 
	Stu *p = head;
	printf("请输入要查找的学生学号:\n");
	scanf("%d",&num);
	int i = 1;
	while ( p!=NULL && p->num != num ){
		p = p->next;
	}
	return p;
	
}
int lenth(Stu * head){			//求表长 
	Stu * p = head;				//p指向head 
	int j = 0;
	while(p){
		p = p -> next;			//当前瓶p指向第j个节点 
		j ++;
	}
	return j;					//返回表长 
}
int menu_select(){      		//菜单功能选择 
 	int a;
    do{
        system("cls");			//清屏 
        printf("\n\n\t\t----------------------学生宿舍管理系统----------------------\n\n");
        printf("\t\t☆☆ 1. 添加学生信息                        ☆☆\n\n");
        printf("\t\t☆☆ 2. 显示学生信息                        ☆☆\n\n");
        printf("\t\t☆☆ 3. 按信息排序并显示                    ☆☆\n\n");
        printf("\t\t☆☆ 4. 插入学生信息                        ☆☆\n\n");
        printf("\t\t☆☆ 5. 查找学生信息                        ☆☆\n\n");
        printf("\t\t☆☆ 6. 修改学生信息                        ☆☆\n\n");
        printf("\t\t☆☆ 7. 删除学生信息                        ☆☆\n\n");
        printf("\t\t☆☆ 8. 将信息写入文件                      ☆☆\n\n");
        printf("\t\t☆☆ 9. 读取文件中的信息                    ☆☆\n\n");
		printf("\t\t☆☆ 0. 退出系统                            ☆☆\n\n");
        printf("\t\t------------------------------------------------------------\n");
        printf("\t请选择您要运行的选项按(0-9):");
        scanf("%d",&a);
    }while(a<0||a>9);		//过滤无效输入 
    return a;
}
void output(Stu *head){			//输出函数 
	printf("-----------------------------------------\n");
	printf(" 姓名		学号		房间号 \n");
	printf("------------------------------------------\n");
	Stu *p;
	p=head;
	if(head==NULL){
		printf("\n\t\t\t学生信息为空！\n");
	}
	else{
		do{
			printf("%3s%20d%10d%\n",p->name,p->num,p->room);
			p=p->next;
		}while(p!=NULL);
	} 
}
void edit(Stu * head){			//编辑函数 
	
} 




