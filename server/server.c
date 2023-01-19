#include "../lib/header.h"

int main(void){
    int listenfd=0;
    int maxfd=0;
    int newSocketfd=0;
    int n_client=0;
    char buff[MB];

    memset(&server,'\0',sizeof(struct serverData));
    // calling socket(), bind(), listen() with error handling
    createServerSocket( &listenfd);

    maxfd = listenfd;

    while(1){
        n_client++;
        clientHandle( listenfd, &newSocketfd);
        while(1){
            
            memset( buff,'\0',sizeof(buff));
            recv(newSocketfd, buff, MAXLINE, 0);
            if(strncmp(buff, ":exit",5)==0){
                printf("\n[+]Disconnected Client(%d)\n",n_client);
                break;
            }else{
                printf("Client(%d): %s\n",n_client, buff);
                send(newSocketfd, buff, strlen(buff), 0);
                memset( buff, '\0', sizeof(buff));
		}
           // serverRecv( listenfd, buff);
           // serverSend( listenfd, buff);
            }
	close(newSocketfd);
	}
 
    close(listenfd);
    printf("\n...Terminating the session...\n");
    return (EXIT_SUCCESS);
}
