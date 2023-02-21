#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
        struct msgbht
        {
                long mtpye;
                char mtext[100];
        }recv;
        int i;
        int qid=msgget((key_t)25,IPC_CREAT|0666);
        if(qid<0)
        {
                error("message failed");
                exit(1);
        }
        for(i=0;i<4;i++)
        {
                if(msgrcv(qid,&recv,100,0,0)==-1)
                {
                        printf("msg %d(i+1) failed",i);
                        exit(1);
                }
                printf("%s",recv.mtext);
}
}
