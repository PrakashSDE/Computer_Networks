#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
main()
{
        struct msgbht
        {
                long mtype;
                char mtext[100];
        }send,recv;
        int msg,len;
        msg=msgget((key_t)25,IPC_CREAT|0666);
        if (msg<0)
        {
                perror("message failed");
                exit(1);
        }
        strcpy(send.mtext,"i am fine thank you!");
        send.mtype=2;
        len=strlen(send.mtext);
        if (msgrcv(msg,&recv,100,1,0)==-1)
        {
                perror("message failed");
                exit(1);
        }
        if(msgsnd(msg,&send,len,0)==-1)
{
                perror("message failed");
                exit(1);
        }
        printf("message from program 1 is : \n%s\n",recv.mtext);
}