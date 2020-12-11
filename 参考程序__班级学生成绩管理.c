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
        printf("\n 请输入您要选择的操作序号，按回车键确认：");
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
            default:  printf("输入错误，请输入列表中存在的序号！\n ");
		}
	}

}
void menu()
{
	printf("       ************************* 班级成绩管理系统************************ ");
    printf("\n                               1  添加学生数据");
    printf("\n                               2  显示学生数据");
    printf("\n                               3  删除学生数据");
    printf("\n                               4  更改学生数据");
    printf("\n                               5  总成绩排序");
    printf("\n                               6  成绩查询");
    printf("\n                               7  退出");
}
int  reads(struct student stu[N]) // 读取学生文件中的内容
{
 
	FILE *fp;
    int i=0;
    if((fp=fopen("e:\\student.txt","r"))==NULL)
	{ 
		printf("文件打开失败！\n");
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
void save(struct student stu[N],int n) // 学生信息改变后更新文件
{
	FILE *fp;
    int i=0;
    if((fp=fopen("e:\\student.txt","w"))==NULL)
	{ 
		printf("文件打开失败！\n");
        return ;
	}
    else
	{
        for(i=0;i<n;i++)
           fprintf(fp,"%s %s %f %f %f\n",stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math);
	}
    fclose(fp);
}
void add()/*添加学生信息*/
{
	FILE *fp;
    int n,i;
    struct student stu;
    if((fp=fopen("e:\\student.txt","a"))==NULL)  //如果文件已经存在，可以追加学生信息
	{
	    if((fp=fopen("e:\\student.txt","w"))==NULL) // 文件不存在时，创建新文件，输入学生信息
		{ 
		    printf("文件打开失败！\n");
            return;
		}
	}
    printf("请输入要添加的学生数量，按回车键确认："); 
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    { 
		printf("\n请输入第%d个学生的学号、姓名，用空格分开，并按回车键确认：\n",i);
        scanf("%s%s",stu.num,stu.name);
        printf("\n请输入第%d个学生的英语、计算机和数学三门成绩，用空格分开，并按回车键确认：\n",i);
        scanf("%f%f%f",&stu.english,&stu.computer,&stu.math);
        fprintf(fp,"%s %s %f %f %f\n",stu.num,stu.name,stu.english,stu.computer,stu.math);
		
	}
    fclose(fp);
}
void show() // 学生信息显示函数
{
	struct student stu[N];
    int i,n;
    n=reads(stu);
    printf("*********************所有的学生信息如下**********************\n\n");
	printf("  序号      学号       姓名     英语       计算机     数学          \n");
    printf("*************************************************************\n"); 
	for(i=0;i<n;i++)
        printf("\n%3d%12s%11s%11.2f%11.2f%11.2f\n",i+1,stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math);
    getch();
}
void del()  /*学生信息删除函数*/
{
	struct student stu[N];
    char number[20];
    int n,i,j;
    n=reads(stu);
    printf("\n请输入要删除信息的学生学号，按回车键确认：");
    scanf("%s",number);
    for(i=0;i<n;i++)
	    if(strcmp(number,stu[i].num)==0) break;
    if(i>=n)
	{
		printf("没有找到该学生信息！\n");
        return;
	}
    else
	{
		for(j=i+1;j<n;j++)
	        stu[j-1]=stu[j];
	}
    save(stu,n-1);
    printf("删除成功！\n");
}
void change()  //学生信息更改
{
	struct student stu[N];
    int n,i;
	char number[20];
    printf("\n请输入要更改信息的学生学号，按回车键确认：");
    scanf("%s",number);
    n=reads(stu);
    for(i=0;i<n;i++)
        if(strcmp(number,stu[i].num)==0)
	       break;
    if(i>=n)
	{
		printf("无此学生信息!");
        return;
	}
    printf("\n请输入更改后学生的学号，姓名，英语、计算机、数学三门成绩，按回车键确认：\n");
    scanf("%s%s%f%f%f",stu[i].num,stu[i].name,&stu[i].english,&stu[i].computer,&stu[i].math);
    save(stu,n);
}
void sort()  // 按总成绩排序
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
	   printf("*********************总成绩排序结果如下**********************************\n\n");
	   printf("  名次      学号       姓名     英语       计算机     数学      总成绩    \n");
       printf("*************************************************************************\n"); 
	   for(i=0;i<n;i++) // 输出结果并排名
	   { 
		   if(stu[i].english+stu[i].computer+stu[i].math==stu[i+1].english+stu[i+1].computer+stu[i+1].math)
	            printf("\n%3d%12s%11s%11.2f%11.2f%11.2f%11.2f\n",j,stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math,stu[i].english+stu[i].computer+stu[i].math);
           else
                printf("\n%3d%12s%11s%11.2f%11.2f%11.2f%11.2f\n",j++,stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math,stu[i].english+stu[i].computer+stu[i].math);
   
	   }
       getch();
}
void query()  // 按学号对学生信息查询
{
    struct student stu[N];
    char number[20];
    int i,n;
    n=reads(stu);
    printf("\n请输入待查询的学生学号，按回车键确认：\n");
    scanf("%s",number);
    for(i=0;i<n;i++)
	   if(strcmp(number,stu[i].num)==0) break;
    if(i>=n)
	{
		printf("没有找到该学生信息！\n");
        return;
	}
    else
	    printf("\n%12s%11s%11.2f%11.2f%11.2f\n",stu[i].num,stu[i].name,stu[i].english,stu[i].computer,stu[i].math,stu[i].english+stu[i].computer+stu[i].math);
}
