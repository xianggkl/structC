#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define MAXSIZE 10
typedef char DataType;
typedef struct BinTNodes
{
    DataType data;
    struct BinTNodes *lch,*rch;
}BinTree;
typedef struct Queue_Node
{
    BinTree *data;
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
void Push_Queue(Queue& Q,BinTree *x)
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
BinTree* Pop_Queue(Queue& Q)
{
    BinTree* e;
    Qnode *p;
    if(Q.front==Q.rear)
    {
        cout <<"error!"<<endl;
        return NULL;
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
void Init_BinTree(BinTree **T)
{
    *T=(BinTree *)malloc(sizeof(BinTree));
    (*T)->data=0;
    (*T)->lch=NULL;
    (*T)->rch=NULL;
}//初始化二叉树
void Create_BinTree(BinTree **t)
{
    DataType e;
    scanf("%c",&e);
    if(e=='#')
    {
        (*t)=NULL;
    }
    else{
        Init_BinTree(t);
        (*t)->data=e;
        Create_BinTree(&((*t)->lch));
        Create_BinTree(&((*t)->rch));
    }
}//先序创建二叉树.(自动以#补充二叉树为完全二叉树)
void travel_layer(BinTree *t)
{
    Queue Q;
    BinTree *temp;
    BinTree *e;
    temp=t;
    Init_Queue(Q);
    Push_Queue(Q,temp);
    while(&Q){
        e=Pop_Queue(Q);
        if(temp->lch!=NULL)
        {
            Push_Queue(Q,temp->lch);
        }
        if(temp->rch!=NULL)
        {
            Push_Queue(Q,temp->rch);
        }
        printf("%d",e);
    }
}//按层遍历二叉树
void travel_PreOrder(BinTree *t)
{
    if(t)
    {
        printf("%c",t->data);
        travel_PreOrder(t->lch);
        travel_PreOrder(t->rch);
    }
}//先序遍历二叉树
void travel_MidOrder(BinTree *t)
{
    if(t)
    {
        travel_MidOrder(t->lch);
        printf("%c",t->data);
        travel_MidOrder(t->rch);
    }
}//中序遍历二叉树（递归算法）

void travel_PostOrder(BinTree *t)
{
    if(t)
    {
        travel_PostOrder(t->lch);
        travel_PostOrder(t->rch);
        printf("%c",t->data);
    }
}//后序遍历二叉树
void Delete_BinTree(BinTree *t)
{
    if(t)
    {
        Delete_BinTree(t->lch);
        Delete_BinTree(t->rch);
        free(t);
        t=NULL;//清除野指针
    }
}//销毁某根节点下的二叉树
void Copy_BinTree(BinTree t,BinTree *Newt)
{
    if(&t==NULL)
    {
        Newt=NULL;
    }
    else{
        Init_BinTree(&Newt);
        Newt->data=t.data;
        Copy_BinTree(*(t.lch),Newt->lch);
        Copy_BinTree(*(t.rch),Newt->rch);
    }
}//二叉树复制.(t为原二叉树，Newt为BinTree*型的变量即可)
int Get_BinTreeHeight(BinTree *t)
{
    if(t==NULL)
    {
        return 0;
    }
    else{
        return MAX(Get_BinTreeHeight(t->lch),Get_BinTreeHeight(t->rch))+1;
    }
}
int MAX(int i,int j)
{
    if(i>j) return i;
    else return j;
}
int Get_BinNodeNumber(BinTree *t)
{
    if(t==NULL)
    {
        return 0;
    }
    else{
        return Get_BinNodeNumber(t->lch)+Get_BinNodeNumber(t->rch)+1;
    }
}//得到二叉树结点的个数
int Get_BinTree_LeafNumber(BinTree *t)
{
    if(t==NULL)
    {
        return 0;
    }
    else if(!t->lch&&!t->rch)
    {
        return 1;
    }
    else{
        return Get_BinTree_LeafNumber(t->lch)+Get_BinTree_LeafNumber(t->rch);
    }
}//得到二叉树叶子结点的个数
int Get_BinTree_Node_1(BinTree *t)
{
    if(t==NULL)
    {
        return 0;
    }
    if((!t->lch&&t->rch)||(t->lch&&!t->rch))
    {
        return Get_BinTree_Node_1(t->lch)+Get_BinTree_Node_1(t->rch)+1;
    }
    else{
        return Get_BinTree_Node_1(t->lch)+Get_BinTree_Node_1(t->rch);
    }
}
void Printf_Allways(BinTree *t,int Way_length,DataType Way[MAXSIZE])
{
    int i=0;
    if(t==NULL)
    {
        printf("Empty!");
        return;;
    }//如果二叉树t为空，则打印Empty，并直接退出
    else{
        Way[Way_length]=t->data;//先将t结点数据存入数组。
        if(t->lch==NULL&&t->rch==NULL)
        {
            for(i=0;i<Way_length;i++)
            {
                printf("%c",Way[i]);
            }//由于遍历顺序永远自左至右，不会出现不同路径重叠
        }
        else{
            //此处Way_length传入的是Way_length+1，不会改变Way_length的值
            Printf_Allways(t->lch,Way_length+1,Way);//先打印左子树路径
            Printf_Allways(t->rch,Way_length+1,Way);//后打印右子数路径
        }
    }
}//以Way_length记录遍历的路径的长度，Way储存路径。需传入Way_length==0，二叉树指针t，空DataType型数组Way
void Exchange_Lnode_Rnode(BinTree *t)
{
    if(t==NULL)
    {
        return;//当结点为空直接退出
    }
    else{
        BinTree *temp;//辅助变量
        //直接交换左右结点地址
        temp=t->lch;
        t->lch=t->rch;
        t->rch=temp;
        //对左右子树分别进行操作
        Exchange_Lnode_Rnode(t->lch);
        Exchange_Lnode_Rnode(t->rch);
    }
}//交换左右结点
int Get_BinTree_depth(BinTree *t)
{
    if(t==NULL)
    {
        return 0;
    }
    else{
        return MAX(Get_BinTree_depth(t->lch),Get_BinTree_depth(t->rch))+1;
    }
}//得到二叉树的深度

int Find_BinTree_EQUAL(BinTree *t1,BinTree *t2)
{
    int find=0;
    if(t1==NULL&&t2==NULL)
    {
        find=1;
        return find;
    }
    else{
        if(t1->data==t2->data)
        {
            if(Find_BinTree_EQUAL(t1->lch,t2->rch))
            {
                find=1;
            }
        }
        return find;
    }
}

BinTree* Copy_BinTree(BinTree *t)
{
    if(t==NULL){
        return NULL;
    }
    else{
        BinTree *temp;
        Init_BinTree(&temp);
        temp->data=t->data;
        temp->lch=Copy_BinTree(t->lch);
        temp->rch=Copy_BinTree(t->rch);
        return temp;
    }
}//复制二叉树，返回值为新树的根节点