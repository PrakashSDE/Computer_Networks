#include<stdio.h>
#include<stdlib.h>
main()
{
        int p1[2],p2[2],n,pid;
        char buf1[25],buf2[25];
        pipe(p1);
        pipe(p2);
        printf("\nreadfds=%d%d\n",p1[0],p2[0]);
        printf("\nwritefds=%d%d\n",p1[1],p2[1]);
        pid=fork();
        if(pid==0)
        {
                close(p1[0]);
                printf("\nCHILD PROCESS SENDING DATA\n");
                write(p1[1],"armstrong no btw 1 and 1000\n",50);
                close(p2[1]);
                read(p2[0],buf1,25);
                printf("Reply from parent:%s\n",buf1);
        }
        else
        {
                close(p1[1]);
                printf("\nPARENT PROCESS RECEIVES DATA\n");
                n=read(p1[0],buf2,sizeof(buf2));
                printf("\nData received from child through pipe:%s",buf2);
                int i=1,c=0;
                for(i=1;i<=1000;i++)
                {
                        int temp=i;
                        int rev=0,a=0;
                        while(temp!=0)
                        {
                                a=temp%10;
                                rev+=a*a*a;
                                temp=temp/10;
                        }
                        if(rev==i)
                        {
                                c++;
                                printf("%d\n",i);
                        }
                }


          sleep(3);
                close(p2[0]);
                char res[10];
                sprintf(res,"%d",c);
                write(p2[1],res,10);
                printf("\nreply send\n");
        }
}