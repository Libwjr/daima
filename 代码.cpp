#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <conio.h>
#define LEN sizeof(struct teacher)

struct teacher 
{
	int num;
	char name[20];
	char sex[20];
	char workplace[50];
	char address[50];
	long phone;
	double de_salary;
	double de_jintie;
	double de_shenghuobutie;
	double yingfa_salary;
	double cost_phone;
	double cost_water_elec;
	double cost_rent;
	double cost_tax;
	double cost_weisheng;
	double cost_gongjijin;
	double cost_all;
	double shifa_salary;
	struct teacher *next;
};



/***********************************读取函数************************************/
struct teacher *load()
{
	struct teacher *p1,*p2,*head;
	FILE *fp;
	int i=1;
	if((fp=fopen("save","rb"))==NULL)
	{
		printf("             文件不存在！按下任意键返回主菜单...");getch();
		return (NULL);
	}
	else
	{
		head=NULL;
		p1=(struct teacher *)malloc(LEN);
		while (fread(p1,LEN-4,1,fp)==1)
		{
			if(i==1)
			{
				head=p1;
				p2=p1;
				i=2;
			}
			else 
			{
				p2->next=p1;
				p2=p2->next;
			}
			p1=(struct teacher *)malloc(LEN);
		}
		p2->next=NULL;
		free(p1);
		fclose(fp);
		return(head);
	}
}

