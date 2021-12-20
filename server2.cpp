#include <string>
#include <iostream> 
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
using namespace std;
#define PORT 12012
int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	const char *first_place = "client X: Aneudys";
	//char second_place[1024];
	//char final_buf[1024];
	const char *hello = " ";
	//const char *hello2 = "Client X: Aneudys recived before Client Y: Aneudys";
	const char *hello2;
	// Creating socket
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	// setting and attching socket
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
												&opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	
	// bind socket to address
	if (bind(server_fd, (struct sockaddr *)&address,
								sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	// accept 1st client
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	int flag = 0;
	//while loop to keep server open for 2 clients
	while(flag < 2){
	valread = read( new_socket , buffer, 1024);
	printf("%s\n",buffer );

	//cout << buffer[7] << endl;
	//cout << strcmp ( buffer, first_place) << endl;
	if(buffer[7] == 'X'){
	  hello2 = "Client X: Aneudys recieved before Client Y: Aneudys";
	}
	else{
	  hello2 = "Client Y: Aneudys recieved before Client X: Aneudys";
	}
	send(new_socket , hello2 , strlen(hello2) , 0 );
	
	flag++;

	//SECOND CLIENT NOW
	//here I repeat everything again for the second client

	//accpet second client
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	valread = read( new_socket , buffer, 1024);
	
	printf("%s\n",buffer );
	
	send(new_socket , hello2 , strlen(hello2) , 0 );
	flag++;
	printf("Sent Acknowledgement to both X and Y\n");
	}
	
	return 0;
}
