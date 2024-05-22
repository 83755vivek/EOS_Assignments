


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

volatile int flag = 0;
// declare mutex
pthread_mutex_t m;
// declare cond variable
pthread_cond_t c;

void* print_sunbeam(void *param)  {
          char *str = "SUNBEAM\n";
		  int i;
		  // lock mutex
		  pthread_mutex_lock(&m);
		  for(i=0; str[i]!='\0'; i++) {
                    putchar(str[i]);
					fflush(stdout);
					sleep(1);
        }
		flag = 1;
		// signal/notify infotech thread
		pthread_cond_signal(&c);
		//unlock mutex
		pthread_mutex_unlock(&m);
		//..
		return NULL;
}

void* print_infotech(void *param)  {
         char *str = "INFOTECH\n";
		 int i;
		 // lock mutex
		 pthread_mutex_lock(&m);
		 // wait until flag become 1
		 while(flag == 0)
		      pthread_cond_wait(&c, &m);
	     for(i=0; str[i]!='\0'; i++) {
                   putchar(str[i]);
				   fflush(stdout);
				   sleep(1);
	}
         //unlock mutex
		 pthread_mutex_unlock(&m);
		 //...
		 return NULL;
}
   
int main() {
         pthread_t st, it;
		 // initialize mutex
		 pthread_cond_init(&c, NULL);
		 pthread_create(&it, NULL, print_infotech, NULL);
		 pthread_create(&st, NULL, print_sunbeam, NULL);
		 pthread_join(st, NULL);
		 pthread_join(it, NULL);
		 //destroy Mutex
		 pthread_mutex_destroy(&m);
		 //destroy cond var
		 pthread_cond_destroy(&c);
		 printf("bye!\n");
		 return 0;

		 }
