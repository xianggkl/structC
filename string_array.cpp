#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define MAX_STRING_SIZE 100
typedef struct
{
    char str[MAX_STRING_SIZE];
    int length;
}stringArray;//定长顺序存储
void Connect_String(stringArray *s,stringArray *r)
{
    int i=0;
    if((s->length+r->length)>s->length)
    {
        cout << "Error"<<endl;
        return;
    }//如果s不够长，则直接退出
    for(i=0;i<r->length;i++)
    {
        s->str[s->length+i]=r->str[i];
    }
    s->length=s->length+r->length;
}//将r中字符串放到s字符串的后面
stringArray* Copy_string(stringArray *s,stringArray *r)
{
    int i=0;
    for(i=0;i<s->length;i++)
    {
        r->str[i]=s->str[i];
    }
    r->length=s->length;
    return r;
}//将s串复制到r串
void Print_string(stringArray *s)
{
    int i=0;
    if(s->length==0)
    {
        cout <<"Error"<<endl;
        return;
    }//如果串为空，则直接退出
    for(i=0;i<s->length;i++)
    {
        printf("%c",s->str[i]);
    }//按顺序打印字符
}
stringArray* Get_pos_String(stringArray *s,int pos,int len)
{
    stringArray *r;
    int i;
    if((s->length-pos+1<len)||pos<1||len<1||pos>s->length)
    {
        cout <<"Error"<<endl;
        return NULL;
    }//如果pos，len不符合存在子串的条件
    r->length=len;//置r串长度为len
    for(i=0;i<len;i++)
    {
        r->str[i]=s->str[pos+i];
    }//遍历进行赋值
    return r;//返回r串
}//从第pos个元素（此为子串第一个元素）开始，取之后的len长度子串返回
