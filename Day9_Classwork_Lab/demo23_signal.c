

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//step1: implement SIGINT handler
void sigint_handler(int sig) {
      printf("SIGINT caught: %d\n", sig);
}

//step1: implement SIGTERM handler
void sigterm_handler(int sig) {
      printf("SIGTERM caught: %d\n", sig);
}

  int main()  {
      int i=1;
      // step2: register signal handler
      signal(SIGINT, sigint_handler);
      // step2 : register signal handler
      signal(SIGTERM, sigterm_handler);
      while(1)  {
          printf("runnig: %d\n", i++);
          sleep(1);
     }
   return 0;

}
