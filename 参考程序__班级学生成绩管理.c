#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"conio.h"
#define N 20
struct student
{char num[20];
 char name[10];
 float english;
 float computer;
 float math;
};
void menu();
int reads(struct student stu[N]);
void save(struct student stu[N],int n);
void add();
void del();
void sort();
void query();
void change();
void show();
void main()
{
	int n;
    while(1)
	{ 
		menu();
        printf("\n ��������Ҫѡ��Ĳ�����ţ����س���ȷ�ϣ�");
        scanf("%d",&n);
        switch(n)
		{
			case 1: add();break;
            case 2: show();break;
            case 3: del();break;
            case 4: change();break;
            case 5: sort();break;
            case 6: query();break;
            case 7: exit(0);
            default:  printf("��������������б��д��ڵ���ţ�\n ");
		}
	}

}
void menu()
{
	printf("       ************************* �༶�ɼ�����ϵͳ************************ ");
    printf("\n                               1  ���ѧ������");
    printf("\n                               2  ��ʾѧ������");
    printf("\n                               3  ɾ��ѧ������");
    printf("\n                               4  ����ѧ������");
    printf("\n                               5  �ܳɼ�����");
    printf("\n                               6  �ɼ���ѯ");
    printf("\n                               7  �˳�");
}
int  reads(struct student stu[N]) // ��ȡѧ���ļ��е�����
{
 
	FILE *fp;
    int i=0;
    if((fp=fopen("e:\\student.txt","r"))==NULL)
	{ 
		printf("�ļ���ʧ�ܣ�\n");
        return 0;
	}
    else
	{
        for(i=0;!feof(fp);i++)
            fscanf(fp,"%s %s %f %f %f\n",stu[i].num,stu[i].name,&stu[i].english,&stu[i].computer,&stu[i].math);
		 
	}
    fclose(fp);
    return i;
}
void save(struct student stu[N],int n) // ѧ����Ϣ�ı������ļ�
{
	FILE *fp;
    int i=0;
    if((fp=fopen("e:\\student.txt","w"))==NULL)
	{ 
		printf("�ļ���ʧ�ܣ�\n");
        return ;
	}
    else
	{
        for(i=0;i<n;i++)
           fprintf(fp,"%s %s %f %f %f\n",stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math);
	}
    fclose(fp);
}
void add()/*���ѧ����Ϣ*/
{
	FILE *fp;
    int n,i;
    struct student stu;
    if((fp=fopen("e:\\student.txt","a"))==NULL)  //����ļ��Ѿ����ڣ�����׷��ѧ����Ϣ
	{
	    if((fp=fopen("e:\\student.txt","w"))==NULL) // �ļ�������ʱ���������ļ�������ѧ����Ϣ
		{ 
		    printf("�ļ���ʧ�ܣ�\n");
            return;
		}
	}
    printf("������Ҫ��ӵ�ѧ�����������س���ȷ�ϣ�"); 
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    { 
		printf("\n�������%d��ѧ����ѧ�š��������ÿո�ֿ��������س���ȷ�ϣ�\n",i);
        scanf("%s%s",stu.num,stu.name);
        printf("\n�������%d��ѧ����Ӣ����������ѧ���ųɼ����ÿո�ֿ��������س���ȷ�ϣ�\n",i);
        scanf("%f%f%f",&stu.english,&stu.computer,&stu.math);
        fprintf(fp,"%s %s %f %f %f\n",stu.num,stu.name,stu.english,stu.computer,stu.math);
		
	}
    fclose(fp);
}
void show() // ѧ����Ϣ��ʾ����
{
	struct student stu[N];
    int i,n;
    n=reads(stu);
    printf("*********************���е�ѧ����Ϣ����**********************\n\n");
	printf("  ���      ѧ��       ����     Ӣ��       �����     ��ѧ          \n");
    printf("*************************************************************\n"); 
	for(i=0;i<n;i++)
        printf("\n%3d%12s%11s%11.2f%11.2f%11.2f\n",i+1,stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math);
    getch();
}
void del()  /*ѧ����Ϣɾ������*/
{
	struct student stu[N];
    char number[20];
    int n,i,j;
    n=reads(stu);
    printf("\n������Ҫɾ����Ϣ��ѧ��ѧ�ţ����س���ȷ�ϣ�");
    scanf("%s",number);
    for(i=0;i<n;i++)
	    if(strcmp(number,stu[i].num)==0) break;
    if(i>=n)
	{
		printf("û���ҵ���ѧ����Ϣ��\n");
        return;
	}
    else
	{
		for(j=i+1;j<n;j++)
	        stu[j-1]=stu[j];
	}
    save(stu,n-1);
    printf("ɾ���ɹ���\n");
}
void change()  //ѧ����Ϣ����
{
	struct student stu[N];
    int n,i;
	char number[20];
    printf("\n������Ҫ������Ϣ��ѧ��ѧ�ţ����س���ȷ�ϣ�");
    scanf("%s",number);
    n=reads(stu);
    for(i=0;i<n;i++)
        if(strcmp(number,stu[i].num)==0)
	       break;
    if(i>=n)
	{
		printf("�޴�ѧ����Ϣ!");
        return;
	}
    printf("\n��������ĺ�ѧ����ѧ�ţ�������Ӣ����������ѧ���ųɼ������س���ȷ�ϣ�\n");
    scanf("%s%s%f%f%f",stu[i].num,stu[i].name,&stu[i].english,&stu[i].computer,&stu[i].math);
    save(stu,n);
}
void sort()  // ���ܳɼ�����
{ 
    struct student stu[N],temp;
    int i,j,n;
    n=reads(stu);
    for(i=0;i<n-1;i++)
	   for(j=0;j<n-1-i;j++)
	   {
		  if(stu[j].english+stu[j].computer+stu[j].math<stu[j+1].english+stu[j+1].computer+stu[j+1].math)
		  { 
			  temp=stu[j];
			  stu[j]=stu[j+1];
			  stu[j+1]=temp;
		  }
	   }
       save(stu,n);
       j=1;
	   printf("*********************�ܳɼ�����������**********************************\n\n");
	   printf("  ����      ѧ��       ����     Ӣ��       �����     ��ѧ      �ܳɼ�    \n");
       printf("*************************************************************************\n"); 
	   for(i=0;i<n;i++) // ������������
	   { 
		   if(stu[i].english+stu[i].computer+stu[i].math==stu[i+1].english+stu[i+1].computer+stu[i+1].math)
	            printf("\n%3d%12s%11s%11.2f%11.2f%11.2f%11.2f\n",j,stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math,stu[i].english+stu[i].computer+stu[i].math);
           else
                printf("\n%3d%12s%11s%11.2f%11.2f%11.2f%11.2f\n",j++,stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math,stu[i].english+stu[i].computer+stu[i].math);
   
	   }
       getch();
}
void query()  // ��ѧ�Ŷ�ѧ����Ϣ��ѯ
{
    struct student stu[N];
    char number[20];
    int i,n;
    n=reads(stu);
    printf("\n���������ѯ��ѧ��ѧ�ţ����س���ȷ�ϣ�\n");
    scanf("%s",number);
    for(i=0;i<n;i++)
	   if(strcmp(number,stu[i].num)==0) break;
    if(i>=n)
	{
		printf("û���ҵ���ѧ����Ϣ��\n");
        return;
	}
    else
	    printf("\n%12s%11s%11.2f%11.2f%11.2f\n",stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math,stu[i].english+stu[i].computer+stu[i].math);
}
