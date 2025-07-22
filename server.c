#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT		8080
#define MAX_CLIENTS 	10

int port = 8080;

struct Student
{
	char name[50];
	int age;
};

int main()
{ 
	int server_fd;
	int new_socket;
	int client_sockets[MAX_CLIENTS];
	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);
	char buffer[1024];
	fd_set readfds;

	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		client_sockets[i] = 0;
	}
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd == 0)
	{
		perror("Socket Failed");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	bind(server_fd, (struct sockaddr *)&address, sizeof(address));
	listen(server_fd, 5);
	printf("Server started on PORT %d.\n", PORT);
	while(1)
	{
		FD_ZERO(&readfds);
		
		FD_SET(server_fd, &readfds);
		int max_fd = server_fd;
	}
	return 0;
}
