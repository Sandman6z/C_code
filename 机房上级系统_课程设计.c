#include <stdio.h>				
#include <stdlib.h>				/*��׼�����������*/
#include <string.h>
#include <stddef.h>
#include <windows.h>
#include <time.h>				/*ʱ�亯��*/
#include "conio.h"
#define N 3					/*�������ݿ�������������*/

struct 	stusys
{
	char num[50];				/*����ѧ��*/
	char name[50];				/*��������*/
	char password[50];			/*��������*/
	char department[50];		/*����ϵ��*/
	char time[10];				/*�������Ļ�ʱ*/
	char ontime[10];			/*�����ϻ�ʱ��*/
	char offtime[10];			/*�����»�ʱ��*/
	char jishi[10];
	char chong[10];
	int  find;					/*�����־����*/
}stu[N];

char n;
long  a,b,c,d;
void input();					/*¼��ѧ����Ϣ*/
long online();					/*�ϻ�ʱ��*/
void offline();					/*�»�ʱ��*/
void yucun();					/*Ԥ���ʱ*/

void main()
{
	while(1)
	{
       system("cls");
       printf("\n       ********************* ��ӭ���������ϻ�ϵͳ******************** ");
   	   printf("\n				1.��ʦ����.");
	   printf("\n				2.ѧ��ʹ��.");
   	   printf("\n				3.�˳�����.");
	   printf("\n����Ҫ������������Ҫ����ţ����س���ȷ�ϣ���");
	   scanf("%c",&n);								/*ʵ�ֹ���ѡ��*/
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
			printf("\n       ********************* ��ӭ������ʦ����ϵͳ******************** ");
			printf("\n                               1.������Ϣ¼��.");
			printf("\n                               2.Ԥ���ʱ.");
			printf("\n                               3.�˳�����.\n");
			printf("\n����Ҫ������������Ҫ����ţ����س���ȷ�ϣ���");
			scanf("%c",&n);								/*ʵ�ֹ���ѡ��*/
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
				case'3':printf("�˳�����.\n");
				    	exit(0);
				}
			}break;
		case '2':
			{
			system("cls");					
			printf("\n");
			printf("       ********************* ��ӭ����ѧ��ʹ��ϵͳ******************** ");
			printf("\n                             1.����ѧ���ϻ�.");
			printf("\n                             2.����ѧ���»�.");
			printf("\n                             3.Ԥ���ʱ.");
			printf("\n                             4.�˳�����.\n");
			printf("\n����Ҫ������������Ҫ����ţ����س���ȷ�ϣ���");
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
					printf("�˳�����.\n"); 
					exit(0);
				}
			}break;
			}
		case '3':
			{
				printf("�˳�����.\n");
				system("pause");
				exit(0);
			}
		  }
	  }
}

void input()					/*¼��������Ϣ����*/
{
	FILE *fp;
	int i=0;
	system("cls");				
	printf("       ********************* ������Ϣ¼��******************** \n");
		printf("�������˺�:\t");
		scanf("\n%s",stu[i].num);
		printf("����������:\t");
		scanf("\n%s",stu[i].password);
		printf("������ϵ��:\t");
		scanf("\n%s",stu[i].department);
		printf("����������:\t");
		scanf("\n%s",stu[i].name);
		printf("���������ʱ��:\t");
		scanf("\n%s",stu[i].time);	
		stu[i].find =0;
	if((fp=fopen("E:\\computer.txt","a+"))==NULL)
    {
		printf("�ļ���ʧ�ܣ�������Ϣ�Ƿ���ڡ�\n");
		exit(0);
	}
    fwrite(stu,250,N,fp);			/*����Ϣ�����ļ�*/
    fclose(fp);
	printf("¼��ɹ�!�������˵�!\n");
	Sleep(3000);
}

long online(long a)						/*�����ϻ�ǩ������*/
{
	FILE *fp;
	int i;
	char num1[50];
	char password[50];
    if((fp=fopen("E:\\computer.txt","a+"))==NULL)
    {
		printf("�ļ���ʧ�ܣ�������Ϣ�Ƿ���ڡ�\n");
		exit(0);
	}
	system("cls");			
	printf("       ********************* �ϻ�ǩ��******************** \n");
	printf("�������˺�:\t");
	scanf("\n%s",num1);
	printf("����������:\t");
	scanf("\n%s",password);
	a=time(NULL);
    //printf("�ϻ�ʱ����%ld",a);
	for(i=0;i<N;i++)				/*���ң���ʾ��Ϣ*/
	{
		if(strcmp(stu[i].num,num1)==0)
		{
			stu[i].find=1;
			if(stu[i].find==1)
			{
				printf("��ѧ�����ϻ�!\n");
			}
			if(stu[i].time<=0)
            {
				printf("�����ʱ����!\n");
			}
			    printf("����˺�:%s\tʣ���ʱ:%s(����)\n",stu[i].num,stu[i].time);
		}
	}
	system("pause");
	fclose(fp);
	return a;
}

void offline(long a)					/*�����»�������*/
{	FILE *fp;
    char num1[50];
	system("cls");				
	printf("       ********************* �»�����******************** \n");
	printf("����������˺�:");
	scanf("%c\n",num1);
    printf("��ѧ�����»�!\n");
	if((fp=fopen("E:\\computer.txt","r+"))==NULL)
    {
		printf("�ļ���ʧ�ܣ�������Ϣ�Ƿ���ڡ�\n");
		exit(0);
	}
	b=time(NULL);
	c=(b-a)/60;
	/*printf("try:%ld\n",a);
	printf("try:%ld\n",b);*/
	printf("�ϻ�ʱ����%ld",c);
	printf("			\n���»�!\n");
	system("pause");
	fclose(fp);
}

void yucun()				/*����Ԥ���ʱ����*/
{
	FILE *fp;
	char num[50];
	int a,b,c;
    system("cls");	
	fp=fopen("E:\\computer.txt","a+");
	printf("       ********************* Ԥ���ʱ******************** \n");
	printf("\n���������ѯ��ѧ��ѧ��(���س���ȷ��):\n");
	scanf("%s",num);
	printf("����˺�:%s\tʣ���ʱ:%s(����)\n",num,stu[0].time);
	if(strcmp(stu[0].num,num)==0)
	printf("\n\t�����������ʱ:");
	scanf("\n%s",stu[0].chong);	
	a=atoi(stu[0].time);
	b=atoi(stu[0].chong);
	c=a+b;
	printf("����˺�:%s\tʣ���ʱ:%d(����)\n",num,c);
	itoa(c,stu[0].time,10);
	fwrite(&stu[0].time,sizeof(struct stusys),1,fp);
	printf("\n\t��ֵ�ɹ�!\n");
	printf("3����Զ���ת�������档\n");
	fclose(fp);
	Sleep(3000);
}