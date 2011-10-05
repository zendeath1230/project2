#include "headerFiles.h"

Public:

Socket(); 

int socket(int domain, int type, int protocol);

int bind(int sockfd, const struct sockaddress* localAddress, socklen_t addrLen); 

int listen(int sockfd, int backlog);

int accept(int sockfd, struct sockaddr *clintAddr, socklen_t* addrLen);

int connect(int sockfd, const struct sockaddress* remoteAddress, socklen_t addrLen);

pid_t fork(fork);

int send(int sockfd, const void*sendbuf, int nbytes, int flags);

int recv(int sockfd, void* recvbuf, int nbytes, int flags); 

int sendto(int sockfd, constvoid* buffer, int nbytes, int flags, struct sockaddr* destinationAddress, socklen_t addrlen); 

int recvfrom(int sockfd,void* buffer, int nbytes, int flags, struct sockaddr* sourceAddress, socklen_t* addrLen); 

int close(int sockfd); 

~Socket();
