#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define<netdb.h>
using namespace std;
void error(const char* msg)
{
perror(msg);
exit(1);
}
int main(int argc,char* argv[])
{
    int sockfd,portno,n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    if(argc<2)
    {
        fprintf(stderr,"you need to provide port number program terminated\n");
        exit(1);
    }
    char buffer[255];
    portno=atoi(argv[2]);
    sockfd = socket(AF_INET,SOCK_STREAM,0);
   if(sockfd<0)
   error("error in opening socket");
   server = gethostbyname(argv[1]);
   if(server==NULL)
   fprintf(stderr,"No such host");
   bzero((char *)&serv_addr,sizeof(serv_addr));
   serv_addr.sin_faimly = AF_INET;
   bcopy((char* )server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
   serv_addr.sin_port = htons(portno);
   if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
   perror("connection failed");
   while(1)
   {
       bzero(buffer,255);
       fgets(buffer,255,stdin);
       n = write(sockfd,buffer,sizeof(buffer));
       if(n<0)perror("error in writing");
       bzero(buffer,255);
       n = read(sockfd,buffer,255);
       if(n<0)error("error in reding");
       printf("server : %s",buffer);
       if(strncmp(buffer,"Bye",3)==0)break;
   }
   close(sockfd);
   return 0;
}