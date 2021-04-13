#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX_size 1000
#define STACK_INIT_size 100
#define STACK_size_increasement 10
#define Max_Line 100
int Let_oprValue(char opr)  
{  
    int value;
    switch (opr)  
    {  
    case '+':  
        value = 1;  
        break;  
    case '-':  
        value = 1;  
        break;  
    case '*':  
        value = 2;  
        break;  
    case '/':  
        value = 2;  
        break;  
    case '(':  
        value = 3;  
        break;  
    case ')':  
        value = 3;  
        break;  
    case '#':  
        value = 0;  
        break;  
    }
    return value;  
}  
int Get_result(char op,int a,int b)
{
    int result;
    switch(op)
    {
        case '+' :{result=a+b;break;}
        case '-' :{result=a-b;break;}
        case '*' :{result=a*b;break;}
        case '/' :{result=a/b;break;}
        default :{return 0;}
    }
    return result;
}//传入运算符号，并得出结果，返回得数
void Get_Calculation_value()
{
    Sstack sym;
    Sstack_int num;
    char ch,xch;
    int a,b;
    Init_Sstack_int(num); Init_Sstack(sym);
    Push_Sstack(sym,'#');//先将#放入sym栈
    while((ch=getchar())!='\n'){
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='#')
        {
            while(!Judeg_SstackEmpty(sym)){
            if(Let_oprValue(ch)>Let_oprValue(Get_top(sym)))
            {
                Push_Sstack(sym,ch);
                break;
            }//如果当前字符ch优先级高于栈顶字符，则直接将当前字符ch放入sym栈中
            else
            {
                if(ch=='+'||ch=='-'||ch=='*'||ch=='/')//此时如果ch是运算符则简单执行一步运算
                {
                    xch=Pop_Sstack(sym);
                    b=Pop_Sstack_int(num);
                    a=Pop_Sstack_int(num);
                    Push_Sstack_int(num,Get_result(xch,a,b));
                }
                else if(ch=='#')//此时所有运算符已经进入过sym运算符栈中
                {
                    while(Get_top(sym)!='#'){
                        xch=Pop_Sstack(sym);
                        b=Pop_Sstack_int(num);
                        a=Pop_Sstack_int(num);
                        Push_Sstack_int(num,Get_result(xch,a,b));
                    }
                    Pop_Sstack(sym);//把#号出栈
                }
            }//如果当前字符ch优先级等于或低于栈顶字符
            }
        }//如果是运算符则进行判断
        else{
            Push_Sstack_int(num,(int)(ch-'0'));
        }//如果是操作数则直接入num栈
    }//当表达式输入完全之后退出操作
    cout <<Get_top_int(num)<<endl;
}