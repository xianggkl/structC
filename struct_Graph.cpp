#include<iostream>
#include<cstdio>
#include<malloc.h>
#include <cstdlib>
using namespace std;
#define n 10
#define e 20
#define INF 0x3f3f3f3f
typedef char vertexType;//定义顶点类型
typedef float weightType;//定义权重类型
typedef struct ArcCell//定义弧
{
    int YN;//定义两个结点是否邻接
    weightType weight;//定义弧的权重
}ArcCell;
typedef struct VertexCell//定义顶点
{
    vertexType vertex;
}VertexCell;
typedef struct Graph
{
    VertexCell ves[n];
    ArcCell arc[n][n];//用邻接矩阵存储
    int VertexNnm;
    int ArcNum;
}Graph;
Graph* InitGraph()
{
    int i=0,j=0;
    Graph *G=(Graph*)malloc(sizeof(Graph));
    G->VertexNnm=0;
    G->ArcNum=0;
    while(i<n){
        G->ves[i].vertex='#';
        i++;
    }//置顶点集为#空
    i=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            G->arc[i][j].YN=0;
            G->arc[i][j].weight=INF;
        }
    }//置弧集邻接距离为无穷大INF
}//初始化图
void CreateGraph(Graph *G,int N,int E)
{
    VertexCell tempVes;
    int i=0,j=0;
    G->VertexNnm=N;
    G->ArcNum=E;
    printf("Please input six vertexs.\n");
    while((tempVes.vertex=getchar())!='\0'){
        G->ves[i]=tempVes;
        i++;
    }//先输入顶点
    printf("Please input ArcCell.YN.\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&G->arc[i][j].YN);
            if(G->arc[i][j].YN==1)
            {
                printf("Please input weight.\n");
                scanf("%f",&G->arc[i][j].weight);
            }
        }
    }//输入弧数据，与权重
}//创建图
void DestroyGraph(Graph *G)
{
    free(G);
    G=NULL;
}//销毁图
void InsertVes(Graph *G,VertexCell *v)
{
    if(G->VertexNnm==n)
    {
        printf("Error!Full!");
        return;
    }
    G->ves[G->VertexNnm]=*v;//录入新顶点
}//插入一个新顶点
int FindVes(Graph *G,VertexCell *v)
{
    int i=0;
    for(i=0;i<G->VertexNnm;i++)
    {
        if(G->ves[i].vertex==v->vertex)
        {
            return i+1;//返回所找元素的位置次序
        }
    }
    printf("Cannot find!");
    return 0;
}
void DeleteVes(Graph *G,VertexCell *v)
{
    if(G->VertexNnm==0)
    {
        printf("Error!Empty!");
        return;
    }//当图空时直接返回

    int pos=FindVes(G,v);

    G->ves[pos-1].vertex='#';//将此顶点在顶点集删除
    G->VertexNnm--;//将顶点个数减一
    
    int i=0;
    for(i=0;i<G->VertexNnm;i++)
    {
        if(G->arc[pos-1][i].YN==1)
        {
            G->arc[pos-1][i].YN=0;
            G->arc[pos-1][i].weight=INF;
            G->ArcNum--;
        }
        if(G->arc[i][pos-1].YN==1)
        {
            G->arc[i][pos-1].YN=0;
            G->arc[i][pos-1].weight=INF;
            G->ArcNum--;
        }
    }//将此顶点在弧集中删除,并调节弧个数

}//删除一个顶点
void InertArcs(Graph *G,VertexCell *v,VertexCell *w,weightType weight)
{
    int posV=FindVes(G,v);
    int posW=FindVes(G,w);
    G->arc[posV-1][posW-1].YN=1;
    G->arc[posV-1][posW-1].weight=weight;
}//插入有向弧v->w
void DeleteArcs(Graph *G,VertexCell *v,VertexCell *w)
{
    int posV=FindVes(G,v);
    int posW=FindVes(G,w);
    G->arc[posV-1][posW-1].YN=0;
    G->arc[posV-1][posW-1].weight=INF;
}//删除有向弧


typedef struct Arcnode
{
    vertexType Name;//顶点
    weightType Weight;//弧权重
    struct Arcnode *next;//下一个弧指针
}Arcnode;//弧表结点
typedef struct vnode
{
    int data;//顶点位置
    struct Arcnode *firstArc;//第一个弧指针
}vnode;//顶点表结点

vnode* InitGraphLink(vnode GLink[n])
{
    int i=0;
    for(i=0;i<n;i++)
    {
        GLink[i].data='#';
        GLink[i].firstArc=NULL;
    }
    return GLink;
}
vnode* CreateGraphLink(vnode GLink[n])
{
    int i=0,j=0;
    printf("Please input the vertexs.\n");
    for(i=0;i<n;i++)
    {
        GLink[i].data=getchar();
    }//先输入顶点信息
    printf("Please input the arcs.\n");
    for(i=0;i<n;i++)
    {
        printf("对于第%d个顶点.\n",i+1);
        scanf("%")
    }
}
