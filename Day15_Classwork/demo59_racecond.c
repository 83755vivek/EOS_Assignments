


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;

void* incr_func(void* param)  {
        int i, newcnt;
		for(i=1; i<=10000; i++)  {
                 newcnt = count + 1;
				 count = newcnt;
				 printf("incr: %d\n", count);
                // sleep(1);
		}
		return NULL;
}

void* decr_func(void* param)  {
        int i, newcnt;
		for(i=1; i<=10000; i++)  {
               newcnt = count -1;
			   count = newcnt;
			   printf("decr: %d\n", count);
			   //sleep(1);
      }
	  return NULL;
}

int main() {
        int i, ret;
		pthread_t it, dt;
	
	    ret = pthread_create(&it, NULL, incr_func, NULL);
	    if(ret < 0) {
                  perror("pthread_create() failed");
				  _exit(0);
		}
		ret = pthread_create(&dt, NULL, decr_func, NULL);
		if(ret < 0)  {
                  perror("pthread_create() failed");
				  _exit(0);
		}

		pthread_join(it, NULL);
		pthread_join(dt, NULL);
		printf("final count: %d\n", count);
		return 0;
}
