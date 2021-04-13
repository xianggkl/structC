#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
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