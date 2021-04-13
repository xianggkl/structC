#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
typedef struct stack
{
    int data[MAX_size];
    int top;
}Sqstack;//数组栈
void Init_stack(Sqstack *s)
{
    s->top=-1;
}//将栈初始化，置空栈。
int Judeg_stackEmpty(Sqstack *s)
{
    return (s->top==-1);
}//判断s栈是否为空栈，是则返回1，不是为0
int Judge_stackFull(Sqstack *s)
{
    return (s->top==MAX_size-1);
}//判断s栈是否为满栈，是则返回1，不是为0
void Push_stack(Sqstack *s,int x)
{
    if(Judge_stackFull(s))
    {
        printf("ERROR!OVERFLOW!");
        return;
    }
    else{
        (s->top)++;
        (s->data)[s->top] = x;
    }
}//将x进栈
int Pop_stack(Sqstack *s)
{
    if(Judeg_stackEmpty(s))
    {
        printf("ERROR!EMPTY!");
        return 0;
    }
    else{
        return s->data[s->top--];
    }
}//出栈(此时栈内仍存在已经出栈的元素)