/**********************************欢迎菜单函数*************************************/
void welcome()
{
	printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统Beta1.2<<<<<\n");
	printf("             *******************************************************\n");
	printf("             *                    教师工资管理系统                 *\n"); 
	printf("             *    班级： 软件2225班   学号：223201062506        *\n");
	printf("             *                      姓名：王靖榕                   *\n");
	printf("             *******************************************************\n");
	printf("\n\n                             按下任意键进入系统 ...");
	getch();
	system("cls");
}
/***********************************************************************/
void list()
{
	system("cls");
	printf("\n\n\n                           >>>>>版权所有 侵权必究<<<<<\n");
	printf("*******************************************************************************\n");
	printf("*    学校(College):       沈阳工学院                                          *\n");
	printf("*    软件名称(Software)： 教师工资管理系统                                    *\n"); 
	printf("*    姓名（name)：        李晓晴                                              *\n");
	printf("*    所在班级(Class)：    21计算机科学与技术专升本4班                         *\n");
	printf("*    所在学院(Institute)：信息与控制学院                                      *\n");	
	printf("*******************************************************************************\n");
	printf("                          >>>>>ILLEGAL COPY BANNED<<<<<\n");
	printf("\n\n                             按下任意键返回主菜单...");
	getch();
}
/***********************************菜单函数*****************************************/
int menu()
{
	int i;
	printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统Beta1.2<<<<<\n");
	printf("             *******************************************************\n");
	printf("             *                 1.输入教师信息                      *\n");
	printf("             *                 2.插入教师信息                      *\n");
	printf("             *                 3.修改教师信息                      *\n");
	printf("             *                 4.删除教师信息                      *\n");
	printf("             *                 5.浏览教师信息                      *\n");
	printf("             *                 6.显示制作人员名单                  *\n");
	printf("             *                 7.退出系统                          *\n");
	printf("             *******************************************************\n");
	printf("             请输入你想要的操作：");
	scanf("%d",&i);getchar();
	return i;
}
/***********************************插入函数*****************************************/
void input()
{
	struct teacher *head,*p1,*p2,*p3,*px;
	int i,t;
	FILE *fp;
	char k,n='n',num[30],name[20];
	p1=p2=p3=px=(struct teacher *)malloc(LEN);
	if((head=load())!=NULL)
	{
		do
		{
			n='n';
			printf("             请输入要插入的教师信息：\n");
			printf("             ------------------------------\n");
			printf("             请输入教工号:");gets(num);px->num=atoi(num);
			printf("             请输入姓名:");gets(px->name);
			printf("             请输入性别:");gets(px->sex);
			printf("             请输入单位名称:");gets(px->workplace);
			printf("             请输入家庭住址:");gets(px->address);
			printf("             请输入联系电话:");gets(num);px->phone=atoi(num);
			printf("             请输入基本工资:");gets(num);px->de_salary=atof(num);
			printf("             请输入津贴:");gets(num);px->de_jintie=atof(num);
			printf("             请输入生活补贴:");gets(num);px->de_shenghuobutie=atof(num);
			printf("             请输入电话费:");gets(num);px->cost_phone=atof(num);
			printf("             请输入水电费:");gets(num);px->cost_water_elec=atof(num);
			printf("             请输入房租:");gets(num);px->cost_rent=atof(num);
			printf("             请输入个人所得税:");gets(num);px->cost_tax=atof(num);
			printf("             请输入卫生费:");gets(num);px->cost_weisheng=atof(num);
			printf("             请输入公积金:");gets(num);px->cost_gongjijin=atof(num);
			px->yingfa_salary=px->de_salary+px->de_jintie+px->de_shenghuobutie;
			px->cost_all=px->cost_phone+px->cost_water_elec+px->cost_rent+px->cost_tax+px->cost_weisheng+px->cost_gongjijin;
			px->shifa_salary=px->yingfa_salary-px->cost_all;
			printf("             数据输入完毕，按下任意键继续...");getch();
			
			system("cls");
			printf("\n\n\n                       >>>>>>>>>>> 插入教师信息 <<<<<<<<<<<\n");
			printf("             *******************************************************\n");
			printf("             *                     1.输入教师号                    *\n");
			printf("             *                     2.输入姓名                      *\n");
			printf("             *                     3.返回上级菜单                  *\n");
			printf("             *******************************************************\n");
			printf("             请选择插入方式：");
			scanf("%d",&i);getchar();
			while (i<1||i>3)
			{
				printf("             输入有误!请重新输入:");
				scanf("%d",&i);getchar();
			}
			switch(i)
			{
			case 1:printf("             请输入要插入在哪条数据后面：");
				scanf("%d",&t);getchar();
				p1=head;
				while (p1->num!=t)
				{
					if (p1->next!=NULL)
					{	p1=p1->next;
					}
					else 
					{
						printf("             查找不到相关数据!\n");
						break;
					}
				}
				if (p1->num==t)
				{
					printf("-----------------------------要插入的信息如下：--------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",px->num,px->name,px->sex,px->workplace,px->address,px->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",px->cost_phone,px->cost_water_elec,px->cost_rent,px->cost_tax,px->cost_weisheng,px->cost_gongjijin,px->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",px->de_salary,px->de_jintie,px->de_shenghuobutie,px->yingfa_salary,px->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					printf("             确定插入吗？（y或n）:");
					scanf("%c",&k);getchar();
				}
				if (k=='y'||k=='Y')
				{
				if (p1->num==t)
				{
					if(p1==head)/*如果插入点为头指针*/
					{
						p3=p1->next;
						p1->next=px;
						px->next=p3;
						p2=head;
					}
					else if(p1->next==NULL)/*如果插入点为末尾指针*/
							{
								p3=p1;p1=head;p2=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p1=p1->next;
								p1->next=px;
								px->next=NULL;
							}
						else{/*如果插入点为中间指针*/
								p3=p1;p1=head;p2=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p1=p1->next;
								p3=p1->next;
								px->next=p3;
								p1->next=px;
							}			
					if((fp=fopen("save","wb"))==NULL)
					{
						printf("             文件不存在！按下任意键返回主菜单...");getch();
					}
					else
					{
					do
					{
						fwrite(p2,LEN-4,1,fp);
						if(p2->next!=NULL)
						p2=p2->next;	
					}while(p2->next!=NULL);
					if(p2!=head)
						fwrite(p2,LEN-4,1,fp);
					}fclose(fp);
					printf("             插入成功！按下任意键继续...");getch();
				}
				}
				else {printf("             插入已被取消！按下任意键继续...");getch();}
				break;
			case 2:printf("             请输入要插入的教师姓名：");
				gets(name);
				p1=head;
				while (strcmp((p1->name),name)!=0)
				{
					if (p1->next!=NULL)
						p1=p1->next;
					else 
					{
						printf("             查找不到相关数据!\n");
						break;
					}
				}
				if (strcmp((p1->name),name)==0)
				{
					printf("-----------------------------要插入的信息如下：--------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					printf("             确定插入吗？（y或n）:");
					scanf("%c",&k);getchar();
				}
				if (k=='y'||k=='Y')
				{
				if (strcmp((p1->name),name)==0)
				{
					if(p1==head)/*如果插入点为头指针*/
					{
						p1->next=px;
						p2=head;
					}
					else if(p1->next==NULL)/*如果插入点为末尾指针*/
							{
								p3=p1;p1=head;p2=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p1=p1->next;
								p1->next=px;
								px->next=NULL;
							}
						else{/*如果插入点为中间指针*/
								p3=p1;p1=head;p2=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p1=p1->next;
								p1->next=px;
								p3=p3->next;
								px->next=p3;
							}			
					if((fp=fopen("save","wb"))==NULL)
					{
						printf("             文件不存在！按下任意键返回主菜单...");getch();
					}
					else
					{
					do
					{
						fwrite(p2,LEN-4,1,fp);
						if(p2->next!=NULL)
						p2=p2->next;	
					}while(p2->next!=NULL);
					if(p2!=head)
						fwrite(p2,LEN-4,1,fp);
					}fclose(fp);
					printf("             插入成功！按下任意键继续...");getch();
				}
				}
				else {printf("             插入已被取消！按下任意键继续...");getch();}
				break;
			case 3:break;
			default :break;
			}
			if (i!=3)
			{
			printf("\n             继续插入其他教师的信息吗？（y或n）");
			scanf("%c",&n);getchar();
			}
		}while((n=='y'||n=='Y')&&i!=3);
	}

			printf("             数据插入成功！按下任意键返回主菜单...");getch();
			getchar();	
}

/***********************************输入函数*****************************************/
void insert()
{
	FILE *fp;
	char m,num[30];	
	struct teacher *p1;
	p1=(struct teacher *)malloc(LEN);
	if((fp=fopen("save","ab"))==NULL)
	{
		printf("             文件不存在！按下任意键返回主菜单...");getch();
	}
	else
	{
		printf("             请输入教师信息：\n");
		do
		{
			printf("             ------------------------------\n");
			printf("             请输入教工号:");gets(num);p1->num=atoi(num);
			printf("             请输入姓名:");gets(p1->name);
			printf("             请输入性别:");gets(p1->sex);
			printf("             请输入单位名称:");gets(p1->workplace);
			printf("             请输入家庭住址:");gets(p1->address);
			printf("             请输入联系电话:");gets(num);p1->phone=atoi(num);
			printf("             请输入基本工资:");gets(num);p1->de_salary=atof(num);
			printf("             请输入津贴:");gets(num);p1->de_jintie=atof(num);
			printf("             请输入生活补贴:");gets(num);p1->de_shenghuobutie=atof(num);
			printf("             请输入电话费:");gets(num);p1->cost_phone=atof(num);
			printf("             请输入水电费:");gets(num);p1->cost_water_elec=atof(num);
			printf("             请输入房租:");gets(num);p1->cost_rent=atof(num);
			printf("             请输入个人所得税:");gets(num);p1->cost_tax=atof(num);
			printf("             请输入卫生费:");gets(num);p1->cost_weisheng=atof(num);
			printf("             请输入公积金:");gets(num);p1->cost_gongjijin=atof(num);
			p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;
			p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;
			p1->shifa_salary=p1->yingfa_salary-p1->cost_all;
			fwrite(p1,LEN-4,1,fp);
			printf("             输入下一个？（y或n）");
			m=getchar();
			if(m!='y'&&m!='Y')
			{printf("             数据保存成功！按下任意键返回主菜单...");getch();}
			getchar();	
		}while (m=='y'||m=='Y');
	}
	fclose(fp);

}

/***********************************修改函数*****************************************/
void modify()
{
	struct teacher *head,*p1,*p2;
	int i;
	FILE *fp;
	char m='n',n='n',num2[30];
	p1=head=(struct teacher *)malloc(LEN);
	if((head=load())!=NULL)
	{
		do
		{
			int num=0;
			char name[20];
			p1=head;
			system("cls");
			printf("\n\n\n                       >>>>>>>>>>> 修改教师信息 <<<<<<<<<<<\n");
			printf("             *******************************************************\n");
			printf("             *                     1.输入教师号                    *\n");
			printf("             *                     2.输入姓名                      *\n");
			printf("             *                     3.返回上级菜单                  *\n");
			printf("             *******************************************************\n");
			printf("             请选择修改方式：");
			scanf("%d",&i);getchar();
			while (i<1||i>3)
			{
				printf("             输入有误!请重新输入:");
				scanf("%d",&i);getchar();
			}
			switch(i)
			{
			case 1:printf("             请输入要修改的教师号：");
				scanf("%d",&num);getchar();
				while (p1->num!=num)
				{
					if (p1->next!=NULL)
						p1=p1->next;
					else 
					{
						printf("             查找不到相关数据!\n");
						break;
					}
				}
				if (p1->num==num)
				{
					system("cls");
					printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统Beta1.2<<<<<\n");
					printf("----------------------------------原信息如下：---------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					printf("             *******************************************************\n");
					printf("             *              1.教师号        2.姓名                 *\n");
					printf("             *              3.性别          4.单位名称             *\n");
					printf("             *              5.家庭住址      6.联系电话             *\n");
					printf("             *              7.基本工资      8.津贴                 *\n");
					printf("             *              9.生活补贴      10.电话费              *\n");
					printf("             *             11.水电费        12.房租                *\n");
					printf("             *             13.所得税        14.卫生费              *\n");
					printf("             *                      15.公积金                      *\n");
					printf("             *******************************************************\n");
					do
					{
					printf("             请选择要修改的数据：");
					scanf("%d",&i);getchar();
					while (i>15||i<1)
					{
						printf("             输入有误！请重新输入:");
						scanf("%d",&i);getchar();
					}
					switch(i)
					{
					case 1:printf("             请输入新教师号：");gets(num2);p1->num=atoi(num2);break;
					case 2:printf("             请输入新姓名：");gets(p1->name);break;
					case 3:printf("             请输入新性别：");gets(p1->sex);break;
					case 4:printf("             请输入新单位名称：");gets(p1->workplace);break;
					case 5:printf("             请输入新家庭住址：");gets(p1->address);break;
					case 6:printf("             请输入新联系电话：");gets(num2);p1->phone=atoi(num2);break;
					case 7:printf("             请输入新基本工资：");gets(num2);p1->de_salary=atof(num2);break;
					case 8:printf("             请输入新津贴：");gets(num2);p1->de_jintie=atof(num2);break;
					case 9:printf("             请输入新生活补贴：");gets(num2);p1->de_shenghuobutie=atof(num2);break;
					case 10:printf("             请输入新电话费：");gets(num2);p1->cost_phone=atof(num2);break;
					case 11:printf("             请输入新水电费：");gets(num2);p1->cost_water_elec=atof(num2);break;
					case 12:printf("             请输入新房租：");gets(num2);p1->cost_rent=atof(num2);break;
					case 13:printf("             请输入新所得税：");gets(num2);p1->cost_tax=atof(num2);break;
					case 14:printf("             请输入新卫生费：");gets(num2);p1->cost_weisheng=atof(num2);break;
					case 15:printf("             请输入新公积金：");gets(num2);p1->cost_gongjijin=atof(num2);break;
					default:break;
					}
					p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;
					p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;
					p1->shifa_salary=p1->yingfa_salary-p1->cost_all;
					printf("             继续修改其他数据吗？(y或n):");
					scanf("%c",&m);getchar();
					}while (m=='y'||m=='Y');
					p2=head;
					if((fp=fopen("save","wb"))==NULL)
					{
						printf("             文件不存在！按下任意键返回主菜单...");getch();
					}
					else
					{
					fwrite(head,LEN-4,1,fp);
					do
					{
						p2=p2->next;
						fwrite(p2,LEN-4,1,fp);
					}while(p2->next!=NULL);
					printf("------------------------------修改后数据如下：---------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					}
					fclose(fp);
				}
				break;
			case 2:printf("             请输入要修改的教师姓名：");
				gets(name);
				while (strcmp(p1->name,name)!=0)
				{
					if (p1->next!=NULL)
						p1=p1->next;
					else 
					{
						printf("             查找不到相关数据！\n");
						break;
					}
				}
				if (strcmp(p1->name,name)==0)
				{
					system("cls");
				printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统Beta1.2<<<<<\n");
					printf("----------------------------------原信息如下：---------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					printf("             *******************************************************\n");
					printf("             *              1.教师号        2.姓名                 *\n");
					printf("             *              3.性别          4.单位名称             *\n");
					printf("             *              5.家庭住址      6.联系电话             *\n");
					printf("             *              7.基本工资      8.津贴                 *\n");
					printf("             *              9.生活补贴      10.电话费              *\n");
					printf("             *             11.水电费        12.房租                *\n");
					printf("             *             13.所得税        14.卫生费              *\n");
					printf("             *                      15.公积金                      *\n");
					printf("             *******************************************************\n");
					do
					{
					printf("             请选择要修改的数据：");
					scanf("%d",&i);getchar();
					while (i>15||i<1)
					{
						printf("             输入有误！请重新输入:");
						scanf("%d",&i);getchar();
					}
					switch(i)
					{
					case 1:printf("             请输入新教师号：");gets(num2);p1->num=atoi(num2);break;
					case 2:printf("             请输入新姓名：");gets(p1->name);break;
					case 3:printf("             请输入新性别：");gets(p1->sex);break;
					case 4:printf("             请输入新单位名称：");gets(p1->workplace);break;
					case 5:printf("             请输入新家庭住址：");gets(p1->address);break;
					case 6:printf("             请输入新联系电话：");gets(num2);p1->phone=atoi(num2);break;
					case 7:printf("             请输入新基本工资：");gets(num2);p1->de_salary=atof(num2);break;
					case 8:printf("             请输入新津贴：");gets(num2);p1->de_jintie=atof(num2);break;
					case 9:printf("             请输入新生活补贴：");gets(num2);p1->de_shenghuobutie=atof(num2);break;
					case 10:printf("             请输入新电话费：");gets(num2);p1->cost_phone=atof(num2);break;
					case 11:printf("             请输入新水电费：");gets(num2);p1->cost_water_elec=atof(num2);break;
					case 12:printf("             请输入新房租：");gets(num2);p1->cost_rent=atof(num2);break;
					case 13:printf("             请输入新所得税：");gets(num2);p1->cost_tax=atof(num2);break;
					case 14:printf("             请输入新卫生费：");gets(num2);p1->cost_weisheng=atof(num2);break;
					case 15:printf("             请输入新公积金：");gets(num2);p1->cost_gongjijin=atof(num2);break;
					default:break;
					}
					p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;
					p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;
					p1->shifa_salary=p1->yingfa_salary-p1->cost_all;
					printf("             继续修改其他数据吗？(y或n):");
					scanf("%c",&m);getchar();
					}while (m=='y'||m=='Y');
					p2=head;
					if((fp=fopen("save","wb"))==NULL)
					{
						printf("             文件不存在！按下任意键返回主菜单...");getch();
					}
					else
					{
					fwrite(head,LEN-4,1,fp);
					do
					{
						p2=p2->next;
						fwrite(p2,LEN-4,1,fp);
					}while(p2->next!=NULL);
					printf("------------------------------修改后数据如下：---------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					}
					fclose(fp);
				}
				break;
			case 3:break;
			default :break;
			}
			if (i!=3)
			{
			printf("\n             继续修改其他教师的信息吗？（y或n）");
			scanf("%c",&n);
			}
			}while((n=='y'||n=='Y')&&i!=3);
	}

}

/***********************************删除函数*****************************************/
void deletes()
{
	struct teacher *head,*p1,*p2,*p3;
	int i;
	char k;
	FILE *fp;
	char n='n';
	p1=p2=p3=(struct teacher *)malloc(LEN);
	if((head=load())!=NULL)
	{
		do
		{
			int num;
			char name[20];
			p1=head;
			system("cls");
			printf("\n\n\n                       >>>>>>>>>>> 删除教师信息 <<<<<<<<<<<\n");
			printf("             *******************************************************\n");
			printf("             *                     1.输入教师号                    *\n");
			printf("             *                     2.输入姓名                      *\n");
			printf("             *                     3.返回上级菜单                  *\n");
			printf("             *******************************************************\n");
			printf("             请选择删除方式：");
			scanf("%d",&i);getchar();
			while (i<1||i>3)
			{
				printf("             输入有误!请重新输入:");
				scanf("%d",&i);getchar();
			}
			switch(i)
			{
			case 1:printf("             请输入要删除的信息的教师号：");
				scanf("%d",&num);getchar();
				while (p1->num!=num)
				{
					if (p1->next!=NULL)
						p1=p1->next;
					else 
					{
						printf("             查找不到相关数据!\n");
						break;
					}
				}
				if (p1->num==num)
				{
					printf("-----------------------------要删除的信息如下：--------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					printf("             确定删除吗？（y或n）:");
					scanf("%c",&k);getchar();
				}
				if (k=='y'||k=='Y')
				{
				if (p1->num==num)
				{
					if(p1==head)
					{
						p1=p1->next;
						p2=p1;
					}
					else if(p1->next==NULL)
							{
								p3=p1;p1=head;p2=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p1->next=NULL;
							}
						else{
								p2=head;p3=p1;p1=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p3=p3->next;
								p1->next=p3;
							}			
					if((fp=fopen("save","wb"))==NULL)
					{
						printf("             文件不存在！按下任意键返回主菜单...");getch();
					}
					else
					{
					do
					{
						fwrite(p2,LEN-4,1,fp);
						if(p2->next!=NULL)
						p2=p2->next;	
					}while(p2->next!=NULL);
					if(p2!=head)
						fwrite(p2,LEN-4,1,fp);
					}fclose(fp);
					printf("             删除成功！按下任意键继续...");getch();
				}
				}
				else {printf("             删除已被取消！按下任意键继续...");getch();}
				break;
			case 2:printf("             请输入要修改的教师姓名：");
				gets(name);
				while (strcmp((p1->name),name)!=0)
				{
					if (p1->next!=NULL)
						p1=p1->next;
					else 
					{
						printf("             查找不到相关数据!\n");
						break;
					}
				}
				if (strcmp((p1->name),name)==0)
				{
					printf("-----------------------------要删除的信息如下：--------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
					printf("             确定删除吗？（y或n）:");
					scanf("%c",&k);getchar();
				}
				if (k=='y'||k=='Y')
				{
				if (strcmp((p1->name),name)==0)
				{
					if(p1==head)
					{
						p1=p1->next;
						p2=p1;
					}
					else if(p1->next==NULL)
							{
								p3=p1;p1=head;p2=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p1->next=NULL;
							}
						else{
								p2=head;p3=p1;p1=head;
								while(p1->next!=p3)
								{p1=p1->next;}
								p3=p3->next;
								p1->next=p3;
							}			
					if((fp=fopen("save","wb"))==NULL)
					{
						printf("             文件不存在！按下任意键返回主菜单...");getch();
					}
					else
					{
					do
					{
						fwrite(p2,LEN-4,1,fp);
						if(p2->next!=NULL)
						p2=p2->next;	
					}while(p2->next!=NULL);
					if(p2!=head)
						fwrite(p2,LEN-4,1,fp);
					}fclose(fp);
					printf("             删除成功！按下任意键继续...");getch();
				}
				}
				else {printf("             删除已被取消！按下任意键继续...");getch();}
				break;
			case 3:break;
			default :break;
			}
			if (i!=3)
			{
			printf("\n             继续删除其他教师的信息吗？（y或n）");
			scanf("%c",&n);
			}
		}while((n=='y'||n=='Y')&&i!=3);
	}

}

/***********************************浏览函数*****************************************/
void scan()
{
	struct teacher *head,*p1;
	int i;
	char m='n';
	p1=head=(struct teacher *)malloc(LEN);
	if((head=load())!=NULL)
	{
		system("cls");
		printf("\n\n\n                       >>>>>>>>>>> 浏览教师信息 <<<<<<<<<<<\n");
		printf("             *******************************************************\n");
		printf("             *                     1.全部浏览                      *\n");
		printf("             *                     2.单个浏览                      *\n");
		printf("             *                     3.返回上级菜单                  *\n");
		printf("             *******************************************************\n");
		printf("             请输入你想要的操作：");
		scanf("%d",&i);getchar();
		while (i<1||i>3)
		{
			printf("             输入有误！请重新输入:");
			scanf("%d",&i);getchar();
		}
		switch(i)
		{
		case 1:p1=head;
			printf("----------------------------所有保存的信息如下：-------------------------------\n");
			printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
			do
			{
				printf(" %-4d %-13s %s     %-19s %-19s%-14ld",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
				if (p1->next!=NULL)
				{p1=p1->next;}
				else break;
			}while(1);
			p1=head;
			printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
			do
			{
				printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf ",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
				if (p1->next!=NULL)
				{p1=p1->next;}
				else break;
			}while(1);
			p1=head;
			printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
			do
			{
				printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf \n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
				if (p1->next!=NULL)
				{p1=p1->next;}
				else break;
			}while(1);
			p1=head;
			printf("\n-------------------------------------------------------------------------------\n");
			printf("             按下任意键返回主菜单...");
			getch();
			break;


		case 2:
			do
			{
			int num=0;
			char name[20];
			p1=head;
			system("cls");
			printf("\n\n\n                       >>>>>>>>>>> 浏览教师信息 <<<<<<<<<<<\n");
			printf("             *******************************************************\n");
			printf("             *                     1.输入教师号                    *\n");
			printf("             *                     2.输入姓名                      *\n");
			printf("             *******************************************************\n");
			printf("             请输入你想要的操作：");
			scanf("%d",&i);getchar();
			while (i<1||i>2)
			{
				printf("             输入有误!请重新输入:");
				scanf("%d",&i);getchar();
			}
			switch(i)
			{
			case 1:printf("             请输入要查询的教师号：");
				scanf("%d",&num);getchar();
				while (p1->num!=num)
				{
					if (p1->next!=NULL)
						p1=p1->next;
					else 
					{
						printf("             查找不到相关数据!\n");
						break;
					}
				}
				if (p1->num==num)
				{
					printf("-------------------------------所查信息如下：----------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
				}
				break;
			case 2:printf("             请输入要查询的教师姓名：");
				gets(name);
				while (strcmp(p1->name,name)!=0)
				{
					if (p1->next!=NULL)
						p1=p1->next;
					else 
					{
						printf("             查找不到相关数据！\n");
						break;
					}
				}
				if (strcmp(p1->name,name)==0)
				{
					printf("-------------------------------所查信息如下：----------------------------------\n");
					printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");
					printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);
					printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
					printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);
					printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");
					printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);
					printf("-------------------------------------------------------------------------------\n");
				}
				break;
			default :break;
			}
			printf("             继续浏览吗？（y或n）");
			scanf("%c",&m);
			}while(m=='y'||m=='Y');
		case 3:break;


		}
	}
}

/***********************************主函数*****************************************/
void main()
{
	int a=1;
	welcome();
	while(1)
	{
		system("cls");
		a=menu();
	switch(a)
	{
	case 1:insert();break;
	case 2:input();break;
	case 3:modify();break;
	case 4:deletes();break;
	case 5:scan();break;
	case 6:list();break;
	case 7:printf("             欢迎下次使用！");getch();exit(0);break;
	default :printf("             输入有误，请重新输入!");getch();break;
	}
	}
	getch();

}