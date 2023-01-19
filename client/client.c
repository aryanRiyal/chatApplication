#include "../lib/header.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("[-]Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("IP Address: %s\n",argv[1]);

    int sockfd=0;
    int maxfd=0;
    char buff[MB];

    createClientSocket( &sockfd, argv[1]);
    
    maxfd = sockfd;

    while(1){
        memset( buff,'\0', sizeof(buff));
        printf("Client: ");
        scanf("%[^\n]%*c", buff);
        
        send( sockfd, buff, strlen(buff), 0);
        if(strncmp( buff, ":exit", 5) == 0){
            close(sockfd);
            printf("[-]Disconnected from server.\n");
            exit(1);
	}

        recv( sockfd, buff, MAXLINE, 0);
        printf("Server: %s\n", buff);	
        /*if(strncmp( buff, ":exit", 5) == 0){
            close(clientSocket);
            printf("[-]Removed from server.\n");
            exit(1);
        }*/
    }
    close(sockfd);
    return (EXIT_SUCCESS);
}
