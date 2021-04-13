#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define MAX_QUEUE_SIZE  100
typedef struct Queue_circle
{
    char *data;
    int font;
    int rear;
}Cqueue;
void Init_Cqueue(Cqueue& Q)
{
    Q.data=(char*)malloc(MAX_QUEUE_SIZE*sizeof(char));
    if(Q.data==NULL)
    {
        cout << "Error"<<endl;
        return;
    }
    Q.font=Q.rear=0;
}
void Push_Cqueue(Cqueue& Q,char x)
{
    if((Q.rear+1)%MAX_QUEUE_SIZE==Q.font)
    {
        cout << "Error"<<endl;
        return;
    }//如果队列满则退出
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAX_QUEUE_SIZE;//此步构建循环
}//将最后一个存储空间闲置
char Pop_Cqueue(Cqueue& Q)
{
    char e;
    if(Q.font==Q.rear)
    {
        cout << "Error"<<endl;
        return 0;
    }//如果队列为空则退出
    e=Q.data[Q.font];
    Q.font=(Q.font+1)%MAX_QUEUE_SIZE;//此步构建循环
    return e;
}
int Get_QueueLength(Cqueue& Q)
{
    return (Q.rear-Q.font+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;//循环队列求队列长度公式
}
