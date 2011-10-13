#include "sockets.h"
Sockets::Sockets(int port, Const static int familyType)
{
  int sockfd;
  struct sockaddr_in my_addr; 
  struct sockaddr_in serv_addr; 
  if(familyType ==1)
    {
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      my_addr.sin_family = AF_INET; 
      my_addr.sin_port = htons(port);
      my_addr.sin_addr.s_addr = INADDR_ANY;
      memset(&(myaddr),0, sizeof(struct sockaddr_in)); 
      int connect(sockfd,*my_addr,
    }
  if(familyType ==2)
    {
    }
  if(familyType ==3)
    {
    }
  if(familyType ==4)
    {
    }
  if(familyType ==5)
    {
    }
  if(familyType ==6)
    {
    }
  if(familyType ==7)
    {
    }
  if(familyType ==8)
    {
    }
}


