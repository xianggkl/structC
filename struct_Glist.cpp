#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
typedef int DataType;
typedef struct Glist_node
{
    int tag;//tag=0则为数据结点，tag=1则为指向子表的指针
    union Glistnode_Type
    {
        DataType data;
        struct Glist_node *sublist;
    };//共用体 ，此节点可以是数据结点或者是指向子表的指针
    struct Glist_node *next;//指向下一个元素
}Glistnode;//广义表的结点定义