#include"header.h"

void Select(int maxfd,fd_set *readset,fd_set *writeset,fd_set *exceptset,const struct timeval *timeout){
	
	int n = select(maxfd,readset,writeset,exceptset,timeout);

	if(n < 0){
		fprintf( stderr,"[-]select() error with error number : %d\n",errno);
	        perror("Error Description: ");
	       	exit(EXIT_FAILURE);
	}
}


void serverSelect(int maxfd,int listenfd,fd_set *readset,fd_set *writeset){
	int newSokcetfd = 0;
	char buff[MB];

	memset(buff,0,sizeof(buff));

	Select(maxfd+1,readset,writeset,NULL,NULL);
	
	//check the server listenfd
	if(FD_ISSET(listenfd,readset)){
		clientHandle(listenfd,&newSocketfd);
		printf("New Socket Created: %d\n",newSocketfd);
	}

	if(FD_ISSET(STDIN_FILENO,readset)){
		if(read(0,buff,sizeof(buff)) > 0){
			for(int i = 0; i < server.totalClient; i++){
				serverSend(server.clientList[i].fileDes,buff);
			}
		}
	}
	
	memset(buff,0,sizeof(buff));
	for(int i = 0;i < server.totalClient;i++){
		if(FD_ISSET(server.clientList[i].fileDes,readset)){
			serverRecv(server.clientList[i].fileDes,buff);
		}
	}
}


