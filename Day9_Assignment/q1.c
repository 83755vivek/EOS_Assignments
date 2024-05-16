//1. Input signal number and a process id from user. Send given signal to the given process using kill() syscall.


#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
 int pid,sign,ret;
 printf("Enter pid number: \n");
 scanf("%d",&pid);
 printf("Enter sign number: \n");
 scanf("%d",&sign);
 ret = kill(pid,sign);
 
 return 0;
}
