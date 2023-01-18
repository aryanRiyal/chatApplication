/* bind() */
int Bind( int sockfd, SA *addr, socklen_t addrlen){
    int n;
    if((n= bind(sockfd,addr, addrlen)) < 0){
        fprintf( stderr,"[-]bind() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Bind Successful\n");
    return (n);
}

