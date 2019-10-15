#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;
void error(const char* msg)
{
perror(msg);
exit(1);
}
int main(int argc,char* argv[])
{
    if(argc<2)
    {
        fprintf("you need to provide port number . program terminated\n");
        exit(1);
    }
    int sockfd,newsockfd,portnumber,n;
    char buffer[255];
    struct sockaddr_in serv_addr,cli_addr;
    socklen_t clilen;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        error("error in opening socket \n");
        exit(1);
    }
    bzero((char*)&serv_addr,sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_faimly = AF_INET;
    serv_addr.sin_port = portno;
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd,(struct sockarr*)&serv_addr,sizeof(serv_addr))<0)
    {
        error("binding failed \n");
        exit(1);
    }
     listen(socketfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd,(struct sockaddr *)cli_addr,&clilen);
     while(1)
     {
         bzero(buffer,255);
         n=read(newsockfd,buffer,sizeof(buffer));
          if(n<0)
          {
              error("error in reading");
          }
          printf("client : %s\n",buffer);
        bzero(buffer,255);
        fgets(buffer,255,stdin);
        n=write(newsockfd,buffer,sizeof(buffer));
        if(n<0)error("error in writing\n");
        if(strncmp(buffer,"bye",3)==0)break;
     }
     close(newsockfd);
     close(sockfd);
     return 0;
}