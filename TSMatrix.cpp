#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define MAX_SIZE  5
typedef struct TriArray
{
    int i,j;//i为第几行，j为第几列
    char value;//值
}Tarray;
typedef struct TsMatrix
{
    Tarray data_M[MAX_SIZE+1];//data_M[0]不使用
    int row,col,Tnum;
}TsMatrix;//row为原矩阵行，col为原矩阵列，Tnum为原矩阵非零元的个数，data_M为储存原矩阵非零元素的三元组
void Create_TSMatrix(TsMatrix **T)
{
    *T=(TsMatrix *)malloc(sizeof(TsMatrix));
    (*T)->data_M[MAX_SIZE+1]={0};
    (*T)->row=0;
    (*T)->col=0;
    (*T)->Tnum=0;
}
void Push_toTsMatrix(TsMatrix *T,int M[MAX_SIZE][MAX_SIZE])
{
    int i=0,j=0;
    T->col=MAX_SIZE;
    T->row=MAX_SIZE;
    for(i=0;i<MAX_SIZE;i++)
    {
        for(j=0;j<MAX_SIZE;j++)
        {
            if(M[i][j]!=0)
            {
                T->Tnum++;
                T->data_M[T->Tnum].i=i+1;
                T->data_M[T->Tnum].j=j+1;
                T->data_M[T->Tnum].value=M[i][j];
            }
        }
    }
}//M二维数组，先行后列。且三元组必须按照先行后列的顺序输入.
void Tran_TsMatrix(TsMatrix T,TsMatrix *s)
{
    s->col=T.col;
    s->row=T.row;
    s->Tnum=T.Tnum;
    if(T.Tnum)
    {
        int m=0,n=0,q=0;
        int col_num[MAX_SIZE+1]={0};
        int col_first[MAX_SIZE+1]={0};
        for(m=1;m<=T.Tnum;m++)
        {
            col_num[T.data_M[m].j]++;
        }//找到每一列有的非零元素的个数
        col_first[0]=1;
        for(n=1;n<=T.Tnum;n++)
        {
            col_first[n]=col_first[n-1]+col_num[n-1];
        }//找到每一列的第一个应该放在新三元组的那个位置上
        for(q=1;q<=T.Tnum;q++)
        {
            int w=T.data_M[q].j;//w为原三元组第q个元素的列
            int p=col_first[w];//p为第w列应该在新三元组s的第几个位置
            s->data_M[p].value=T.data_M[q].value;
            s->data_M[p].i=T.data_M[q].j;
            s->data_M[p].j=T.data_M[q].i;
            p++;
        }
    }
}//将T三元组的转置三元组放入s中