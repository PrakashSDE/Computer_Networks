#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
int main()
{
        struct msgbht
        {
                long mtype;
                char mtext[100];
        }send,recv;
        int msg,len;
        msg=msgget((key_t)25,IPC_CREAT|0666);
        if(msg<0)
        {
                perror("message failed");
                exit(1);
        }
        strcpy(send.mtext,"msg 1: Hello, how are you?");
        send.mtype=1;
        len=strlen(send.mtext);
        if(msgsnd(msg,&send,len,0)==-1)
        {
                perror("message failed");
                exit(1);
        }
        strcpy(send.mtext,"\nmsg 2: Where are you?");
        send.mtype=2;
        len=strlen(send.mtext);
if(msgsnd(msg,&send,len,0)==-1)
        {
                perror("meaasge failed");
                exit(1);
        }
        strcpy(send.mtext,"\nmsg 3: What are you doing?");
        send.mtype=3;
        len=strlen(send.mtext);
        if(msgsnd(msg,&send,len,0)==-1)
        {
                error("meaasge failed");
                exit(1);
        }
        strcpy(send.mtext,"\nmsg 4: Why are you here now?");
        send.mtype=4;
        len=strlen(send.mtext);
        if(msgsnd(msg,&send,len,0)==-1)
        {
                perror("mesage failed");
                exit(1);
        }
}