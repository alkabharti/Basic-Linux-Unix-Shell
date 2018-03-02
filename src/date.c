#include<string.h>
#include<stdio.h>
#include<time.h>

int main(int argc,char * argv[])
{
time_t times;
struct tm *entireInformation;
char buffer[250];
time(&times);
if(argc==1)
{
entireInformation= localtime(&times);
strftime(buffer,250,"%c",entireInformation);
printf("%s\n",buffer);
}
if(argc==2)
{
if(strcmp(argv[1],"-u")==0)
{
entireInformation= gmtime(&times);
strftime(buffer,250,"%c",entireInformation);
printf("%s\n",buffer);
}
if(strcmp(argv[1],"-R")==0)
{
entireInformation= localtime(&times);
strftime(buffer,250,"%a %d %h %Y %T %z",entireInformation);
printf("%s\n",buffer);
}
}
return 0;
}

