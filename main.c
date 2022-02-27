#include<stdio.h>
#include<string.h>
#include"file/file_std.h"
#include"df/std.h"
typedef struct Student{
    char name[20];//姓名
    char sex[5];//性别
    char number[20];//学号
    int age;//年龄
   // float scores;//总成绩
    struct Student *pNext;//指针域

} Student;

Student *Addstudent()//添加学生信息
{
     Student *hand = NULL;//头指针
     Student *pNew,*pEnd;
    
    pNew = (Student*)malloc(sizeof(struct Student));
    printf("输入0退出\n");
    printf("请输入姓名：");
    scanf("%s",pNew->name);
    printf("请输入性别：");
    scanf("%s",pNew->sex);
    printf("请输入学号：");
    scanf("%s",pNew->number);
    printf("请输入年龄：");
    scanf("%d",&pNew->age);
    
    do
    {
        
        if (hand!=NULL)
        {
            pEnd = hand;
            hand = pNew;
            
            pNew->pNext = pEnd;
        /* code */
        }
        else
        {
            hand = pNew;
            pNew->pNext=NULL;
        }
        pNew = (Student*)malloc(sizeof(Student));
        printf("请输入姓名：");
        scanf("%s",pNew->name);
        if (strcmp(pNew->name,"0")==0)
        {
            break;
            /* code */
        }
        
        printf("请输入性别：");
        scanf("%s",pNew->sex);
        printf("请输入学号：");
        scanf("%s",pNew->number);
        printf("请输入年龄：");
        scanf("%d",&pNew->age);
        /* code */
    }while (1);
    
    return hand;

    
}



void Show()//打印文字
{
    printf("\t\t##########################\n");
    printf("\t\t# 1.添加学生             #\n");
    printf("\t\t# 2.查看所有学生信息     #\n");
    printf("\t\t# 3.根据学生姓名查看信息 #\n");
    printf("\t\t# 4.删除学生             #\n");
    printf("\t\t# 5.修改学生             #\n");
    printf("\t\t# 6.系统设置             #\n");
    printf("\t\t# 7.查看提示             #\n");
    printf("\t\t# 0.退出                 #\n");
    printf("\t\t##########################\n");

}

void file_write(char *filename,struct Student *tmp)
//filename文件名 //tmp要写入的链表
{
    FILE *fp;
    fp = fopen(filename,"a+");
    if (fp==NULL)
    {
        printf("打开失败");

        /* code */
    }
    fprintf(fp,"%s %s %s %d\n",tmp->name,tmp->sex,tmp->number,tmp->age);
    fclose(fp);
    

}





void dprint(Student *p,int x)
{//负责打印
    Student *tmp;
    tmp = p;
    while (tmp!=NULL)
    {
        if (x==1)
        {
            file_write("std.txt",tmp);
            /* code */
        }
        
       
        printf("%s %s %s %d\n",tmp->name,tmp->sex,tmp->number,tmp->age);
        tmp = tmp->pNext;

        /* code */
    }
    

}


Student *View()
//查看所有学生信息
{
    FILE *fp;
    char text[100];
    fp = fopen("std.txt","r");
    if (fp==NULL)
    {
        printf("打开失败\n");
        /* code */
    }
    Student *hand=NULL;
    Student *pNew,*pEnd;

    while ((fgets(text,60,fp)!=NULL))
    {
        pNew = (Student*)malloc(sizeof(Student));
        sscanf(text,"%s %s %s %d",pNew->name,pNew->sex,pNew->number,&pNew->age);
        if (hand!=NULL)
        {
            pEnd=hand;
            hand = pNew;
            pNew->pNext=pEnd;

            /* code */
        }
        else
        {
            hand = pNew;
            pNew->pNext=NULL;
        }

        
        /* code */
    }
    
    return hand;    
    
}

void find(Student *p,char *name)//查找
//name 姓名
{
    Student *tmp;
    tmp=p;
    int cunt = 0;
    
    while (tmp->pNext!=NULL)
    {
        cunt++;
        int x;
        
        
        if (strcmp(tmp->name,name)==0)
        {
            printf("NO.%d姓名:%s性别:%s学号:%s年龄:%d\n",cunt,tmp->name,tmp->sex,tmp->number,tmp->age);
            int x = 1;
            break;
            /* code */
        }
        else
        {
            tmp = tmp->pNext;
        }
        if (x!=1)
        {
            printf("第%d行到该学生\n",cunt);

            /* code */
        }
        /* code */
    }

    

}


extern void del_file_write(char *filename,struct Student *tmp);


