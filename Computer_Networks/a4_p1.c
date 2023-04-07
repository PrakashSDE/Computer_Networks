
#include<stdlib.h>
#include<stdio.h>
main()
{
        int pipefd[2],n;

        char buff[100];
        pipe(pipefd);
        printf("\nreadfd=%d",pipefd[0]);
        printf("\nwritefd=%d",pipefd[1]);
        write(pipefd[1],"helloworld",12);
        
         n=read(pipefd[0],buff,sizeof(buff));
        printf("\nsize of data %d",n);
        printf("\ndata from pipe: %s\n",buff)
       ;
}
