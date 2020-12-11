#include <stdio.h>				
#include <stdlib.h>				/*标准输入输出函数*/
#include <string.h>
#include <stddef.h>
#include <windows.h>
#include <time.h>				/*时间函数*/
#include "conio.h"
#define N 3					/*定义数据库容量（人数）*/

struct 	stusys
{
	char num[50];				/*定义学号*/
	char name[50];				/*定义姓名*/
	char password[50];			/*定义密码*/
	char department[50];		/*定义系别*/
	char time[10];				/*定义存入的机时*/
	char ontime[10];			/*定义上机时间*/
	char offtime[10];			/*定义下机时间*/
	char jishi[10];
	char chong[10];
	int  find;					/*定义标志变量*/
}stu[N];

char n;
long  a,b,c,d;
void input();					/*录入学生信息*/
long online();					/*上机时间*/
void offline();					/*下机时间*/
void yucun();					/*预存机时*/

void main()
{
	while(1)
	{
       system("cls");
       printf("\n       ********************* 欢迎来到机房上机系统******************** ");
   	   printf("\n				1.教师管理.");
	   printf("\n				2.学生使用.");
   	   printf("\n				3.退出程序.");
	   printf("\n您想要（请输入您需要的序号，按回车键确认）：");
	   scanf("%c",&n);								/*实现功能选择*/
		  if(n>'3'||n<'1')
		  {
			do
			{
				scanf("%c",&n);
			}
			while(n>'3'||n<'1');
		  }
		  switch(n)
		  {
		     case '1':
			{
			system("cls");					
			printf("\n       ********************* 欢迎来到教师管理系统******************** ");
			printf("\n                               1.数据信息录入.");
			printf("\n                               2.预存机时.");
			printf("\n                               3.退出程序.\n");
			printf("\n您想要（请输入您需要的序号，按回车键确认）：");
			scanf("%c",&n);								/*实现功能选择*/
				if(n>'3'||n<'1')
				{
					do
					{
						scanf("%c",&n);
					}
					while(n>'3'||n<'1');
				}
				switch(n)
				{
				case'1':input();break;
				case'2':yucun(); break;
				case'3':printf("退出程序.\n");
				    	exit(0);
				}
			}break;
		case '2':
			{
			system("cls");					
			printf("\n");
			printf("       ********************* 欢迎来到学生使用系统******************** ");
			printf("\n                             1.输入学号上机.");
			printf("\n                             2.输入学号下机.");
			printf("\n                             3.预存机时.");
			printf("\n                             4.退出程序.\n");
			printf("\n您想要（请输入您需要的序号，按回车键确认）：");
			scanf("%c",&n);							
				if(n>'4'||n<'1')
				{	
					do
					{
						scanf("%c",&n);
					}
					while(n>'4'||n<'1');
				}
			switch(n)
			{
			case'1':online();break;
			case'2':offline();break;
			case'3':yucun(); break;
			case'4':
				{
					printf("退出程序.\n"); 
					exit(0);
				}
			}break;
			}
		case '3':
			{
				printf("退出程序.\n");
				system("pause");
				exit(0);
			}
		  }
	  }
}

void input()					/*录入数据信息函数*/
{
	FILE *fp;
	int i=0;
	system("cls");				
	printf("       ********************* 数据信息录入******************** \n");
		printf("请输入账号:\t");
		scanf("\n%s",stu[i].num);
		printf("请输入密码:\t");
		scanf("\n%s",stu[i].password);
		printf("请输入系别:\t");
		scanf("\n%s",stu[i].department);
		printf("请输入姓名:\t");
		scanf("\n%s",stu[i].name);
		printf("请输入存入时间:\t");
		scanf("\n%s",stu[i].time);	
		stu[i].find =0;
	if((fp=fopen("E:\\computer.txt","a+"))==NULL)
    {
		printf("文件打开失败！请检查信息是否存在。\n");
		exit(0);
	}
    fwrite(stu,250,N,fp);			/*将信息存入文件*/
    fclose(fp);
	printf("录入成功!返回主菜单!\n");
	Sleep(3000);
}

long online(long a)						/*定义上机签到函数*/
{
	FILE *fp;
	int i;
	char num1[50];
	char password[50];
    if((fp=fopen("E:\\computer.txt","a+"))==NULL)
    {
		printf("文件打开失败！请检查信息是否存在。\n");
		exit(0);
	}
	system("cls");			
	printf("       ********************* 上机签到******************** \n");
	printf("请输入账号:\t");
	scanf("\n%s",num1);
	printf("请输入密码:\t");
	scanf("\n%s",password);
	a=time(NULL);
    //printf("上机时长：%ld",a);
	for(i=0;i<N;i++)				/*查找，显示信息*/
	{
		if(strcmp(stu[i].num,num1)==0)
		{
			stu[i].find=1;
			if(stu[i].find==1)
			{
				printf("该学生已上机!\n");
			}
			if(stu[i].time<=0)
            {
				printf("存入机时不足!\n");
			}
			    printf("你的账号:%s\t剩余机时:%s(分钟)\n",stu[i].num,stu[i].time);
		}
	}
	system("pause");
	fclose(fp);
	return a;
}

void offline(long a)					/*定义下机处理函数*/
{	FILE *fp;
    char num1[50];
	system("cls");				
	printf("       ********************* 下机处理******************** \n");
	printf("请输入你的账号:");
	scanf("%c\n",num1);
    printf("该学生已下机!\n");
	if((fp=fopen("E:\\computer.txt","r+"))==NULL)
    {
		printf("文件打开失败！请检查信息是否存在。\n");
		exit(0);
	}
	b=time(NULL);
	c=(b-a)/60;
	/*printf("try:%ld\n",a);
	printf("try:%ld\n",b);*/
	printf("上机时长：%ld",c);
	printf("			\n已下机!\n");
	system("pause");
	fclose(fp);
}

void yucun()				/*定义预存机时函数*/
{
	FILE *fp;
	char num[50];
	int a,b,c;
    system("cls");	
	fp=fopen("E:\\computer.txt","a+");
	printf("       ********************* 预存机时******************** \n");
	printf("\n请输入待查询的学生学号(按回车键确认):\n");
	scanf("%s",num);
	printf("你的账号:%s\t剩余机时:%s(分钟)\n",num,stu[0].time);
	if(strcmp(stu[0].num,num)==0)
	printf("\n\t请输入所充机时:");
	scanf("\n%s",stu[0].chong);	
	a=atoi(stu[0].time);
	b=atoi(stu[0].chong);
	c=a+b;
	printf("你的账号:%s\t剩余机时:%d(分钟)\n",num,c);
	itoa(c,stu[0].time,10);
	fwrite(&stu[0].time,sizeof(struct stusys),1,fp);
	printf("\n\t充值成功!\n");
	printf("3秒后自动跳转回主界面。\n");
	fclose(fp);
	Sleep(3000);
}