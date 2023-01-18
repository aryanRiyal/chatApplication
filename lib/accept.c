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
