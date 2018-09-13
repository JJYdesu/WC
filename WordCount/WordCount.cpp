#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "io.h"



int charcalculate(char *file) /*字符统计*/
{
	 int c=0;
	 FILE *fp;
     char a;
	 fp=fopen(file,"r");
	 while(!feof(fp))
	 {
		 a=fgetc(fp);
		    if(a!=' '&&a!='\n'&&a!='\t')
               c++;
			
	 }
	 fclose(fp); 
	 c--;
	 return c;
}

int wordcalculate(char *file)   /*词数统计*/
{
	 int w=0;
	 FILE *fp;
	 char a;
	 fp=fopen(file,"r");
	 if (charcalculate(file)==0)
         w=0;  
	 else
	 {
		 while(!feof(fp))
	 {
		 a=fgetc(fp);
		    if(a==' '||a=='\n'||a=='\t')
               w++;
	 }
	 w++;
	 }
	 fclose(fp);
	 return w;
}

int linecalculate(char *file)  /*行数统计*/
{
	 int l=0;
	 FILE *fp;
     fp=fopen(file,"r");
	 char a;
	 while(!feof(fp))
	 {
		 a=fgetc(fp);
		    if(a=='\n'||a=='\t')
               l++;
	 }
	 l++;
	 fclose(fp); 
	 return l;
}

int searchfile(void)    /*寻找目录下txt文件*/
{
    //文件存储信息结构体 
    struct _finddata_t fileinfo;
    //保存文件句柄 
    long fHandle;
    //文件数记录器
    int t=0;
	
       if( (fHandle=_findfirst( "F:\\Microsoft Visual Studio\\MyProjects\\WordCount\\Debug\\*txt", &fileinfo )) == -1L ) 
		{
        printf( "当前目录下没有txt文件\n");
		
		}
    else
    do{
		 t++;
		printf("找到文件:%s\n", fileinfo.name);
	}while (_findnext(fHandle,&fileinfo)==0);

    _findclose(fHandle);

    printf("txt文件数量：%d\n",t);
    return 0;
}


int main (int argc, char *argv[])   /*主函数*/
{
	   
	
	   if(!strcmp(argv[1],"-c"))
	{
		printf("charnumber:%d\n",charcalculate(argv[2]));
	}

	   else if(!strcmp(argv[1],"-w"))
	{
		printf("wordnumber:%d\n",wordcalculate(argv[2]));
	}

	   else if (!strcmp(argv[1],"-l"))
	{
		printf("linenumber:%d\n",linecalculate(argv[2]));
	}
	  
	   else if(!strcmp(argv[1],"-s"))
	   {
		   searchfile();
	   }

	return 0;
}






			 
		     
 