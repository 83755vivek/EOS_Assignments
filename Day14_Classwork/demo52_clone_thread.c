


#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int child_task(void *param)  {
          int i;
          for(i=1; i<=10; i++)   {
                 printf("child: %d\n", i);
    		 sleep(1);
      } 
       return 0;
}

int main() { 
     int i, ret, size;
     size = 2 * 1024 * 1024;
     void *stack = malloc(size);   // 2  MB stack
     ret = clone(child_task, (char*)stack + size, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND, NULL);
     for(i=1; i<=10; i++)  {
           printf("parent: %d\n", i);
           sleep(1);
}
 return 0;

}
