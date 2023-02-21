#include<stdio.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
main()
{
        int wrfd,rdfd,n,ret_val,i;
        char buf[50];
        ret_val=mkfifo("np1",0666);
        ret_val=mkfifo("np2",0666);
        rdfd=open("np1",O_RDONLY);
        wrfd=open("np2",O_WRONLY);
        n=read(rdfd,buf,50);
        buf[n]='\0';
        printf("full duplex server:read from pipe:%s\n",buf);
        i=0;
        while(i<n)
        {
                if(buf[i]=='a')
                        printf("a encountered\n");
                else if(buf[i]=='e')
                        printf("e encountered\n");
                else if(buf[i]=='i')
                        printf("i encountered\n");
                else if(buf[i]=='o')
                        printf("o encountered\n");
                else if(buf[i]=='u')
                        printf("u encountered\n");
                i++;
        }
        write(wrfd,"completed!",15);
}