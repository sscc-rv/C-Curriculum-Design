#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define LEN sizeof(struct student)  //����ʹ�ã�ʹ�������࣬��"LEN"����"sizeof(struct student)"
using namespace std;
int n;//��ʾѧ������ 
//�����ṹ�� 
typedef struct student{
	int score;
	char name[12];
	char sex[5];
	char major[20];//רҵ 
	struct student *next;
}*link;
//������ 
class student_system
{
public:
	//�������� 
	static int Login();              //��¼
	static void Menu();              //�˵� 
	static int input(link head);     //¼�� 
	static void Sort(link head);     //���� 
	static int  Search(link head);   //��ѯ 
	static int Classify(link head);  //���� 
	static int Del(link head) ;      //ɾ�� 
	static int Modify(link head);    //�޸�
	static int print(link head);     //��ӡ 
	static void write_wb(link head); //������д���ļ� 
	static void read(link head);     //���ļ��ж�ȡ���� 
};
//��������
link creat()
{
	link head=NULL;         //ͷ�ڵ�ָ�룬��Ϊ��ָ���һ���ڵ㣬��Ȼ�ڵ�ᶪʧ
	head=(link)malloc(LEN); //�ڶ������ٿռ� 
	if(head==NULL)          //�������������ָ�����ͣ�������һ��ɹ���ʱ�򷵻���Ӧ�ĵ�ַ��ʧ�ܵ�ʱ�򷵻�NULL
	{
		printf("�ڴ�������");
		return NULL;
	} 
	memset(head,0,LEN); //��head��ʼ�� 
	head->next=NULL;    //��headָ���nextָ�븳ֵΪ�� 
	return head;
}
int main()
{
	system("color F0"); //�ı����̨��ɫ 
	link stu,p;
	link head;          //��������
	head=creat();
	student_system::Login();
start:
	while(1)
	{
		student_system::Menu ();
		printf("����ִ��ʲô������");
		int choice;
		scanf("%d",&choice);
		switch(choice)   //��switch����������Ϣ��������� 
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
				printf("�ݰ�~,ϣ����������в���̫��\n");
				system("pause");
				system("cls");
				return 0;
				break;
			default:
				printf("������˼....��ª����û���������\n\n");
				printf("����ǲ�С��������ǾͰ�1,����ִ�����밴����.\n");
				int n;
				scanf("%d",&n);
				if(n==1)
				goto start; 
				else
				{
					printf("�ݰ�~");
					return 0;
				}
				system("pause"); //��ͣ 
				break;
		}
	}	
}
//��¼ 
void Cat()  //ʹ��������� 
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
	printf("  ', |,||,|,','      ',          ,'                ҳ�������...\t\t\tCode by rv\n ");
	int num=100;
	while (num--)  //ʹ��~��ֱ���𽥼��س��� 
	{
		printf("~");
		Sleep(14); 
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t   ���سɹ���\n\n");
	Sleep(700);
start:
	if (flag) Cat();  //ʹ�û������һ���˺ź�ҳ�����Ϸ�����Сè���Ϲ� 
	cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t----- ����������Ϣͳ����� -----"<<endl;
	cout<<"\t\t\t\t\t------                    ------"<<endl;
	cout<<"\t\t\t\t\t--------- �û���¼ҳ�� ---------"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\n\n\n\t\t\t\t�������������֤���룺";
	flag=1;
	char ID[18]={'\0'},temp[6]={'\0'},password[6]={'\0'};
	gets(ID);           //�������֤�� 
	if(strlen(ID)!=18)  //�����֤���Ƿ���18λ���� 
	{
		printf("\n\t\t\t\t����ˣ�����������֤�Ų���18λѽ\n");
		printf("\n\t\t\t\t����������\n"); 
		system("pause"); 
		system("cls"); //���� 
		goto start;   //���ص�½ҳ�� 
	}
	else
	{
		int i;
		int ans=0;
		
		for(i=12;i<18;i++) 
			temp[ans++]=ID[i];  //����һ�����鱣�����֤����λ 
	
		for(i=0;i<3;i++)  //�����ݴ���� 
		{
			printf("\n\t\t\t\t����������(��ʼ����Ϊ���֤�����6λ)��");
			gets(password);
			if(strcmp(password,temp)==0)
			{
				printf("\n\t\t\t\t������ȷ!������½");
				Sleep(500);  //ʹ��.��ֱ���𽥼��س��� 
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
		printf("\n\t\t\t\t����ˣ�������%d�λ���\n\n",2-i);
	}
	printf("\n\t\t\t\t�ݰ�~");
	exit(0);  //exit()--�˳�   0--�����˳�  ����--�������˳� 
	} 
}
//�˵� 
void student_system::Menu()
{ 
	printf("\n\t\t*********************************\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t����������Ϣͳ�����    *\n");
	printf("\t\t*\t                        *");
	//printf("\n\t\t*\t����ִ��ʲô����?       *\n");
	//printf("\t\t*\t                        *");
	printf("\n\t\t*\t1.¼��ѧ����Ϣ          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t2.��Ӣ����ѧ�ɼ�����    *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t3.��ѯѧ����Ϣ          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t4.��ѧ����Ϣ����        *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t5.ɾ��ѧ����Ϣ          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t6.�޸�ѧ����Ϣ          *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*\t7.���沢�˳�ϵͳ        *\n");
	printf("\t\t*\t                        *");
	printf("\n\t\t*********************************\n"); 
}
//¼�뺯�� 
int student_system::input(link head)
{
	link new_node;
	link head_t=head;
	new_node=NULL;
	new_node=(link)malloc(LEN);
	if(new_node==NULL)
	{
		printf("�ڴ�������");
		return -1;
	}
	while(head_t->next!=NULL)
	{
		head_t=head_t->next;
	} 
	head_t->next=new_node;
	FILE *fp;
	fp=fopen("ѧ��.txt","a+"); //��һ�����ڶ�ȡ��׷�ӵ��ļ� 
	if(!fp)                    //fopen��������һ�� FILE ָ�롣���򷵻� NULL
	{
		printf("error");
		exit(0);
	}
	printf("������Ӣ����ѧ�ɼ���");
	scanf("%d",&new_node->score);
	printf("������������");
	getchar();
	gets(new_node->name);
	printf("�������Ա�");
 	gets(new_node->sex);
	printf("������רҵ��");
	gets(new_node->major);
	new_node->next=NULL;
	printf("\n¼��ɹ�!\n\n");
	Sleep(800);   //��ͣ800���� 
	n++;
	fprintf(fp,"%d %s %s %s\n",new_node->score,new_node->name,new_node->sex,new_node->major);
	fclose(fp);  //�ر��ļ� �൱�ڱ����ļ�
	return 0;
}
//��ӡ 
int student_system::print(link head)
{
	read(head);
	link p=head->next;
	printf("Ӣ��\t\t����\t\t�Ա�\t\tרҵ\n");
	/*��������ʱ��Ϊʲô��ֱ��ʹ��headָ���Ҫ���´���һ����ָ�룿
	��Ϊ���ʹ��head����ı�head�е�ֵ��������Ҳ�������Ŀ�ʼ��*/
	while(p)
	{
		printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
		p=p->next; 
	} 
	return 0;
}
//���� 
void student_system::Sort(link head)
{
	read(head);
	link head_t=head;
	link pre,p;
	link tail=NULL;
	while(head_t->next!=tail)//������Ǵ�ͷ�ڵ������,Ϊ�˼�����ͷ�ڵ�δ��ֵ,���Դ�head->next��ʼ
	{
		pre=head;
		p=head->next;
		while (p->next != tail)
		{
			if (p->score < p->next->score)  //���ǰһ���ڵ��scoreС�ں�һ���ڵ��score�ģ������ڵ㻥����ַ 
			{
				pre->next = p->next;
				p->next = pre->next->next;
				pre->next->next = p;
			}
			else
			{
				p = p->next;  //ָ����һ�ڵ� 
			}
				pre = pre->next;
		}
		tail=p;
	}
	printf("�����:\n");
	write_wb(head); //�����ݴ����ļ��� 
	print(head);    //��ӡ��������� 
}
//��ѯ 
int student_system::Search(link head) 
{
	read(head);
		int i;
	link p=head->next;
	int num;
	int flag=0;
	char s[20];
	printf("\n\t\t**********************\n");
	printf("\n\t\t-1.��Ӣ����ѧ�ɼ���ѯ-\n");
	printf("\n\t\t-----2.��������ѯ-----\n");
	printf("\n\t\t-----3.�˳����˵�-----\n");
	printf("\n\t\t**********************\n");
	while(1)
	{
		printf("\n��������������������: ");
		int choice;
		scanf("%d",&choice);
		switch(choice)  //��switch����������Ϣ��������� 
		{
			case 1:
there:			printf("\n�����������ѯ��ѧ��Ӣ����ѧ�ɼ�: ");  //�Ƚ������id��������ÿ���ڵ�id���ֵ����Ƿ����
				scanf("%d",&num);
				p=head->next;
				while(p)
				{
					if(p->score==num)
					{
						flag=1;
						printf("Ӣ��\t\t����\t\t�Ա�\t\tרҵ\n");
						printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
						Sleep(1000);
						return 0;
					 } 
					p=p->next;   //ָ����һ�ڵ� 
				}
				if(p==NULL&&flag==1)
					return 0;
					if(p==NULL&&flag==0)  //˵������������������û�д�ѧ�� 
					{
						printf("\nû�и�ѧ��\n��С������밴1������ִ�����밴������\n");
						int n;
						scanf("%d",&n);
						if(n==1)
						goto there;
						else
					return 0;
					}
				break;
			case 2:
here:			printf("\n�����������ѯ��ѧ������: ");
				scanf("%s",s);
				p=head->next;
				while(p) //ֻҪ����β�ڵ�ͳ������� 
				{
					if(strcmp(p->name,s)==0)  //�Ƚ������name��������ÿ���ڵ�name���ֵ����Ƿ���� 
					{
						flag=1;
						printf("Ӣ��\t\t����\t\t�Ա�\t\tרҵ\n");
						printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
						return 0;
					}
					p=p->next;  //ָ����һ�ڵ� 
				}
				if(p==NULL&&flag==1)
					return 0;
					if(p==NULL&&flag==0)  //˵������������������û�д�ѧ�� 
					{
						printf("\nû�и�ѧ��\n��С������밴1������ִ�����밴������\n");
						int n;
						scanf("%d",&n);
						if(n==1)
						goto here;
						else
					return 0;
					}
				break;
			case 3:
				printf("�����˳�"); 
				return 0;
				break;
			default:
				printf("�������!\n");
				break;
				return 0;
		}
	}	
} 
//���� 
int student_system::Classify (link head)
{
	read(head);
	printf("\n\t\t**********************\n");
	printf("\n\t\t-----1.��רҵ����-----\n");
	printf("\n\t\t-----2.���Ա����-----\n");
	printf("\n\t\t-----3.�˳����˵�-----\n");
	printf("\n\t\t**********************\n");

		link head_t=head;
		link pre,p;
		link tail=NULL;
		int flag=0;
		printf("��������������������: ");
		int choice;
		scanf("%d",&choice);
		switch(choice)  //��switch����������Ϣ��������� 
		{
			case 1:
				printf("\n\t\t********************************\n");
				printf("\n\t\t-----1.������ѧ����רҵ����-----\n");
				printf("\n\t\t-----2.���ĳרҵ������ѧ��-----\n");
				printf("\n\t\t-----3.�˳����˵�---------------\n");
				printf("\n\t\t********************************\n");
				printf("��������������������: ");
				int n;
				scanf("%d",&n);
			switch(n)
			{
				case 1:
					while(head_t->next!=tail)//������Ǵ�ͷ�ڵ������,Ϊ�˼�����ͷ�ڵ�δ��ֵ,���Դ�head->next��ʼ
				{
					pre=head;
					p=head->next;
					while (p->next != tail)
					{
						if(strcmp(p->major,p->next->major)>0)  //���ǰһ���ڵ��major���ֵ�����ں�һ���ģ������ڵ㻥����ַ
						{
							pre->next = p->next;
							p->next = pre->next->next;
							pre->next->next = p;
						}
						else
						{
							p = p->next;   //ָ����һ�ڵ� 
						}	
						pre = pre->next;
					}
					tail=p;
				}
				print(head);
				break;
				case 2:
there:				printf("�����ȡ�ĸ�רҵ��ѧ��?\n");
					char s1[20];
					scanf("%s",s1);
					p=head->next;
					while(p)  //ֻҪ����β�ڵ�ͳ������� 
					{
						if(strcmp(p->major,s1)==0)  //�Ƚ������major��������ÿ���ڵ�major���ֵ����Ƿ���� 
						{
							flag=1;
							printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
						}
						p=p->next;  //ָ����һ�ڵ� 
					}
					if(p==NULL&&flag==1)
					return 0;
					if(p==NULL&&flag==0) //˵������������������û�д�ѧ�� 
					{
						printf("ϵͳ��δ�洢����ѧ����Ϣ��\n��С������밴1������ִ�����밴������\n");
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
				printf("�������!\n");
				break;
				return 0;
		}
			break;
			case 2:
				printf("\n\t\t********************************\n");
				printf("\n\t\t-----1.������ѧ�����Ա����-----\n");
				printf("\n\t\t-----2.���ĳ�Ա������ѧ��-----\n");
				printf("\n\t\t-----3.�˳����˵�---------------\n");
				printf("\n\t\t********************************\n");
				printf("��������������������: ");
				int n2;
				scanf("%d",&n2);
				fflush(stdin);
				switch(n2)
				{
					case 1:
					while(head_t->next!=tail)//������Ǵ�ͷ�ڵ������,Ϊ�˼�����ͷ�ڵ�δ��ֵ,���Դ�head->next��ʼ
					{
						pre=head;
						p=head->next;
						while (p->next != tail)
						{
							if(strcmp(p->sex,p->next->sex)>0)  //���ǰһ���ڵ��sex���ֵ�����ں�һ���ģ������ڵ㻥����ַ
							{
								pre->next = p->next;
								p->next = pre->next->next;
								pre->next->next = p;
							}
							else
							{
								p = p->next;   //ָ����һ�ڵ� 
							}	
							pre = pre->next;
						}
						tail=p;
					}
					print(head);
					break;
					case 2:
						
come:					printf("�����ȡʲô�Ա��ѧ��?\n");
						char s1[20];
						scanf("%s",s1);
						p=head->next;
						while(p)  //ֻҪ����β�ڵ�ͳ������� 
						{
							if(strcmp(p->sex,s1)==0)  //�Ƚ������sex��������ÿ���ڵ�sex���ֵ����Ƿ���� 
							{
								flag=1;
								printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
							}
							p=p->next;  //ָ����һ�ڵ� 
						}
						if(p==NULL&&flag==1)
						return 0;
						if(p==NULL&&flag==0) //˵������������������û�д�ѧ�� 
						{
							printf("ϵͳ��δ�洢����ѧ����Ϣ��\n");
							goto come;
						}
						break;
					case 3:
						return 0;
						break;
					default:
						printf("�������!\n");
						break;
						return 0;
				}		
				break;
			case 3:
				return 0;
				break;
			default:
				printf("�������");
				return 0;
				break;
		}
}
//ɾ�� 
int student_system::Del (link head)    
{
	read(head);
there:
	printf("����������ɾ����ѧ��Ӣ����ѧ�ɼ���"); 
	int num;
	scanf("%d",&num);
	link head_t=head,q;
	while(head_t->next)  //��ΪNULLʱ�������� 
	{
		if(head_t->next->score==num) //ֱ���ҵ�scoreΪnum���Ǹ��ڵ� 
		{
			q=head_t->next;
			head_t->next=q->next;
			free(q);  //�ͷſռ� 
			printf("\nɾ���ɹ���\n");
			n--;
			printf("\nɾ����:\n");
			write_wb(head);  //������д���ļ��� 
			print(head);     //��ӡ�޸ĺ������
			return 0;
		}
		head_t=head_t->next; //��ʼ����һ�ڵ� 
	}
	if(head_t->next==NULL) //˵������������������û�д�ѧ�� 
	{
		printf("û�и�ѧ��\n��С������밴1������ִ�����밴������\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		goto there;
		else
		return 0;
	}
}
//�޸�
int student_system::Modify(link head) 
{
	read(head);
there:
	printf("\n\n�����������޸ĵ�ѧ����ѧ�ţ�");
	int num;
	scanf("%d",&num);
	link p=head;
	while(p)           //p��ΪNULLʱ�������� 
	{
		if(p->score==num) //ֱ���ҵ�scoreΪnum���Ǹ��ڵ� 
		{
			printf("Ӣ��ɼ�\t\t����\t\t�Ա�\t\tרҵ\n");
			printf("%d\t\t%s\t\t%s\t\t%s\n",p->score,p->name,p->sex,p->major);
			printf("������������\n");
			scanf("%s",p->name);
			printf("�������Ա�\n");
 			scanf("%s",p->sex);
			printf("������רҵ��\n");
			scanf("%s",p->major);
			printf("�޸ĺ�\n");
			write_wb(head); //������д���ļ��� 
			print(head);   //��ӡ�޸ĺ������
			return 0;
		}
		p=p->next;  //����һ���ڵ�ĵ�ַ��ֵ��p 
	}
	if(p==NULL)
	{
		printf("û�и�ѧ��\n\n��С������밴1������ִ�����밴������\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		goto there;  //��goto��䷵���������ѧ�Ž��棬���û��������� 
		else
		return 0;
	}	
 } 
//������д���ļ�
void student_system::write_wb(link head)
{
	FILE *fp;
	fp=fopen("ѧ��.txt","w");  //w--����һ������д��Ŀ��ļ�������ļ��������Ѵ��ڵ��ļ���ͬ�����ɾ�������ļ������ݣ��ļ�����Ϊһ���µĿ��ļ���
	link p=head->next;
	if(!fp)
	{
		printf("error");
		exit(0);  //���ã�����ļ�������,�ر��ļ�����ֹ��ǰ�������У����ز���ϵͳ��
	}
	while(p!=NULL)
	{
		fprintf(fp,"%d %s %s %s\n",p->score,p->name,p->sex,p->major); //�����ݴ����ļ� 
		p=p->next;
	}
	fclose(fp);  //�ر��ļ� �൱�ڱ����ļ�
}
//���ļ��ж�ȡ����
void student_system::read(link head)
{
	FILE *fp;
	fp=fopen("ѧ��.txt","r");  //r--��һ�����ڶ�ȡ���ļ������ļ�������ڡ�
	if(!fp)  //������ļ�ʧ�ܣ���fopen��������һ����ָ�� 
	{
		printf("error");
		exit(0);  //���ã�����ļ�������,�ر��ļ�����ֹ��ǰ�������У����ز���ϵͳ��
	}  
	link p,q1;
	p=q1=head;
	while(!feof(fp))
	{
		q1=(link)malloc(LEN);
		fscanf(fp,"%d %s %s %s\n",&q1->score,q1->name,q1->sex,q1->major); //���ļ��ж�ȡ���� 
		p->next=q1;
		p=q1;
	}
	p->next=NULL;
	fclose(fp);  //�ر��ļ� �൱�ڱ����ļ�
	return ;
}
