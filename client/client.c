#include "../lib/header.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("[-]Usage: %s client_Name <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    //printf("IP Address: %s\n",argv[1]);

    int sockfd=0;
    int maxfd=0;
    char buff[MB];
    fd_set readset;
    fd_set writeset;
    fd_set exceptset;


    createClientSocket( &sockfd, argv[1]);
    
    maxfd = sockfd;

    while(1){
        memset( buff,'\0', sizeof(buff));
        
	maxfd = clientBuildfdsets(sockfd,&readset,&writeset,&exceptset);
	clientSelect(maxfd,sockfd,&readset,&writeset);
    }
    close(sockfd);
    return (EXIT_SUCCESS);
}
