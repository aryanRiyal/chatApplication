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

void clientHandle( int listenfd, int *newSocketfd){
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(struct sockaddr);
    memset( &clientAddress, '\0', sizeof(clientAddress));
    *newSocketfd = Accept( listenfd, (SA *)&clientAddress, &len);
     
    // addNewClient();
    printf("[+]New Socket Created %d\n", *newSocketfd);
}
