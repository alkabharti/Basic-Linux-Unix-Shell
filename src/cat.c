#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
int i;
for(i=(strcmp(argv[1],"-n")==0||strcmp(argv[1],"-E")==0?2:1);i<argc && argv[i]!=NULL;i++)
{
//printf("%d",i);
if(strcmp(argv[1],"-n")!=0 && strcmp(argv[1],"-E")!=0)
{
FILE *f;
f=fopen(argv[i],"r");

if(f==NULL)
{
printf("Can not open the file\n");
return 0;
}
char c;
c=fgetc(f);
while(c!=EOF)
{
printf("%c",c);
c=fgetc(f);
}
fclose(f);
}
if(strcmp(argv[1],"-n")==0)
{
FILE *f;
f=fopen(argv[i],"r");

if(f==NULL)
{
printf("Can not open the file\n");
return 0;
}
char c[128];
int count=0;
while(fgets(c,sizeof c,f)!=NULL)
{
printf("%d\n",count);
fputs(c,stdout);
count++;
}
fclose(f);
}

if(strcmp(argv[1],"-E")==0)
{
FILE *f;
f=fopen(argv[i],"r");

if(f==NULL)
{
printf("Can not open the file\n");
return 0;
}
int c;
c=fgetc(f);
while(c!=EOF)
{
printf("%c",c);
c=fgetc(f);
if(c == '\n')
{
printf("$");
}
}
fclose(f);

}
}
return 0;
}
