#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
main()
{
int msgid;
key_t key;
int mykey;
msgid=msgget((key)/mykey,IPC_CREAT|0);
printf("message queue is created with key value %d",msgid);
}