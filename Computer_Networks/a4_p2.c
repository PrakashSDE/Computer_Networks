#include<stdio.h>
#include<stdlib.h>
main()
{
        int pipefd[2],n,pid;
        char buff[100];
        pipe(pipefd);
        printf("\nreadfd=%d",pipefd[0]);
        printf("\nwritefd=%d",pipefd[1]);
        pid=fork();
        if(pid==0)
        {
                close(pipefd[0]);
                printf("\nCHILD PROCESS SENDING DATA\n");
                write(pipefd[1],"hello world",12);
        }
        else
        {
                close(pipefd[1]);
                printf("\nPARENT PROCESS RECEIVES DATA");
                n=read(pipefd[0],buff,sizeof(buff));
                printf("\nsize of data:%d",n);
                printf("\ndaa received from child through pipe:%s",buff);
        }
}