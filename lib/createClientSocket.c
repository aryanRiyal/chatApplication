/* socket() */
int Socket( int family, int type, int protocol){
    int n;
    if((n= socket(family, type, protocol)) < 0){
        fprintf( stderr,"[-]send() error with error number : %d\n",errno);
        perror("Error Description ");
        exit(EXIT_FAILURE);
    }
    printf("[+]Socket Created\n");
    return (n);
}

/* connect() */
int Connect( int sockfd, SA *addr, socklen_t addrlen){
    int n;
    if((n = connect(sockfd, addr, addrlen)) < 0){
        fprintf( stderr, "[-]connect() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Connection Established\n");
    return (n);
}

void createClientSocket(int *clientSocket, char *IP_Address){
    struct sockaddr_in serverAddress;

    *clientSocket = Socket(AF_INET, SOCK_STREAM, 0);
    memset( &serverAddress, '\0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);

    if(inet_pton(AF_INET, IP_Address, &serverAddress.sin_addr)<=0){
        printf("[-]inet_pton Error for %s\n", IP_Address);
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    Connect( *clientSocket, (SA *)&serverAddress, sizeof(serverAddress));
}
