#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100

typedef struct Sstack_int
{
    int *Sbase,*Stop;
    int Sstack_size;
}Sstack_int;//使用指针构建栈___储存整型
void Init_Sstack_int(Sstack_int &s)
{
    s.Sbase=(int*)malloc(STACK_INIT_size*sizeof(int));
    if(!s.Sbase)
    {
        printf("ERROR!");
        exit (-1); //存储分配失败
    }
    s.Stop=s.Sbase;
    s.Sstack_size=STACK_INIT_size;
}//初始化一个空栈
void Push_Sstack_int(Sstack_int &s,int x)
{
    if((s.Stop-s.Sbase)>=STACK_INIT_size)//如果满栈则增加储存空间
    {
        printf("INCREASE THE SIZE!");
        s.Sbase=(int*)realloc(s.Sbase,(STACK_INIT_size+STACK_size_increasement)*sizeof(int));
        if(!s.Sbase) exit (-1); //存储分配失败则退出
        s.Stop=s.Sbase+s.Sstack_size;
        s.Sstack_size=s.Sstack_size+STACK_size_increasement;
    }
    *s.Stop++ = x;
}//进栈
void Destroy_Sstack_int(Sstack_int &s)
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
void Clear_Sstack_int(Sstack_int &s)
{
    s.Stop=s.Sbase;
}//清空栈，使栈底等于栈顶，有效元素为零
int Judeg_SstackEmpty_int(Sstack_int &s)
{
    if(s.Stop==s.Sbase)
    {
        return 1;
    }
    else{
        return 0;
    }
}//判断栈s是否为空栈，是则返回1
int Pop_Sstack_int(Sstack_int &s)
{
    if(Judeg_SstackEmpty_int(s))
    {
        printf("ERROR!EMPTR!");
        return 0;
    }
    else{
        s.Stop--;
        return *(s.Stop);
    }
}//出栈
int Get_top_int(Sstack_int &s)
{
    if(s.Sbase == s.Stop)
        return 0;
    return *(s.Stop-1);
}//得到最上方元素
int Length_Sstack_int(Sstack_int &s)
{
    return s.Stop-s.Sbase;
}//返回这个栈的长度