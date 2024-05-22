

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//declare mutex
pthread_mutex_t m;
int count = 0;

void* incr_func(void* param)  {
           int i, newcnt;
		   for(i=1; i<=10; i++)  {
                 //lock mutex
				 pthread_mutex_lock(&m);
				 newcnt = count + 1;
				 count = newcnt;
				 printf("incr: %d\n", count);
				 // unlock mutex
				 pthread_mutex_unlock(&m);
				 sleep(1);
				 
		 }
		 return NULL;
}

void* decr_func(void* param)  {
        int i, newcnt;
		for(i=1; i<=10; i++) {
                 //lock mutex
				 pthread_mutex_lock(&m);
				 newcnt = count - 1;
				 printf("decr: %d\n", count);
				 // unlock mutex
				 pthread_mutex_unlock(&m);
				 sleep(1);
           }
		   return NULL;
}

int main() {
        int i, ret;
		pthread_t it, dt;
		pthread_mutexattr_t ma;
		//create and initialize mutex
		pthread_mutexattr_init(&m);  //initiallize mutex attrs to default values
		#ifdef DEBUG
		       printf("creating error check mutex...\n");
			   pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_ERRORCHECK);
	    #else
		       printf("creating normal mutex...\n");
			   pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_NORMAL);
	    #endif
		ret = pthread_mutex_init(&m, &ma);

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
