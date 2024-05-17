


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
// server
#define SERV_PORT	2809
#define SERV_IP		"127.0.0.1"
int main() {
	int serv_fd, cli_fd, ret;
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t socklen;
	char str[64];
	serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(serv_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_aton(SERV_IP, &serv_addr.sin_addr);
	ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("bind() failed");
		_exit(2);
	}

	listen(serv_fd, 5);

	socklen = sizeof(cli_addr);
	cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
	if(cli_fd < 0) {
		perror("accept() failed");
		_exit(3);
	}

	do {
		read(cli_fd, str, sizeof(str));
		printf("client: %s\n", str);

		printf("server: ");
		gets(str);
		write(cli_fd, str, strlen(str)+1);
	}while(strcmp(str, "bye")!=0);
	
	close(cli_fd);

	shutdown(serv_fd, SHUT_RDWR);
	return 0;
}

