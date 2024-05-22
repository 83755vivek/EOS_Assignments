

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// declare mutex
pthread_mutex_t m;
int count = 0;

void* incr_func(void* param) {
      int i, newcnt;
	  for(i=1; i<=10000; i++) {
            //lock mutex
			pthread_mutex_lock(&m);
			newcnt = count +1;
			count = newcnt;
			printf("incr: %d\n", count);
			//unlock mutex
			pthread_mutex_unlock(&m);
			//sleep(1)
        }
		return NULL;
}

void* decr_func(void* param)  {
         int i, newcnt;
		 for(i=1; i<=10000; i++) {
            //lock mutex
			pthread_mutex_lock(&m);
			newcnt = count -1;
			count = newcnt;
			printf("decr: %d\n", count);
			// unlock mutex
			pthread_mutex_unlock(&m);
			//sleep(1);
}
     return NULL;

}

int main()  {

     int i, ret;
	 pthread_t it, dt;
	 //create and initialize mutex
	 ret = pthread_mutex_init(&m, NULL);
      
	 ret = pthread_create(&it, NULL, incr_func, NULL);
	 if(ret < 0)  {
            perror("pthread_create() failed");
			_exit(0);
     }
      
	   pthread_join(it, NULL);
	   pthread_join(dt, NULL);
	   printf("final count: %d\n", count);
	   //destroy the mutex
	   pthread_mutex_destroy(&m);
	   return 0;
}
