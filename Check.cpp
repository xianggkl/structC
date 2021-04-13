#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
int Check()
{
    Sstack s;
    char ch;
    Init_Sstack(s);
    while((ch=getchar())!='\n'){
        if(ch=='('||ch=='['||ch=='{')
        {
            Push_Sstack(s,ch);
        }
        else if(ch==')')
        {
            if(Pop_Sstack(s)!='(')
            {
                printf("ERROR!");
                return 0;
            }
        }
        else if(ch==']')
        {
            if(Pop_Sstack(s)!='[')
            {
                printf("ERROR!");
                return 0;
            }
        }
        else if(ch=='}')
        {
            if(Pop_Sstack(s)!='{')
            {
                printf("ERROR!");
                return 0;
            }
        }
        else{
            printf("ERROR!");
            return 0;
        }
    }
    if(Judeg_SstackEmpty(s))
    {
        return 1;
    }
    else{
        return 0;
    }
}//括号匹配算法