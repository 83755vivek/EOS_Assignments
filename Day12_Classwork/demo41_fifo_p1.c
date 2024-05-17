#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// p1 -- writer
int main() {
	int fd, cnt;
	char str[32];
	fd = open("/tmp/vivek_fifo", O_WRONLY);



	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("enter a string: ");
	scanf("%s", str);

	cnt = write(fd, str, strlen(str)+1);
	printf("written in fifo: %d bytes\n", cnt);

	close(fd);
	return 0;
}

