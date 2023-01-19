#include "../lib/header.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("[-]Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("IP Address: %s\n",argv[1]);

    int clientSocket=0;
    int maxfd=0;
    char buff[MAXLINE];

    createClientSocket( &clientSocket, argv[1]);
    
    maxfd = clientSocket;

    while(1){
        memset( buff,'\0', sizeof(buff));
        printf("Client: ");
        scanf("%[^\n]%*c", &buff[0]);
        send( clientSocket, buff, strlen(buff), 0);
        if(strncmp( buff, ":exit", 5) == 0){
            close(clientSocket);
            printf("[-]Disconnected from server.\n");
            exit(1);
        }
        if(recv( clientSocket, buff, MAXLINE, 0) < 0){
            printf("[-]Error in receiving data.\n");
        }else{
            printf("Server: %s\n", buff);
        }	
        /*if(strncmp( buff, ":exit", 5) == 0){
            close(clientSocket);
            printf("[-]Removed from server.\n");
            exit(1);
        }*/
    }
    return (EXIT_SUCCESS);
}
