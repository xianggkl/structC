#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
typedef struct Queue_Node
{
    char data;
    Qnode *next;
}Qnode;
typedef struct Queue
{
    Qnode *front;
    Qnode *rear;
}Queue;
void Init_Queue(Queue& Q)
{
    Q.front=Q.rear=(Qnode*)malloc(sizeof(Qnode));
    if(!Q.front)
    {
        cout <<"error!"<<endl;
        return;
    }
    Q.front->next=NULL;
}
void Push_Queue(Queue& Q,char x)
{
    Qnode *p;
    p=(Qnode*)malloc(sizeof(Qnode));//给p结点分配空间
    if(!p)
    {
        cout <<"error"<<endl;
        return;
    }//如果没有分配则error
    p->data=x;
    p->next=NULL;//对新队结点进行初始化
    Q.rear->next=p;//让队尾指针代表的元素位置指向新结点
    Q.rear=p;//重置队尾指针为最后一个结点
}//入队
char Pop_Queue(Queue& Q)
{
    char e;
    Qnode *p;
    if(Q.front==Q.rear)
    {
        cout <<"error!"<<endl;
        return 0;
    }//如果队列内没有元素，则error
    p=Q.front->next;//得到要出队的队列结点
    e=p->data;//得到出队的元素的值
    Q.front->next=p->next;//重新置值队首指针指向出队元素的下一位
    if(Q.rear==p)
    {
        Q.rear=Q.front;
    }//如果队列内只有一个元素，直接free（p）会造成队尾指针失联，所以重新置Q.rear为Q.front
    free(p);//此时释放出队元素的空间
    return e;
}//出队
void Destroy_Queue(Queue& Q)
{
    while(Q.front!=NULL){
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }//直接放弃队尾指针，从队首开始逐个释放结点
}//销毁队列
int Judge_QueueEmpty(Queue& Q)
{
    if(Q.front==Q.rear)
    {
        return 1;
    }
    else{
        return 0;
    }
}//判断队列是否为空
int Get_QueueLength(Queue& Q)
{
    return (Q.rear-Q.front);
}
char Get_QueueHead(Queue& Q)
{
    if(Q.front==Q.rear)
    {
        cout <<"error"<<endl;
        return 0;
    }
    return Q.front->next->data;
}//得到队列队首元素
void Clear_Queue(Queue& Q)
{
    Q.rear=Q.front;
}//清空栈内元素
