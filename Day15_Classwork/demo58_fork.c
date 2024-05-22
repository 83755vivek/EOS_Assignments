

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* incr_func(void* param)  {
        int i;
		for(i=1; i<=10; i++)  {
                   printf("incr: %d\n", i);
				   sleep(1);
				   if(i == 5)
				           fork();
            }
			return NULL;
}

void* decr_func(void* param)  {
          int i;
		  for(i=-1; i>=-10; i--)  {
                printf("decr: %d\n", i);
				sleep(1);
			}
			return NULL;
}

int main() {
       int i, ret;
	   pthread_t it, dt;
	   //incr_func(NULL); //simple fn call by main thread itself
	   ret = pthread_create(&it, NULL, incr_func, NULL);
	   if(ret < 0) {
              perror("pthread_create() failed");
			  _exit(0);
        }
		ret = pthread_create(&dt, NULL, decr_func, NULL);
		if(ret < 0) {
              perror("pthread_create() failed");
			  _exit(0);
	    }

		for(i=1; i<=10; i++) {
              printf("main: %d\n", i);
			  sleep(1);
        }
		return 0;

}
