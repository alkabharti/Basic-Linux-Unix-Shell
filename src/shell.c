#include<sys/wait.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
char input[40];
int i=0;
const char s[2]=" \n";
char *token;
char *information[40];
char *working=NULL;
char *hist[15];
int l=0;
while(1)
{
i=0;
fgets(input,30,stdin);
if(l<15)
{
hist[l]=strdup(input);
}
l++;
token=strtok(input,s);
information[i]=token;
i++;
if(strcmp(information[0],"pwd")==0)
{
working=getcwd(working,0);
if(working!=NULL)
{
fprintf(stdout,"current working directory is : %s\n",working);
free(working);
working=NULL;
}
else
{
perror("getcwd() error");
}
continue;
}

while(token!=NULL)
{
token=strtok(NULL,s);
information[i]=token;
i++;
}
information[i]=NULL;
if(strcmp(information[0],"exit")==0 && information[1]==NULL)
{
return 0;
}
if(strcmp(information[0],"exit")==0 && information[1]!=NULL)
{
int q=atoi(information[1]);
printf("%d\n",q);
return 0;
}
if(strcmp(information[0],"pwd")==0 && strcmp(information[1],"-P")==0)
{
working=getcwd(working,0);
if(working!=NULL)
{
fprintf(stdout,"current working directory is : %s\n",working);
free(working);
working=NULL;
}
else
{
perror("getcwd() error");
}
continue;
}
if(strcmp(information[0],"echo")==0&& strcmp(information[1],"-n")==0)
{
int j;
for(j=2;information[j]!=NULL;j++)
{
printf(" %s",information[j]);
}
continue;
}
else if(strcmp(information[0],"echo")==0&& strcmp(information[1],"-e")==0)
{
int j;
for(j=2;information[j]!=NULL;j++)
{
if(strcmp(information[j],"\\")==0)
{
printf("\n");
}
else
{
printf(" %s",information[j]);
}
}
continue;
}
else if (strcmp(information[0],"echo") ==0 ) {
int j;
for(j=1;information[j]!=NULL;j++)
{
printf(" %s",information[j]);
}
continue;
}


hist[l]=NULL;
if(strcmp(information[0],"history")==0&& information[1]==NULL)
{
int q;
for(q=0;hist[q]!=NULL;q++)
{
printf(" %s\n",hist[q]);
}
continue;
}
else if(strcmp(information[0],"history")==0&& information[1]!=NULL && strcmp(information[1],"-c")!=0)
{
int q;
int q1=atoi(information[1]);
for(q=0;q<q1;q++)
{
printf(" %s\n",hist[q]);
}
continue;
}
else if(strcmp(information[0],"history")==0&& strcmp(information[1],"-c")==0)
{
int q;
for(q=0;hist[q]!=NULL;q++)
{
hist[q]=NULL;
}
l=0;
continue;
}
if(strcmp(information[0],"cd")==0)
{
if(chdir((char *)information[1])!=0)
{
printf("no directory of this name present\n");
}
continue;
}
//int result=fork();
if(fork()==0)
{
if(strcmp(information[0],"ls")==0)
{
char a[70]="/home/alka/Desktop/code";
strcat(a,"/ls");
execl(a,information[0],information[1],information[2],NULL);
}
if(strcmp(information[0],"date")==0)
{
char a[70]="/home/alka/Desktop/code";
strcat(a,"/date");
execl(a,information[0],information[1],NULL);
}
if(strcmp(information[0],"cat")==0)
{
char a[70]="/home/alka/Desktop/code";
strcat(a,"/cat");
execl(a,information[0],information[1],information[2],information[3],NULL);
}
if(strcmp(information[0],"rm")==0)
{
char a[70]="/home/alka/Desktop/code";
strcat(a,"/rm");
execl(a,information[0],information[1],information[2],NULL);
}
if(strcmp(information[0],"mkdir")==0)
{
char a[70]="/home/alka/Desktop/code";
strcat(a,"/mkdir");
execl(a,information[0],information[1],information[2],information[3],NULL);
}
return -1;
}
else
{
wait(NULL);
}
i=0;
}
return 0;
}
// code ends here
