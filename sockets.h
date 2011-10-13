#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>

#define BACKLOG 10

using namespace std;

class Sockets
{
public:
Sockets(int port, const char* IP,int type)
{

  //TCP CLIENT
  if(type ==1)
    {
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      memset(&serv_addr,0, sizeof(serv_addr)); 
      serv_addr.sin_family = AF_INET; 
      serv_addr.sin_port = htons(port);
      inet_pton(AF_INET,IP,&serv_addr.sin_addr);
 
      if(connect(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
	{
           std::cout<<"error on TCP Connect"<<std::endl; 
	}
	else
	  {
	   std::cout<<"TCP Connection established"<<std::endl; 
	  }
       }
	//UDP CLIENT
     if(type ==2)
	  {
      sockfd = socket(AF_INET, SOCK_DGRAM, 0);
      memset(&(serv_addr),0, sizeof(serv_addr)); 
      serv_addr.sin_family = AF_INET; 
      serv_addr.sin_port = htons(port);
      inet_pton(AF_INET,IP,&serv_addr.sin_addr);
           }
	     };
Sockets(int port, int type)
{

//type 1 TCP SERVER
if(type ==1)
{
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      memset(&serv_addr,0, sizeof(serv_addr)); 
      serv_addr.sin_family = AF_INET; 
      serv_addr.sin_port = htons(port);
      serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
     
      if(bind(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr)) ==-1)
	{
	  std::cout<<"TCP SERVER DID NOT SUCCESSFULLY BIND"<<std::endl; 
	}
      else
	{
	  std::cout<<"TCP SERVER: BIND SUCCESSFULL ON PORT"<<std::endl; 
	}

      if(listen(sockfd,BACKLOG) ==-1)
	{
	  std::cout<<"TCP SERVER: NOT ABLE TO LISTEN FOR CONNECTIONS"<<std::endl; 
	}
      else
	{
	  std::cout<<"TCP SERVER: LISTENING TO INCOMMING CONNECTION"<<std::endl; 
	}
	
      if(fd= accept(sockfd,(struct sockaddr*)&my_addr, &addr_size)==-1)
	{
	  std::cout<<"TCP SERVER: WAITING TO ACCEPT CONNECTIONS"<<std::endl; 
	} 
      

}
//type 2 UDP SERVER
if(type ==2)
{
  sockfd = socket(AF_INET, SOCK_DGRAM,0);
  memset(&serv_addr,0, sizeof(serv_addr)); 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port); 
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
  

     if(bind(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr)) ==-1)
	{
	  std::cout<<"UDP SERVER DID NOT SUCCESSFULLY BIND"<<std::endl; 
	}
      else
	{
	  std::cout<<"UDP SERVER: BIND SUCCESSFULL ON PORT"<<std::endl; 
	}


  
}

 };
private:
int sockfd; 
int fd; 
struct sockaddr_in my_addr; 
struct sockaddr_in serv_addr; 
socklen_t addr_size; 
};




