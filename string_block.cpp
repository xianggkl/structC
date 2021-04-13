#include<iostream>
#include<cstdio>
#include<malloc.h>
#include <cstdlib>
using namespace std;
#define BLOCK_SIZE 4
typedef struct Block_Node
{
    char data[BLOCK_SIZE];
    struct Block_Node *next;
}Bnode;
typedef struct Block_Linkstring
{
    Bnode *font,*rear;
    int length;//此为元素个数
}Blstring;
void Init_Blockstring(Blstring *b)
{
    b->length=0;
}//初始化块链串
int Get_BlockstringLength(Blstring *b)
{
    return b->length;
}//得到块链长度，元素个数
int Judeg_BlockstringEmpty(Blstring *b)
{
    if(b->font==b->rear)
    {
        return 1;
    }
    else{
        return 0;
    }
}//判断块链是否为空
void Value_Blstring(Blstring *b)
{
    int i,j;
    char ch;
    Bnode *p;
    p=(Bnode*)malloc(sizeof(Bnode));
    while((ch=getchar())!='\n'){
        if(b->length%BLOCK_SIZE==0)
        {
            p=(Bnode*)malloc(sizeof(Bnode));
            for(j=0;j<BLOCK_SIZE;j++)
            {
                p->data[j]={'#'};//将新结点初始值赋为#
            }
            p->data[0]=ch;
            p->next=NULL;
            b->rear->next=p;
            b->rear=p;
            p=p->next;
            b->length++;//b元素个数加一
        }//当尾结点满时，扩充一个新的结点
        else{
            for(i=0;i<BLOCK_SIZE;i++)
            {
                if(b->rear->data[i]=='#'){break;}
            }
            b->rear->data[i]=ch;
            b->length++;
        }//当尾结点没有满，找到尾结点最后一个元素位置，直接赋值
    }//当正在输入时执行
}//给b块链串输入字符串,需要初始化数组为#
void Print_Blstring(Blstring *b)
{
    int i,j;
    Bnode *q;
    q=b->font;
    if(b->length==0)
    {
        cout <<"error"<<endl;
        return;
    }
    for(i=0;i<b->length/BLOCK_SIZE+1;i++)
    {
        q=q->next;
        for(j=0;j<BLOCK_SIZE&&q->data[j]!='#';j++)
        {
            cout <<q->data[j];
        }
    }
}
int main ()
{
    Blstring *s;
    s=(Blstring*)malloc(sizeof(Blstring));
    s->font=(Bnode*)malloc(sizeof(Bnode));
    s->rear=s->font;
    Init_Blockstring(s);
    Value_Blstring(s);
    Print_Blstring(s);
    return 0;
}








