//3. Find max number of child processes that can be created on Linux using C pro//gram? Hint: use fork() in inﬁnite loop (wisely).


#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
       int ret,s,i,j;
       i=1;
       while(1){
               ret=fork();
               if(ret==0) {
                        //child task
                      printf("desd\n");
                      sleep(5);
                      _exit(0);
	       }
                else if(ret==-1)
                        break;
                else{
                       i++;
                       printf("child count : %d\n",i);
                }
           }
           for(j=1;j<=i;j++)
                   wait(&s);
          return 0;
}
