/* listen() */
int Listen( int sockfd, int backlog){
    int n;
    char *ptr;
    if( (ptr = getenv("LISTENQ")) != NULL){
        backlog = atoi(ptr);
    }
    if((n= listen(sockfd, backlog)) < 0){
        fprintf( stderr,"[-]listen() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Listening for the Client...\n\n");
    return (n);
}
