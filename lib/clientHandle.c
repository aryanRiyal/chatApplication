#include"header.h"

/* accept() */
int Accept( int sockfd, SA *addr, socklen_t *addrlen){
    int n;
    if((n= accept(sockfd, addr, addrlen)) < 0){      
        fprintf( stderr,"[-]accept() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Client Connected\n");
    return (n);
}

void addNewClient(struct sockaddr_in clientInfo,int newSocketfd){
	
	char ip[INET_ADDRSTRLEN] = {0};
	char name[MAX_NAME_SIZE] = {0};

	//get client name 
	serverRecv(newSocketfd,name);
	printf("name : %s\n",name);

	//get the IP and port of client
	int port = ntohs(clientInfo.sin_port);
	inet_ntop(AF_INET,&clientInfo.sin_addr,ip,INET_ADDRSTRLEN);
	printf("[Client-Info] : Port = %d, IP = %s\n",port,ip);

	if(server.totalClient >= NO_OF_CLIENTS){
		perror("ERROR: ");
	}
	
	//add the new client data in client list
	strncpy(server.clientList[server.totalClient].cname,name,strlen(name));
	server.clientList[server.totalClient].port = port;
	strcpy(server.clientList[server.totalClient].ip,ip);
	server.clientList[server.totalClient].fileDes = newSocketfd;

	server.totalClient++;
}

void clientHandle( int listenfd, int *newSocketfd){
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(struct sockaddr);
    memset( &clientAddress, '\0', sizeof(clientAddress));
    *newSocketfd = Accept( listenfd, (SA *)&clientAddress, &len);
     
    addNewClient(clientAddress,*newSocketfd);
}
