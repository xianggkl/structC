#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
typedef struct Node
{
    char data;
    struct Node *next;
}ListNode,*LinkList;
typedef struct Dnode
{
    char data;
    struct Dnode *next,*prev;
}Dlinklist;
typedef struct stack
{
    int data[MAX_size];
    int top;
}Sqstack;//数组栈
typedef struct Sstack
{
    char *Sbase,*Stop;
    int Sstack_size;
}Sstack;//使用指针构建栈
typedef struct SNode
{
    char data;
    struct SNode *next;    
}SstackLink_Node;//定义链栈




LinkList Create_head()
{
    LinkList head;
    head=(LinkList)malloc(sizeof(ListNode));
    return head;
}//建立空链表
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






/*存在错误
LinkList GetNode_key(LinkList head,char x)
{
    int j=0;
    LinkList p,r;
    r=(LinkList)malloc(sizeof(ListNode));
    p=(LinkList)malloc(sizeof(ListNode));
    p=head;
    while(p->next!=NULL)
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
}//按值查找节点
*/






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



void Init_Sstack(Sstack &s)
{
    s.Sbase=(char*)malloc(STACK_INIT_size*sizeof(char));
    if(!s.Sbase)
    {
        printf("ERROR!");
        exit (-1); //存储分配失败
    }
    s.Stop=s.Sbase;
    s.Sstack_size=STACK_INIT_size;
}//初始化一个空栈


void Push_Sstack(Sstack &s,char x)
{
    if((s.Stop-s.Sbase)>=STACK_INIT_size)//如果满栈则增加储存空间
    {
        printf("INCREASE THE SIZE!");
        s.Sbase=(char*)realloc(s.Sbase,(STACK_INIT_size+STACK_size_increasement)*sizeof(char));
        if(!s.Sbase) exit (-1); //存储分配失败则退出
        s.Stop=s.Sbase+s.Sstack_size;
        s.Sstack_size=s.Sstack_size+STACK_size_increasement;
    }
    *s.Stop++ = x;
}//进栈

void Destroy_Sstack(Sstack &s)
{
    if(s.Sbase)
    {
        free(s.Sbase);
        s.Sbase=NULL;
        s.Stop=NULL;
        s.Sstack_size=0;
        printf("THE STACK IS FREE!");
    }
}//销毁栈


void Clear_Sstack(Sstack &s)
{
    s.Stop=s.Sbase;
}//清空栈，使栈底等于栈顶，有效元素为零
int Judeg_SstackEmpty(Sstack &s)
{
    if(s.Stop==s.Sbase)
    {
        return 1;
    }
    else{
        return 0;
    }
}//判断栈s是否为空栈，是则返回1
char Pop_Sstack(Sstack &s)
{
    if(Judeg_SstackEmpty(s))
    {
        printf("ERROR!EMPTR!");
        exit(-1);
    }
    else{
        s.Stop--;
        return *(s.Stop);
    }
}//出栈
int Get_top(Sstack &s)
{
    if(s.Sbase == s.Stop)
        return 0;
    return *(s.Stop-1);
}//得到最上方元素
int Length_Sstack(Sstack &s)
{
    return s.Stop-s.Sbase;
}//返回这个栈的长度


void TEN_to_EIGHT()
{
    Sstack s;
    int N;
    char e;
    Init_Sstack(s);
    printf("Please input N(ten).");
    scanf("%d",&N);
    while(N){
        Push_Sstack(s,(char)(N%8));
        N=N/8;
    }//余数入栈
    while(!Judeg_SstackEmpty(s)){
        e=Pop_Sstack(s);
        printf("%d",(int)e);
    }
}//将十进制转换为八进制

int main()
{
    Sstack s;
    Init_Sstack(s);
    for(int i=0;i<10;i++)
        Push_Sstack(s, i);
    for(int i=0;i<10;i++)
    {
        int a = Get_top(s);
        printf("%d  ", a);
        Pop_Sstack(s);
    }
    printf("\n");
    if(Judeg_SstackEmpty(s) == 1)
        printf("不为空\n");
    int len = Length_Sstack(s);
    printf("%d\n", len);
    Destroy_Sstack(s);
    TEN_to_EIGHT();
    return 0;
}
