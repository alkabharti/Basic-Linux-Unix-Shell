#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char * argv[])
{
struct stat stt;
struct dirent *entryPoint;
DIR * open;
if(argc==2)
{
open=opendir(argv[1]);
}
if(argc==3)
{
open=opendir(argv[2]);
}
if(argc==1)
{
open=opendir(".");
}
if(open==NULL)
{
printf(" Could not open the directory\n");
return 0;
}
while((entryPoint=readdir(open))!=NULL)
{
if(strcmp(argv[1],"-a")!=0)
{
if(strcmp(argv[1],"-s")==0)
{
if(!stat(entryPoint->d_name,&stt))
printf("%u\n",(unsigned int)stt.st_size);
}
char c=entryPoint->d_name[0];
if(c!='.')
{
printf(" %s\n",entryPoint->d_name);
}
}
else
{
printf(" %s\n",entryPoint->d_name);
}
}
closedir(open);
return 0;
}
