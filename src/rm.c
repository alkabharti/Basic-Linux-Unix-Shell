#include<unistd.h>
#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
int c;
if(argc==2)
{
struct stat stt;
stat(argv[1],&stt);
if((S_ISREG(stt.st_mode))!=0)
{
c=remove(argv[1]);
if(c!=0)
{
printf("file can not be deleted\n");
}
}
else
{
printf("can not delete the item\n");
}
}
if(argc==3)
{
if(strcmp(argv[1],"-v")==0)
{
c=remove(argv[2]);
if(c==0)
{
printf("file was successfully deleted\n");
}
else
{
printf("file could not be deleted\n");
}
}
if(strcmp(argv[1],"-d")==0)
{
struct dirent * entryPoint;
DIR *open;
open=opendir(argv[2]);
if(open==NULL)
{
printf("directory could not be opened\n");
return 0;
}
int count=0;
while((entryPoint=readdir(open))!=NULL)
{
count++;
}
closedir(open);
if(count==2)
{
rmdir(argv[2]);
}
}
}
return 0;
}
