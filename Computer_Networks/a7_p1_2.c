
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#define serv_port 7001
main(int agrc,char *argv[])
{
        int sockfd,newsockfd;
        int clilen;
        struct sockaddr_in cli_addr,serv_addr;
        int i;
        char buf[100];
        if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
        {
                printf("cannot create socket\n");
                exit(0);
        }
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=INADDR_ANY;
        serv_addr.sin_port=htons(atoi(argv[1]));
        if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
        {
                printf("unable to bind local address\n");
                exit(0);
        }
        listen(sockfd,5);
        while(1)
        {
                clilen=sizeof(cli_addr);
                newsockfd=accept(sockfd,(struct sockaddr*) &cli_addr, &clilen);
                if(newsockfd<0)
                {
                        printf("accept error\n");
                        exit(0);
                }
                if(fork()==0)
                {
                        close(sockfd);
                        for(i=0;i<100;i++)
                        buf[i]='\0';
                        strcpy(buf,"message from server: yes, I am ready");
                        send(newsockfd,buf,100,0);
                        for(i=0;i<100;i++)
                        buf[i]='\0';
                        recv(newsockfd,buf,100,0);
                        printf("%s\n",buf);
                        close(newsockfd);
                        exit(0);
                }
                close(newsockfd);
        }
}