#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
void LineEdit()
{
    Sstack s;
    char ch,e,correct_line[Max_Line];
    Init_Sstack(s);
    while(ch!='$'){
        if((ch=getchar())!='\n')
        {
            if(ch=='#')
            {
                e=Pop_Sstack(s);
            }
            else if(ch=='@')
            {
                Clear_Sstack(s);
            }
            else{
                Push_Sstack(s,ch);
            }
        }
        else{
            while(!Judeg_SstackEmpty(s)){
                correct_line[Length_Sstack(s)-1]=Pop_Sstack(s);
            }
            cout <<correct_line<<endl;
        }
    }
    Destroy_Sstack(s);
}//定义#为退格符，@为删除此行,$为结束编辑，仅对于一行使用