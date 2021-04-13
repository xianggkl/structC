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
int Get_Next(int n,stringArray *r)
{
    if(n<=1)
    {
        return 0;
    }
    else{
        int now=Get_Next(n-1,r);
        if(r->str[now]==r->str[n-1])
        {
            return now+1;
        }
        else{
            now=Get_Next(now-1,r);
            return now;
        }
    }
}
int Get_KMP(stringArray *s,stringArray *r,int pos)
{
    char *p,*q;
    int m,n;
    q=s->str+pos-1;//q为pos位置的指针
    m=pos-1;//pos位置数组下标
    p=r->str;//p为模式串的头指针
    n=0;//模式串初始数组下标
    while(m<s->length&&n<r->length){
        if(*p==*q)
        {
            m++;q++;
            n++;p++;
        }//当此位置匹配成功，主串与模式串指针与下标都后移一位
        else{
            if(n==0)
            {
                m++;q++;
            }
            else{
                n=Get_Next(n,r);p=s->str+Get_Next(n,r);
            }
        }//如果匹配失败,模式串指针与下标左移Next
    }//当下标在数组有效范围之内时执行
    if(n==r->length)
    {
        return (m-r->length+1);//如果成功匹配，则返回首元素的次序
    }
    else{
        return -1;
    }
}//使用kmp算法进行匹配，s为主串，r为模式串，pos为开始匹配的位置，即pos位置为第pos个元素的位置
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
    e=Get_KMP(&s,&r,2);
    cout <<e<<endl;
    return 0;
}