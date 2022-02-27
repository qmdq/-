#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int witre_file(char *file_name,int x,char *Std_name)
// x = 1.返回第一个字符出x=2返回第二个
{


    FILE *fp;
   /* 打开用于读取的文件 */
    fp = fopen(file_name,"w");
    if(fp == NULL)
    {
      perror("打开文件时发生错误");
      
    }
    if (x == 1)
    {
        fputs(Std_name,fp);
        
            //puts(str);
        return 0;
      /* 向标准输出 stdout 写入内容 */
        
    }
    if (x==2)
    {
        fputs (Std_name,fp);
        //puts(str2);
       
      /* 向标准输出 stdout 写入内容 */
        return 1;
        /* code */
    }
    
    fclose(fp);
    
}


char* read_file(char *file_name,int x)
// x = 1.返回第一个字符出x=2返回第二个
{


    FILE *fp;
    static char str[60];
    static char str2[60];

   /* 打开用于读取的文件 */
    fp = fopen(file_name,"r");
    if(fp == NULL)
    {
      perror("打开文件时发生错误");
      
    }
    if (x == 1)
    {
        if( fgets(str, 60, fp)!=NULL) 
        {
            //puts(str);
       
      /* 向标准输出 stdout 写入内容 */
            return str;
        }
        /* code */
    }
    if (x==2)
    {
        if( fgets (str2, 60, fp)!=NULL ) 
        {
           //puts(str2);
       
      /* 向标准输出 stdout 写入内容 */
            return str2;
        }
        /* code */
    }
    
    fclose(fp);
    
}
