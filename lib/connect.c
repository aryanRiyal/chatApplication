/* connect() */
int Connect( int sockfd, SA *addr, socklen_t addrlen){
    int n;
    if((n= connect(sockfd, addr, addrlen)) < 0){
        fprintf( stderr, "[-]connect() error with error number : %d\n", errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Connection Established\n");
    return (n);
}
