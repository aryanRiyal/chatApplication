/* send() */
int Send( int sockfd, const void *buff, size_t length, int flags){
    int n;
    if((n= send( sockfd, buff, length, flags)) < 0){
        fprintf( stderr,"[-]send() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}

/* recv() */
int Recv( int sockfd, void *buff, size_t length, int flags){
    int n;
    if((n= recv( sockfd, buff, length, flags)) < 0){
        fprintf( stderr,"[-]recv() error with error number : %d\n", errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}
