#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
typedef struct Dnode
{
    char data;
    struct Dnode *next,*prev;
}Dlinklist;
Dlinklist* Create_Dlink()
{
    Dlinklist *head,*p,*r;
    char ch;
    head=(Dlinklist*)malloc(sizeof(Dlinklist));
    r=head;
    head->prev=NULL;
    head->next=NULL;
    while((ch=getchar())!='\n'){
        p=(Dlinklist*)malloc(sizeof(Dlinklist));
        p->data=ch;
        p->next=NULL;
        p->prev=head;
        head->next=p;
        head=head->next;
    }
    return r;
}//创建有头结点的双向链表
Dlinklist* GetDnode_i_number(Dlinklist* head,int i)
{
    Dlinklist *p,*r=NULL;
    int j=0;
    p=head;
    while(p!=NULL){
        if(j<i)
        {
            p=p->next;
            j++;
        }
        else{
            return p; 
        }
    }
    printf("ERROR!");
    return r;
}//得到元素序号为i的节点
void Insert_i_Dnode_frontpart(Dlinklist* head,int i,char ch)
{
    Dlinklist *p,*r;
    p=(Dlinklist*)malloc(sizeof(Dlinklist));
    p->data=ch;
    if(p->prev!=NULL)
    {
        r=GetDnode_i_number(head,i-1);
        p->next=r->next;
        r->next->prev=p;
        p->prev=r;
        r->next=p;
    }
    else{
        printf("ERROR!");
    }
}//在元素序号为i的节点之前插入元素ch