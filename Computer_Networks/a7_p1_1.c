#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
main(int agrc,char* argv[])
{
        int sockfd;
        struct sockaddr_in serv_addr;
        int i;
        char buf[100];
        if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
        {
                printf("unable to create socket\n");
                exit(0);
        }
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=inet_addr(argv[2]);
        serv_addr.sin_port=htons(atoi(argv[1]));
        if((connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)))<0)
        {
                printf("unable to connect to server\n");
                exit(0);
        }
        for(i=0;i<100;i++)
        buf[i]='\0';
        recv(sockfd,buf,100,0);
        printf("%s\n",buf);
        for(i=0;i<100;i++)
        buf[i]='\0';
        strcpy(buf,"message from client : hello,are you ready");
        send(sockfd,buf,100,0);
        for(i=0;i<100;i++)
        buf[i]='\0';
        strcpy(buf,"geeksforgeeks");
        send(sockfd,buf,100,0);

        close(sockfd);
}