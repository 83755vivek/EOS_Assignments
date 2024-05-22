

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_func(void *param) {
       int i;
	   for(i=1; i<=10; i++)  {
               printf("thread: %d\n", i);
			   sleep(1);
        }
		return NULL;
}

int main()  {
          pthread_t th;
		  pthread_create(&th, NULL, thread_func, NULL);
		  printf("press enter to cancel the thread...\n");
		  getchar();
		  pthread_cancel(th); // sends cancellation request to the thread
		  printf("bye!\n");
		  return 0;
}
