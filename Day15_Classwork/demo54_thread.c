


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// step 1: implement thread function
void* print_table(void *param) {
	int i, *num = (int*)param;
	for(i=1; i<=10; i++) {
		printf("%d * %d = %d\n", *num, i, *num * i);
		sleep(1);
	}
	return NULL;
}

int main() {
	int ret, num1=3, num2=13, num3=23;
	pthread_t t1, t2, t3;
	// step 2: call pthread_create()
	ret = pthread_create(&t1, NULL, print_table, &num1);
	ret = pthread_create(&t2, NULL, print_table, &num2);
	ret = pthread_create(&t3, NULL, print_table, &num3);

	printf("press enter to exit...\n");
	getchar();
	return 0;
}

