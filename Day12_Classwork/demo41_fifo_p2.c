#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fd, cnt;
	char str[32];
	fd = open("/tmp/vivek_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
	cnt = read(fd, str, sizeof(str));
	printf("read from fifo: %d bytes -- %s\n", cnt, str);

	close(fd);
	return 0;
}


