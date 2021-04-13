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
int Get_BF(stringArray *s,stringArray *r,int pos)
{
    char *p,*q;
    int j=0,k;
    p=r->str;//p作为模式串的头指针
    q=s->str+pos-1;//q为主串开始匹配的位置的头指针
    k=pos-1;
    while(k<s->length&&j<r->length){
        if(*p==*q)
        {
            k++;q++;
            j++;p++;
        }//如果两指针所存数据相同，则进行下一位置的比较
        else{
            k=k-j+1;q=s->str+k;//主串指针指向下一个位置
            p=r->str;j=0;//模式串指针指向模式串第一个位置
        }//如果两指针所存数据不相同,则重置匹配位置
    }//当p，q指针位置在s，r串范围内时进行匹配
    if(j==r->length)
    {
        return (k-r->length+1);//如果成功匹配，则返回首元素的次序
    }
    else{
        return -1;
    }
}//暴力匹配算法，s为主串，r为模式串，pos为开始匹配的位置,pos位置为第pos个元素的位置

int main ()
{
    int i,j,e;
    stringArray s,r;
    s.length=10;
    r.length=2;
    for(i=0;i<s.length;i++)
    {
        s.str[i]=getchar();
    }
    for(j=0;j<r.length;j++)
    {
        r.str[j]=getchar();
    }
    e=Get_BF(&s,&r,1);
    cout <<e<<endl;
    return 0;
}