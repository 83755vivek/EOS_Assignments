


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

//declare semaphore
sem_t s;

void* print_sunbeam(void *param)  {
          char *str = "SUNBEAM\n";
		  int i;
		  for(i=0; str[i]!='\0'; i++)  {
                  putchar(str[i]);
				  fflush(stdout);
				  sleep(1);
           }
		   // V(s);
		   sem_post(&s);
		   //  ...
		   return NULL;
 }
void* print_infotech(void *param) {
          char *str = "INFOTECH\n";
		  int i;
		  //P(s);
		  sem_wait(&s);
		  for(i=0; str[i]!='\0'; i++)  {
                  putchar(str[i]);
				  fflush(stdout);
				  sleep(1);
      }
	  // ...
	  return NULL;
}

int main()  {
       pthread_t st, it;
	   // create and initialize semaphore to 0
	   sem_init(&s, 0, 0);
	           //arg1: semaphore id - out param
			   //arg2: 0 if sync threads of current process,
			   //  non-zero if sync threadss across the processes
			   //arg3: initial semaphore count

	    pthread_create(&it, NULL, print_infotech, NULL);
        pthread_create(&st, NULL, print_sunbeam, NULL);
		pthread_join(st, NULL);
		pthread_join(it, NULL);
		//  destroy the semaphore
		sem_destroy(&s);
		printf("bye!\n");
		return 0;
}
