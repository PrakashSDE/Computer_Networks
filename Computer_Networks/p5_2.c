#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
        struct msgbht
        {
                long mtype;
                char mtext[100];
        }send,recv;
        int msg,i,len,c=0;
        msg=msgget((key_t)25,IPC_CREAT|0666);
        if(msg<0)
        {
                perror("message failed");
                exit(1);
        }
        for(i=0;i<strlen(recv.mtext);i++)
        {
                if(recv.mtext[i]=='a' ||recv.mtext[i]=='e'||recv.mtext[i]=='o'||recv.mtext[i]=='i'||recv.mtext[i]=='u')                {
                        c++;
                }
        }
        char w[100]="hello,number of vowles are ";
w=strcat(w,c);
        strcpy(send.mtext,w);
        send.mtype=2;
        len=strlen(send.mtext);
        if(msgrcv(msg,&recv,100,1,0)==-1)
        {
                perror("message failed");
                exit(1);
        }
        if(msgsnd(msg,&send,len,0)==-1)
        {
                perror("message failed");
                exit(1);
        }
        printf("message from program 1 is:\n%s\n",recv.mtext);
}