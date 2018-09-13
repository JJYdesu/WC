#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "io.h"



int charcalculate(char *file) /*�ַ�ͳ��*/
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

int wordcalculate(char *file)   /*����ͳ��*/
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

int linecalculate(char *file)  /*����ͳ��*/
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

int searchfile(void)    /*Ѱ��Ŀ¼��txt�ļ�*/
{
    //�ļ��洢��Ϣ�ṹ�� 
    struct _finddata_t fileinfo;
    //�����ļ���� 
    long fHandle;
    //�ļ�����¼��
    int t=0;
	
       if( (fHandle=_findfirst( "F:\\Microsoft Visual Studio\\MyProjects\\WordCount\\Debug\\*txt", &fileinfo )) == -1L ) 
		{
        printf( "��ǰĿ¼��û��txt�ļ�\n");
		
		}
    else
    do{
		 t++;
		printf("�ҵ��ļ�:%s\n", fileinfo.name);
	}while (_findnext(fHandle,&fileinfo)==0);

    _findclose(fHandle);

    printf("txt�ļ�������%d\n",t);
    return 0;
}


int main (int argc, char *argv[])   /*������*/
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






			 
		     
 