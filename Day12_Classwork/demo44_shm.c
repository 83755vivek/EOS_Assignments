



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SHM_KEY	0x4231

typedef struct shm {
	int count;
} shm_t;

int main() {
	int i, ret, s, shmid;
	shm_t *ptr;

	shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT|0600);
	if(shmid < 0) {
		perror("shmget() failed");
		_exit(1);
	}

	ptr = (shm_t*)shmat(shmid, NULL, 0);
	if(ptr == (void*)-1) {
		perror("shmat() failed");
		_exit(2);
	}

	// mark shm for destruction -- it will destroyed when attach count become 0.
	shmctl(shmid, IPC_RMID, NULL);
	
	ptr->count = 0;
	ret = fork();
	if(ret == 0) {
		// child
		for(i=1; i<=5; i++) {
			ptr->count++;
			printf("incr: %d\n", ptr->count);
			sleep(1);
		}
		shmdt(ptr);
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
		shmdt(ptr);
	}
	return 0;
}

