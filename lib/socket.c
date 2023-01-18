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
