#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define LEN sizeof(struct student)  //方便使用，使代码更简洁，用"LEN"代替"sizeof(struct student)"
using namespace std;
int n;//表示学生人数 
//创建结构体 
typedef struct student{
	int score;
	char name[12];
	char sex[5];
	char major[20];//专业 
	struct student *next;
}*link;
//创建类 
class student_system
{
public:
	//函数定义 
	static int Login();              //登录
	static void Menu();              //菜单 
	static int input(link head);     //录入 
	static void Sort(link head);     //排序 
	static int  Search(link head);   //查询 
	static int Classify(link head);  //分类 
	static int Del(link head) ;      //删除 
	static int Modify(link head);    //修改
	static int print(link head);     //打印 
	static void write_wb(link head); //把数据写入文件 
	static void read(link head);     //从文件中读取数据 
};
//创建链表
link creat()
{
	link head=NULL;         //头节点指针，是为了指向第一个节点，不然节点会丢失
	head=(link)malloc(LEN); //在堆区开辟空间 
	if(head==NULL)          //如果数据类型是指针类型，那我们一般成功的时候返回相应的地址，失败的时候返回NULL
	{
		printf("内存用完啦");
		return NULL;
	} 
	memset(head,0,LEN); //把head初始化 
	head->next=NULL;    //把head指向的next指针赋值为空 
	return head;
}
int main()
{
	system("color F0"); //改变控制台颜色 
	link stu,p;
	link head;          //创建链表
	head=creat();
	student_system::Login();
start:
	while(1)
	{
		student_system::Menu ();
		printf("您想执行什么操作：");
		int choice;
		scanf("%d",&choice);
		switch(choice)   //用switch语句对输入信息分情况讨论 
		{
			case 1:
				student_system::input(head);
				Sleep(200);
				break;
			case 2:
				student_system::Sort(head);
				Sleep(200);
				break;
			case 3:
				student_system::Search(head);
				Sleep(200);
				break;
			case 4:
				student_system::Classify(head);
				Sleep(200);
				break;
			case 5:
				student_system::Del(head);
				Sleep(200);
				break;
			case 6:
				student_system::Modify(head);
				Sleep(200);
				break;
			case 7:
				printf("拜拜~,希望您的体验感不会太差\n");
				system("pause");
				system("cls");
				return 0;
				break;
			default:
				printf("不好意思....简陋的我没有这个功能\n\n");
				printf("如果是不小心输错了那就按1,不想执行了请按其他.\n");
				int n;
				scanf("%d",&n);
				if(n==1)
				goto start; 
				else
				{
					printf("拜拜~");
					return 0;
				}
				system("pause"); //暂停 
				break;
		}
	}	
}
//登录 
void Cat()  //使代码更清晰 
{
	printf("\n");
	printf("    /\\,_,/\\      .          //\n");
	printf("   (  .,.  )   ,','   , '`` ` ``',\n"); 
	printf("   ,'      ', ; ;   ,'  /\\   /\\   ',\n");
	printf("  ;' | || | ;,','   ;     \\/       ;\n");
	printf("  ', |,||,|,','      ',          ,'                                                     Code by rv\n ");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
}
int student_system::Login()
{
	int flag=0;
	printf("\n");
	printf("    /\\,_,/\\      .          //\n");
	printf("   (  .,.  )   ,','   , '`` ` ``',\n"); 
	printf("   ,'      ', ; ;   ,'  /\\   /\\   ',\n");
	printf("  ;' | || | ;,','   ;     \\/       ;\n");
	printf("  ', |,||,|,','      ',          ,'                页面加载中...\t\t\tCode by rv\n ");
	int num=100;
	while (num--)  //使“~”直接逐渐加载出来 
	{
		printf("~");
		Sleep(14); 
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t   加载成功！\n\n");
	Sleep(700);
start:
	if (flag) Cat();  //使用户在输错一次账号后页面最上方仍有小猫和南瓜 
	cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t----- 新生基本信息统计软件 -----"<<endl;
	cout<<"\t\t\t\t\t------                    ------"<<endl;
	cout<<"\t\t\t\t\t--------- 用户登录页面 ---------"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\n\n\n\t\t\t\t请输入您的身份证号码：";
	flag=1;
	char ID[18]={'\0'},temp[6]={'\0'},password[6]={'\0'};
	gets(ID);           //存入身份证号 
	if(strlen(ID)!=18)  //看身份证号是否是18位数字 
	{
		printf("\n\t\t\t\t输错了，您输入的身份证号不是18位呀\n");
		printf("\n\t\t\t\t请重新输入\n"); 
		system("pause"); 
		system("cls"); //清屏 
		goto start;   //返回登陆页面 
	}
	else
	{
		int i;
		int ans=0;
		
		for(i=12;i<18;i++) 
			temp[ans++]=ID[i];  //再用一个数组保存身份证后六位 
	
		for(i=0;i<3;i++)  //三次容错机会 
		{
			printf("\n\t\t\t\t请输入密码(初始密码为身份证号码后6位)：");
			gets(password);
			if(strcmp(password,temp)==0)
			{
				printf("\n\t\t\t\t密码正确!即将登陆");
				Sleep(500);  //使“.”直接逐渐加载出来 
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				system("cls");
				return 0;
			}
		else
		printf("\n\t\t\t\t输错了，您还有%d次机会\n\n",2-i);
	}
	printf("\n\t\t\t\t拜拜~");
	exit(0);  //exit()--退出   0--正常退出  其他--非正常退出 
	} 
}
//菜单 
void student_system::Menu()
{ 
	printf("\n\t\t*********************************\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t新生基本信息统计软件    *\n");
	printf("\t\t*\t                        *");
	//printf("\n\t\t*\t您想执行什么操作?       *\n");
	//printf("\t\t*\t                        *");
	printf("\n\t\t*\t1.录入学生信息          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t2.按英语入学成绩排序    *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t3.查询学生信息          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t4.对学生信息分类        *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t5.删除学生信息          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t6.修改学生信息          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t7.保存并退出系统        *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*********************************\n"); 
}
//录入函数 
int student_system::input(link head)
{
	link new_node;
	link head_t=head;
	new_node=NULL;
	new_node=(link)malloc(LEN);
	if(new_node==NULL)
	{
		printf("内存用完啦");
		return -1;
	}
	while(head_t->next!=NULL)
	{
		head_t=head_t->next;
	} 
	head_t->next=new_node;
	FILE *fp;
	fp=fopen("学管.txt","a+"); //打开一个用于读取和追加的文件 
	if(!fp)                    //fopen函数返回一个 FILE 指针。否则返回 NULL
	{
		printf("error");
		exit(0);
	}
	printf("请输入英语入学成绩：");
	scanf("%d",&new_node->score);
	printf("请输入姓名：");
	getchar();
	gets(new_node->name);
	printf("请输入性别：");
 	gets(new_node->sex);
	printf("请输入专业：");
	gets(new_node->major);
	new_node->next=NULL;
	printf("\n录入成功!\n\n");
	Sleep(800);   //暂停800毫秒 
	n++;
	fprintf(fp,"%d %s %s %s\n",new_node->score,new_node->name,new_node->sex,new_node->major);
	fclose(fp);  //关闭文件 相当于保存文件
	return 0;
}
//打印 
int student_system::print(link head)
{
	read(head);
	link p=head->next;
	printf("英语\t\t姓名\t\t性别\t\t专业\n");
	/*遍历链表时，为什么不直接使用head指针而要重新创建一个新指针？
	因为如果使用head，会改变head中的值，程序就找不到链表的开始处*/
	while(p)
	{
		printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
		p=p->next; 
	} 
	return 0;
}
//排序 
void student_system::Sort(link head)
{
	read(head);
	link head_t=head;
	link pre,p;
	link tail=NULL;
	while(head_t->next!=tail)//传入的是带头节点的链表,为了简便操作头节点未赋值,所以从head->next开始
	{
		pre=head;
		p=head->next;
		while (p->next != tail)
		{
			if (p->score < p->next->score)  //如果前一个节点的score小于后一个节点的score的，则两节点互换地址 
			{
				pre->next = p->next;
				p->next = pre->next->next;
				pre->next->next = p;
			}
			else
			{
				p = p->next;  //指向下一节点 
			}
				pre = pre->next;
		}
		tail=p;
	}
	printf("排序后:\n");
	write_wb(head); //把数据存入文件中 
	print(head);    //打印存入的数据 
}
//查询 
int student_system::Search(link head) 
{
	read(head);
		int i;
	link p=head->next;
	int num;
	int flag=0;
	char s[20];
	printf("\n\t\t**********************\n");
	printf("\n\t\t-1.按英语入学成绩查询-\n");
	printf("\n\t\t-----2.按姓名查询-----\n");
	printf("\n\t\t-----3.退出本菜单-----\n");
	printf("\n\t\t**********************\n");
	while(1)
	{
		printf("\n请输入您想进行哪项操作: ");
		int choice;
		scanf("%d",&choice);
		switch(choice)  //用switch语句对输入信息分情况讨论 
		{
			case 1:
there:			printf("\n请输入您想查询的学生英语入学成绩: ");  //比较输入的id与链表中每个节点id的字典序是否相等
				scanf("%d",&num);
				p=head->next;
				while(p)
				{
					if(p->score==num)
					{
						flag=1;
						printf("英语\t\t姓名\t\t性别\t\t专业\n");
						printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
						Sleep(1000);
						return 0;
					 } 
					p=p->next;   //指向下一节点 
				}
				if(p==NULL&&flag==1)
					return 0;
					if(p==NULL&&flag==0)  //说明遍历完整个链表仍没有此学生 
					{
						printf("\n没有该学生\n不小心输错请按1，不想执行了请按其他。\n");
						int n;
						scanf("%d",&n);
						if(n==1)
						goto there;
						else
					return 0;
					}
				break;
			case 2:
here:			printf("\n请输入您想查询的学生姓名: ");
				scanf("%s",s);
				p=head->next;
				while(p) //只要不到尾节点就持续遍历 
				{
					if(strcmp(p->name,s)==0)  //比较输入的name与链表中每个节点name的字典序是否相等 
					{
						flag=1;
						printf("英语\t\t姓名\t\t性别\t\t专业\n");
						printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
						return 0;
					}
					p=p->next;  //指向下一节点 
				}
				if(p==NULL&&flag==1)
					return 0;
					if(p==NULL&&flag==0)  //说明遍历完整个链表仍没有此学生 
					{
						printf("\n没有该学生\n不小心输错请按1，不想执行了请按其他。\n");
						int n;
						scanf("%d",&n);
						if(n==1)
						goto here;
						else
					return 0;
					}
				break;
			case 3:
				printf("正在退出"); 
				return 0;
				break;
			default:
				printf("输入错误!\n");
				break;
				return 0;
		}
	}	
} 
//分类 
int student_system::Classify (link head)
{
	read(head);
	printf("\n\t\t**********************\n");
	printf("\n\t\t-----1.按专业分类-----\n");
	printf("\n\t\t-----2.按性别分类-----\n");
	printf("\n\t\t-----3.退出本菜单-----\n");
	printf("\n\t\t**********************\n");

		link head_t=head;
		link pre,p;
		link tail=NULL;
		int flag=0;
		printf("请输入您想进行哪项操作: ");
		int choice;
		scanf("%d",&choice);
		switch(choice)  //用switch语句对输入信息分情况讨论 
		{
			case 1:
				printf("\n\t\t********************************\n");
				printf("\n\t\t-----1.将所有学生按专业分类-----\n");
				printf("\n\t\t-----2.输出某专业的所有学生-----\n");
				printf("\n\t\t-----3.退出本菜单---------------\n");
				printf("\n\t\t********************************\n");
				printf("请输入您想进行哪项操作: ");
				int n;
				scanf("%d",&n);
			switch(n)
			{
				case 1:
					while(head_t->next!=tail)//传入的是带头节点的链表,为了简便操作头节点未赋值,所以从head->next开始
				{
					pre=head;
					p=head->next;
					while (p->next != tail)
					{
						if(strcmp(p->major,p->next->major)>0)  //如果前一个节点的major的字典序大于后一个的，则两节点互换地址
						{
							pre->next = p->next;
							p->next = pre->next->next;
							pre->next->next = p;
						}
						else
						{
							p = p->next;   //指向下一节点 
						}	
						pre = pre->next;
					}
					tail=p;
				}
				print(head);
				break;
				case 2:
there:				printf("您想获取哪个专业的学生?\n");
					char s1[20];
					scanf("%s",s1);
					p=head->next;
					while(p)  //只要不到尾节点就持续遍历 
					{
						if(strcmp(p->major,s1)==0)  //比较输入的major与链表中每个节点major的字典序是否相等 
						{
							flag=1;
							printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
						}
						p=p->next;  //指向下一节点 
					}
					if(p==NULL&&flag==1)
					return 0;
					if(p==NULL&&flag==0) //说明遍历完整个链表仍没有此学生 
					{
						printf("系统并未存储此类学生信息！\n不小心输错请按1，不想执行了请按其他。\n");
						int n;
						scanf("%d",&n);
						if(n==1)
						goto there;
						else
					return 0;
				}
					break;
			case 3:
				return 0;
				break;
			default:
				printf("输入错误!\n");
				break;
				return 0;
		}
			break;
			case 2:
				printf("\n\t\t********************************\n");
				printf("\n\t\t-----1.将所有学生按性别分类-----\n");
				printf("\n\t\t-----2.输出某性别的所有学生-----\n");
				printf("\n\t\t-----3.退出本菜单---------------\n");
				printf("\n\t\t********************************\n");
				printf("请输入您想进行哪项操作: ");
				int n2;
				scanf("%d",&n2);
				fflush(stdin);
				switch(n2)
				{
					case 1:
					while(head_t->next!=tail)//传入的是带头节点的链表,为了简便操作头节点未赋值,所以从head->next开始
					{
						pre=head;
						p=head->next;
						while (p->next != tail)
						{
							if(strcmp(p->sex,p->next->sex)>0)  //如果前一个节点的sex的字典序大于后一个的，则两节点互换地址
							{
								pre->next = p->next;
								p->next = pre->next->next;
								pre->next->next = p;
							}
							else
							{
								p = p->next;   //指向下一节点 
							}	
							pre = pre->next;
						}
						tail=p;
					}
					print(head);
					break;
					case 2:
						
come:					printf("您想获取什么性别的学生?\n");
						char s1[20];
						scanf("%s",s1);
						p=head->next;
						while(p)  //只要不到尾节点就持续遍历 
						{
							if(strcmp(p->sex,s1)==0)  //比较输入的sex与链表中每个节点sex的字典序是否相等 
							{
								flag=1;
								printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
							}
							p=p->next;  //指向下一节点 
						}
						if(p==NULL&&flag==1)
						return 0;
						if(p==NULL&&flag==0) //说明遍历完整个链表仍没有此学生 
						{
							printf("系统并未存储此类学生信息！\n");
							goto come;
						}
						break;
					case 3:
						return 0;
						break;
					default:
						printf("输入错误!\n");
						break;
						return 0;
				}		
				break;
			case 3:
				return 0;
				break;
			default:
				printf("输入错误");
				return 0;
				break;
		}
}
//删除 
int student_system::Del (link head)    
{
	read(head);
there:
	printf("请输入您想删除的学生英语入学成绩："); 
	int num;
	scanf("%d",&num);
	link head_t=head,q;
	while(head_t->next)  //不为NULL时持续遍历 
	{
		if(head_t->next->score==num) //直到找到score为num的那个节点 
		{
			q=head_t->next;
			head_t->next=q->next;
			free(q);  //释放空间 
			printf("\n删除成功！\n");
			n--;
			printf("\n删除后:\n");
			write_wb(head);  //把数据写入文件中 
			print(head);     //打印修改后的数据
			return 0;
		}
		head_t=head_t->next; //开始看下一节点 
	}
	if(head_t->next==NULL) //说明遍历完整个链表仍没有此学生 
	{
		printf("没有该学生\n不小心输错请按1，不想执行了请按其他。\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		goto there;
		else
		return 0;
	}
}
//修改
int student_system::Modify(link head) 
{
	read(head);
there:
	printf("\n\n请输入您想修改的学生的学号：");
	int num;
	scanf("%d",&num);
	link p=head;
	while(p)           //p不为NULL时持续遍历 
	{
		if(p->score==num) //直到找到score为num的那个节点 
		{
			printf("英语成绩\t\t姓名\t\t性别\t\t专业\n");
			printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
			printf("请输入姓名：\n");
			scanf("%s",p->name);
			printf("请输入性别：\n");
 			scanf("%s",p->sex);
			printf("请输入专业：\n");
			scanf("%s",p->major);
			printf("修改后：\n");
			write_wb(head); //把数据写入文件中 
			print(head);   //打印修改后的数据
			return 0;
		}
		p=p->next;  //把下一个节点的地址赋值给p 
	}
	if(p==NULL)
	{
		printf("没有该学生\n\n不小心输错请按1，不想执行了请按其他。\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		goto there;  //用goto语句返回最初输入学号界面，让用户重新输入 
		else
		return 0;
	}	
 } 
//将数据写入文件
void student_system::write_wb(link head)
{
	FILE *fp;
	fp=fopen("学管.txt","w");  //w--创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。
	link p=head->next;
	if(!fp)
	{
		printf("error");
		exit(0);  //作用：清空文件缓冲区,关闭文件，终止当前程序运行，返回操作系统；
	}
	while(p!=NULL)
	{
		fprintf(fp,"%d %s %s %s\n",p->score,p->name,p->sex,p->major); //把数据存入文件 
		p=p->next;
	}
	fclose(fp);  //关闭文件 相当于保存文件
}
//从文件中读取数据
void student_system::read(link head)
{
	FILE *fp;
	fp=fopen("学管.txt","r");  //r--打开一个用于读取的文件，该文件必须存在。
	if(!fp)  //如果打开文件失败，则fopen函数返回一个空指针 
	{
		printf("error");
		exit(0);  //作用：清空文件缓冲区,关闭文件，终止当前程序运行，返回操作系统；
	}  
	link p,q1;
	p=q1=head;
	while(!feof(fp))
	{
		q1=(link)malloc(LEN);
		fscanf(fp,"%d %s %s %s\n",&q1->score,q1->name,q1->sex,q1->major); //从文件中读取数据 
		p->next=q1;
		p=q1;
	}
	p->next=NULL;
	fclose(fp);  //关闭文件 相当于保存文件
	return ;
}
