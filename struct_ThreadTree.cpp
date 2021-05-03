#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

typedef int DataType;
#define Link 0;
#define Thread 1;

//ltag=0时，lch指向结点左孩子，ltag=1时，lch指向结点前驱结点；
//rtag=0时，rch指向结点右孩子，rtag=1时，rch指向结点后继结点。
typedef struct BTnode
{
    DataType data;
    struct BTnode *lch;
    int ltag;
    struct BTnode *rch;
    int rtag;
}BTnode;

void Create_ThreadTree(BTnode **t)
{
    DataType data;
    scanf("%d",&data);
    if(data==-1)
    {
        return;
    }
    else{
        Init_ThreadTreeNode(t);
        (*t)->data=data;
        Create_ThreadTree(&((*t)->lch));
        Create_ThreadTree(&((*t)->rch));
    }
}//先序创建线索二叉树(未线索化)

void Init_ThreadTreeNode(BTnode **t)
{
    (*t)=(BTnode*)malloc(sizeof(BTnode));
    (*t)->lch=NULL;
    (*t)->rch=NULL;
    (*t)->data=0;
    (*t)->ltag=Link;
    (*t)->rtag=Link;
}//初始化线索二叉树结点

void Init_ThreadTree_Head(BTnode **head)
{
    (*head)=(BTnode*)malloc(sizeof(BTnode));
    (*head)->lch=(*head);
    (*head)->rch=(*head);
    (*head)->data=0;
    (*head)->ltag=Thread;
    (*head)->rtag=Thread;
}//建立一个空的线索二叉树的头指针

void Link_ThreadTree_Head_TO_T(BTnode *head,BTnode *T)
{
    head->lch=T;
    head->ltag=Link;
    head->rch=head;
}//链接头结点和根节点

void Thread_Tree_font(BTnode *T,BTnode *pre)
{
    if(T==NULL)
    {
        return;
    }//先判断传入的根节点是否为空

    Thread_Tree_font(T->lch,pre);//先对左子树进行中序线索化

    //线索化操作，由于左孩子需要找前驱，右孩子需要找后继，因为前驱可以记录，所以在右孩子找后继时回退一个结点（但pre不变）。
    if(T->lch==NULL)
    {
        T->ltag=Thread;
        T->lch=pre;
    }//当根节点左孩子为空时，置ltag为Thread，lch指向pre前驱结点
    else{
        T->ltag=Link;
    }//根节点左孩子非空时，置ltag为Link

    if(pre->rch==NULL)
    {
        pre->rch=T;
        pre->rtag=Thread;
    }//当前驱结点pre右子树为空时，置rtag为Thread，rch为T
    else{
        pre->rtag=Link;
    }//当前驱结点pre右子树非空时，置rtag为Link
    
    pre=T;//令pre变为当前访问过的结点

    Thread_Tree_font(T->rch,pre);//对右子树进行中序线索化
}//中序遍历二叉树，将其线索化,pre为head头结点，T为根节点

