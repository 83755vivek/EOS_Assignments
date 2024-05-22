


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

struct ap {
	int start;
	int end;
};

void* ap_sum(void *param) {
	struct ap *ptr = (struct ap*)param;
	int sum = 0, num, *res;
	for(num = ptr->start; num <= ptr->end; num++) {
		printf("adding... %d\n", num);
		sum = sum + num;
		sleep(1);
	}
	printf("result: %d + ... + %d = %d\n", ptr->start, ptr->end, sum);
	res = (int*)malloc(sizeof(int));
	*res = sum;
	//pthread_exit(res);
	return res; // returning dynamically allocated memory address
		// never return addr of local variable, as it will be destroyed when fn is completed
}

int main() {
	int ret, *result;
	pthread_t t1;
	struct ap ap1 = { .start = 10, .end = 15 };
	ret = pthread_create(&t1, NULL, ap_sum, &ap1);
	printf("main thread waiting for t1 thread...\n");
	pthread_join(t1, (void**) &result);
		// current thread (main) will wait for completion of given thread (t1)
		// step1: block current thread until completion of given thread
		// step2: collect result of given thread
	printf("t1 result: %d\n", *result);
	return 0;
}

