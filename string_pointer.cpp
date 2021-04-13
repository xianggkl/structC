#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
typedef struct String_heap
{
    char *str;
    int length;//表示现有的元素个数
}Hstring;
void Init_Hstring(Hstring *H,int len)
{
    H->str=(char*)malloc(sizeof(char)*len);//为H->str分配len个char类型的存储空间
    if(H->str==NULL)
    {
        cout << "Error"<<endl;
        return;
    }
    H->length=0;
}
Hstring* Connect_Hstring(Hstring *s,Hstring *r)
{
    Hstring *T;
    char i=0,j=0;
    T->length=s->length+r->length;
    T->str=(char*)malloc(sizeof(char)*T->length);
    if(T->str==NULL)
    {
        cout <<"Error"<<endl;
        return NULL;
    }//未分配内存则直接退出
    for(i=0;i<s->length;i++)
    {
        T->str[i]=s->str[i];
    }//先将s串赋值给T串
    for(j=0;j<r->length;j++)
    {
        T->str[s->length+j]=r->str[j];
    }//再将r赋值给T串
    return T;
}//s在前，r在后，合并在T中
