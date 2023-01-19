#include "../lib/header.h"

int main(void){
    int listenfd=0;
    int maxfd=0;
    // struct sockaddr_in clientAddress;
    socklen_t addr_size;
    int n_client=0;
    char buff[MAXLINE];

    memset(&server,'\0',sizeof(struct serverData));
    // calling socket(), bind(), listen() with error handling
    createServerSocket( &listenfd);

    maxfd = listenfd;

    while(1){
        n_client++;
        clientSocket = Accept( serverSocket, (SA *)&clientAddress, &addr_size);
        while(1){
            memset( buff,'\0',sizeof(buff));
            recv(clientSocket, buff, MAXLINE, 0);
            if(strncmp(buff, ":exit",5)==0){
                printf("\n[+]Disconnected from %s:%d - Client(%d)\n\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port), n_client);
                break;
            }else{
                printf("Client(%d): %s\n",n_client, buff);
                send( clientSocket, buff, strlen(buff), 0);
                memset( buff, '\0', sizeof(buff));
            }
        }
        close(clientSocket);
    }
    close(serverSocket);
    printf("\n...Terminating the session...\n");
    return (EXIT_SUCCESS);
}
