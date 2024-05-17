

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
// client
#define SERV_PORT	1500
#define SERV_IP		"172.18.4.248"
int main() {
	int cli_fd, ret;
	struct sockaddr_in serv_addr;
	char str[64];
	cli_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(cli_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_aton(SERV_IP, &serv_addr.sin_addr);
	ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("connect() failed");
		_exit(2);
	}

	do {
		printf("client: ");
		gets(str);
		write(cli_fd, str, strlen(str)+1);

		read(cli_fd, str, sizeof(str));
		printf("server: %s\n", str);
	}while(strcmp(str, "bye")!=0);

	close(cli_fd);
	return 0;
}
