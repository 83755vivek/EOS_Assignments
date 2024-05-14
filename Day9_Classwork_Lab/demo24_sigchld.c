

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>

void sigchld_handler(int sig) {
       int s;
       wait(&s);
       printf("child exit status: %d\n", WEXITSTATUS(s));
}

 int main()  {
          int ret, i;
          signal(SIGCHLD, sigchld_handler);
          ret = fork();
          if(ret == 0) {
                 // child process
                for(i=1; i<=5; i++) {
                        printf("child: %d\n", i);
                        sleep(1);
                   }
                   _exit(2);
             }
              else {
                  // parent process
                  for(i=1; i<=10; i++)  {
                          printf("parent: %d\n", i);
                           sleep(1);
                     }
               }
               return 0;
}
