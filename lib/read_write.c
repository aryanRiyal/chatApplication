/* write() */
ssize_t Write( int sockfd, void *buff, size_t count){
    ssize_t n;
    if((n= write(sockfd, buff, count)) < 0){        
        fprintf( stderr,"[-]write() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}

/* read() */
ssize_t Read( int sockfd, void *buff, size_t count){
    ssize_t n;
    if((n= read(sockfd, buff, count)) < 0){       
        fprintf( stderr,"[-]read() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}
