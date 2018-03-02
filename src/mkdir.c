#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
struct stat stt={0};
if(argc==2)
{
if(stat(argv[1],&stt)==-1)
{
mkdir(argv[1],0700);
}
else
{
printf("directory exists\n");
}
}
if(argc==3)
{
if(strcmp(argv[1],"-v")==0)
{
if(stat(argv[2],&stt)==-1)
{
mkdir(argv[2],0700);
printf("Directory created\n");
}
else
{
printf("directory exists\n");
}
}
}
if(argc==4)
{
if(strcmp(argv[1],"-m")==0)
{
umask(0);
char *c;
long permission;
permission=strtoul(argv[3],&c,8);
if(stat(argv[3],&stt)==-1)
{
mkdir(argv[3],permission);
}
else
{
printf("directory exist\n");
}
umask(0022);
}
}
return 0;
}