void del_file_write(char *filename,struct Student *p)
//filename文件名 //tmp要写入的链表
{
    
    Student *tmp;
    tmp = p;
    FILE *fp;
    fp = fopen(filename,"w+");
    if (fp==NULL)
    {
        printf("打开失败");

        /* code */
    }
    fprintf(fp,"\n");
    while (tmp!=NULL)
    {
        if (tmp->age==0||strcmp(tmp->name,"0")==0)
        {
            tmp->pNext;
            /* code */
        }
        
        fprintf(fp,"%s %s %s %d\n",tmp->name,tmp->sex,tmp->number,tmp->age);

        tmp = tmp->pNext;
        /* code */
    }
    
    
    fclose(fp);
    

}



Student *Rev_stu(Student *p,char *stuname,char *new_name,int x )
{//x=0修改姓名 x=1修改学号 name_num姓名or学号 newname新值
    Student *tmp = p;
    if (x==0)
    {
        while (tmp!=NULL)
        {
            if (strcmp(tmp->name,stuname)==0)
            {
                strcpy(tmp->name,new_name);
                /* code */
            }
            tmp = tmp->pNext;
            /* code */
        }
        return p;
        /* code */
    }
    if (x==1)
    {
        while (tmp!=NULL)
        {
            if (strcmp(tmp->number,stuname)==0)
            {
                strcpy(tmp->number,new_name);
                /* code */
            }
            tmp = tmp->pNext;
            /* code */
        }
        return p;
        /* code */
    }
 }


void Rev()//修过学生信息
{
    Student *p;
    printf("\t\t##########################\n");
    printf("\t\t# 1.修改姓名             #\n");
    printf("\t\t# 2.修改学号             #\n");
    printf("\t\t# 0.返回上一级           #\n");
    printf("\t\t##########################\n");
    int sel=1;
    p = View();
    Student *p_stu;
    char stu_name[20];//学生姓名或学号
    char new_name[20];
    printf("请输入功能\n");
    scanf("%d",&sel);
    switch (sel)
    {
    case 0:
        /* code */
        break;
    case 1:
    
        printf("请输入学生姓名\n");
        scanf("%s",stu_name);
        printf("请输入修改后的姓名\n");
        scanf("%s",new_name);    
        p_stu = Rev_stu(p,stu_name,new_name,0);
        del_file_write("std.txt",p_stu);
        break;
    case 2:
        printf("请输入学生学号\n");
        scanf("%s",stu_name);
        printf("请输入修改后的学号\n");
        scanf("%s",new_name);    
        p_stu = Rev_stu(p,stu_name,new_name,1);
        del_file_write("std.txt",p_stu);
        break;
    default:
        break;
    }
    
}
Student *del_student(Student *p,char *student_name)
{

    Student *tmp;
    Student *del_link;//用来保存要删除的节点
    tmp = p;
    if (strcmp(p->name,student_name)==0)
    {
        p = p->pNext;
        
        /* code */
    }
    else
    {
        while (tmp!=NULL)
        {
            
            if (strcmp(tmp->name,student_name)==0)
            {
                del_link=tmp;
                tmp=del_link;
                free(tmp);
                
                /* code */
            }
            tmp=tmp->pNext;
            /* code 
            */
        }
        
        return p;
        
    }
    
    //del_print(p);
    
    

    
    
}





int main()
{

    int lg;
    
    //lg =  Longin();

    
    int n=1;
    char sure;  
    Student *p;
    int cunt_1 = 3;//设置登录密码错误次数
    char student_name[20];//学生名
    for (int i = 0; i < 3; i++)
    {
      
        lg = Longin();
        /* code */
        if (lg==1)
        {
            break;
            /* code */
        } 
        
    }
    Show();
    while (n!=0)
    {
    
    
    /* code */
    
  
    printf("请输入功能\n");

    scanf("%d",&n);

        switch (n)
        {
       
        
        case 1:
            /* code */
            p = Addstudent();
            dprint(p,1);
            break;
        case 2:
            p = View();
            dprint(p,0);
            break;
        case 3: 
            printf("请输入学生名\n");
            scanf("%s",student_name);
            p =View();
            find(p,student_name);
                /* code */
            break;
                /* code */ 
        case 4:
            p = View();
            char name[20];
            printf("请输入要删除的学生姓名\n");
            scanf("%s",name);
            del_file_write("std.txt",del_student(p,name));
            break;
        case 5:
            Rev();
            break;
        case 6:
            Setting();
            break;
        case 7:
            Show();
            break;

        default :
            Show();
            break;
        }
    
      }
    return 0;
      
      
     

        /* code */
}  

