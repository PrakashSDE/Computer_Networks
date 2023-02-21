#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main()
{
        int msgid;
        key_t key;
        msgid=msgget((key)25,IPC_CREAT|0666);
        if(msgid<0)
        perror("message failed");
        else
        printf("message queue is created with key value %d",msgid);
}