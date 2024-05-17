

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct shm {
	int count;
} shm_t;

int main() {
	int i, ret, s;
	shm_t *ptr;
	ptr = (shm_t*)malloc(sizeof(shm_t));
	ptr->count = 0;
	ret = fork();
	if(ret == 0) {
		// child
		for(i=1; i<=5; i++) {
			ptr->count++;
			printf("incr: %d\n", ptr->count);
			sleep(1);
		}
	}
	else {
		// parent
		for(i=1; i<=5; i++) {
			ptr->count--;
			printf("decr: %d\n", ptr->count);
			sleep(1);
		}
		waitpid(ret, &s, 0);
		printf("final count: %d\n", ptr->count);
	}
	free(ptr);
	return 0;
}

