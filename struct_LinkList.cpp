#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
typedef struct Node
{
    char data;
    struct Node *next;
}ListNode,*LinkList;
LinkList Create_list_frontpart()
{
    char ch;
    ListNode *s;
    LinkList head;
    head=(LinkList)malloc(sizeof(ListNode));
    head->next=NULL;
    while((ch=getchar())!='\n')
    {
        s=(LinkList)malloc(sizeof(ListNode));
        s->data=ch;
        s->next=head;
        head=s;
    }
    return head;
}//头插法建立单链表
LinkList Create_list_backpart()
{
    LinkList head=NULL,r=NULL,p;
    char ch;
    while((ch=getchar())!='\n'){
        p=(LinkList)malloc(sizeof(ListNode));
        p->data=ch;
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            r=head;
        }
        else{
            r->next=p;
            r=p;
        }
    }
    return head;
}//不带头结点的尾插法建立单链表
LinkList Create_list_backpart_1()
{
    char ch;
    LinkList head=NULL,r=NULL,p=NULL;
    head=(LinkList)malloc(sizeof(ListNode));
    r=head;
    while((ch=getchar())!='\n')
    {
        p=(LinkList)malloc(sizeof(ListNode));
        p->data=ch;
        p->next=NULL;
        r->next=p;
        r=p;
    }
    return head;
}//带头节点的尾插法建立单链表
LinkList GetNode_number(LinkList head,int i)
{
    int j=0;
    LinkList p,r;
    p=(LinkList)malloc(sizeof(ListNode));
    p=head;
    r=(LinkList)malloc(sizeof(ListNode));
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(i==j)
    {
        return p;
    }
    else return r;
}//得到元素序号i的节点
LinkList GetNode_key(LinkList head,char x)
{
    int j=0;
    LinkList p,r;
    r=(LinkList)malloc(sizeof(ListNode));
    p=(LinkList)malloc(sizeof(ListNode));
    p=head->next;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            return p;
        }
        else{
            p=p->next;
        }
    }
    printf("ERROR!");
    return r;
}//按值查找节点，带头节点
LinkList GetNext_node(LinkList p)
{
    int i=0;
    LinkList r;
    r=(LinkList)malloc(sizeof(ListNode));
    if(p->next==NULL)
    {
        printf("ERROR!");
        return r;
    }
    else{
        return p->next;
    }
}//得到后继节点，无后继节点返回空节点
LinkList GetPro_node(LinkList p,LinkList head)
{
    int i=0;
    LinkList r;
    r=(LinkList)malloc(sizeof(ListNode));
    if(p==head->next)
    {
        printf("ERROR!");
        return r; 
    }
    else{
        while(head->next!=p){
            head=head->next;
        }
        return head;
    }
}//head为带头结点的单链表
//得到前驱结点，无前驱结点返回空指针
LinkList GetEnd_node(LinkList head)
{
    LinkList r;
    r=(LinkList)malloc(sizeof(ListNode));
    if(head->next==NULL)
    {
        printf("ERROR!");
        return head;
    }
    else{
        while(head->next!=NULL){
            head=head->next;
        }
        return head;
    }
}//得到最后一个节点
LinkList GetFirst_node(LinkList head)
{
    return head;
}//得到表首节点
void Insert_i_node(LinkList head,char x,int i)
{
    LinkList p,r;
    r=(LinkList)malloc(sizeof(ListNode));
    r->data=x;
    p=GetNode_number(head,i-1);
    if(p==NULL)
    {
        printf("ERROR!");  
    }
    else{
        r->next=p->next;
        p->next=r;
    }
}//带头节点，将x插入到第i个元素的前面
void Deleteafter(LinkList p)
{
    LinkList q;
    q=(LinkList)malloc(sizeof(ListNode));
    q=p->next;
    if(q==NULL)
    {
        printf("ERROR!");
    }
    else{
        p->next=q->next;
        free(q);
    }
}//删除p节点下一个节点
void Delete_i_node(LinkList head,int i)
{
    LinkList p,r;
    p=GetNode_number(head,i-1);
    r=p->next;
    if(p==NULL||r==NULL)
    {
        printf("ERROR!");
    }
    else{
        p->next=r->next;
        free(r);
    }
}//删除第i个元素所在的节点
LinkList MergeList(LinkList head1,LinkList head2)
{
    LinkList New_head=NULL,r;
    New_head=head1;
    r=New_head;
    head1=head1->next;
    head2=head2->next;
    while(head1!=NULL&&head2!=NULL){
        if((head1->data)<=(head2->data))
        {
            New_head->next=head1;
            head1=head1->next;
            New_head=New_head->next;
            New_head->next=NULL;
        }
        else{
            New_head->next=head2;
            head2=head2->next;
            New_head=New_head->next;
            New_head->next=NULL;
        }
    }
    if(head1==NULL)
    {
        while(head2!=NULL){
            New_head->next=head2;
            head2=head2->next;
            New_head=New_head->next;
            New_head->next=NULL;
        }
    }
    else{
        while(head1!=NULL){
            New_head->next=head1;
            head1=head1->next;
            New_head=New_head->next;
            New_head->next=NULL;
        }
    }
    return r;
}//head1与head2，有带头节点，都是递增排列，合成New_head一个链表且递增排列,也带有头结点。
LinkList Create_circlelist()
{
    LinkList head=NULL,p=NULL,r=NULL;
    char ch;
    head=(LinkList)malloc(sizeof(ListNode));
    r=head;
    while((ch=getchar())!='\n'){
        p=(LinkList)malloc(sizeof(ListNode));
        p->data=ch;
        p->next=NULL;
        head->next=p;
        head=head->next;
    }
    head->next=r;
    return r;
}
//尾插法创建循环链表