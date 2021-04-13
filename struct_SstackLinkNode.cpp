#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
typedef struct SNode
{
    char data;
    struct SNode *next;    
}SstackLink_Node;//定义链栈