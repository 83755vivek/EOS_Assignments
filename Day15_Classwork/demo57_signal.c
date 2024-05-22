


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

void sigint_handler(int sig) {
         printf("SIGINT caught...\n");
		 printf("Current PID=%d, Current TID=%d, Current POSIX Thread ID: %lu\n", getpid(), gettid(), pthread_self());
		 if(gettid() == getpid())   //if main thread (pid==tid
		   _exit(0);                    // then terminate the process
		 else                             // otherwise
		      pthread_exit(NULL);        //terminate the thread to whom signal was sent
}

void* thread_func(void *param)  {
         int i;
		 for(i=1; i<=10; i++)  {
                 printf("thread: %d\n", i);
				 sleep(1);
		}
		return NULL;
}

int main() {
           pthread_t th;
		   int ret;
		   struct sigaction sa;
		   memset(&sa, 0, sizeof(struct sigaction));
		   sa.sa_handler = sigint_handler;
		   ret = sigaction(SIGINT, &sa, NULL);

		   ret = pthread_create(&th, NULL, thread_func, NULL);
		   printf("New POSIX Thread ID: %lu\n", th);
		   printf("press enter to send signal the thread...\n");
		   getchar();

		   pthread_kill(th, SIGINT);
		   printf("press enter to exit...\n");
		   getchar();

		   printf("bye!\n");
		   return 0;
}

