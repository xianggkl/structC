#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct ClassLink
{
    long student_id;
    int class_id;
    int score;
    struct ClassLink *next;
}ClassLink;
void Init_ClassLink(ClassLink **s)
{
    *s=(ClassLink *)malloc(sizeof(ClassLink));
    (*s)->student_id=0;
    (*s)->class_id=0;
    (*s)->score=0;
    (*s)->next=NULL;
}//初始化空表
void Insert_decrease_class_link(ClassLink **s1, ClassLink **s2)
{
    int i=0,n=0,w=0,e=0,k=0,claId,sco;
    long stuId;
    ClassLink *p,*q,*temp1,*temp2,*font,*temp;
    Init_ClassLink(&p);Init_ClassLink(&q);Init_ClassLink(&temp1);Init_ClassLink(&temp2);Init_ClassLink(&font);Init_ClassLink(&temp);
    p=*s1;q=*s2;
    printf("please input the number of the students:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Please input classid,studentid,score:\n");
        scanf("%d,%ld,%d",&claId,&stuId,&sco);
        if(claId==1)
        {
            w++;
            if(w==1)
            {
                p->student_id=stuId;
                p->class_id=claId;
                p->score=sco;
            }
            else{
                p=*s1;
                while(p->student_id!=0&&p->score>sco){
                    k++;
                    font=p;
                    p=p->next;
                    if(p==NULL)
                    {
                        Init_ClassLink(&p);
                    }
                }
                temp1->student_id=stuId;
                temp1->class_id=claId;
                temp1->score=sco;
                temp1->next=p;
                if(k==0)
                {
                    *s1=temp1;
                }
                else{
                    font->next=temp1;
                }
                temp1=temp;
                temp=temp->next;
                Init_ClassLink(&temp);
                k=0;
            }
        }
        else{
           e++;
            if(e==1)
            {
                q->student_id=stuId;
                q->class_id=claId;
                q->score=sco;
            }
            else{
                q=*s2;
                while(q->student_id!=0&&q->score>sco){
                    k++;
                    font=q;
                    q=q->next;
                    if(q==NULL)
                    {
                        Init_ClassLink(&q);
                    }
                }
                temp2->student_id=stuId;
                temp2->class_id=claId;
                temp2->score=sco;
                temp2->next=q;
                if(k==0)
                {
                    *s2=temp2;
                }
                else{
                    font->next=temp2;
                }
                temp2=temp;
                temp=temp->next;
                Init_ClassLink(&temp);
                k=0;
            }
        }
    }
}//降序录入学生数据
void Find_stuID_Delete(ClassLink **s,int stuId)
{
    int i=0,m=0,FIND=0;
    ClassLink *font,*now;
    Init_ClassLink(&font);Init_ClassLink(&now);
    now=*s;
    while(now!=NULL)
    {
        if(stuId!=now->student_id)
        {
            m++;
            font=now;
            now=now->next;
        }
        else{
            if(m==0)
            {
                *s=now->next;
            }
            else{
                font->next=now->next;
            }
            free(now);
            FIND=1;
            now=NULL;
        }//若找到了则删除
    }
    //如果没有此学号学生，则输出无法找到
    if(FIND==0)
    {
        printf("CANNOT FIND!");
    }
}//找到某学号学生,并删除
void Print_ClassLink(ClassLink *s)
{
    int i,j;
    for(i=0;s!=NULL;i++)
    {
        printf("ClassId:%d.StudentId:%ld.Score:%d.\n",s->class_id,s->student_id,s->score);
        s=s->next;
    }
}//遍历线性链表，输出信息

int main ()
{
    ClassLink *s1,*s2;
    Init_ClassLink(&s1);
    Init_ClassLink(&s2);
    Insert_decrease_class_link(&s1,&s2);
    Print_ClassLink(s1);
    Find_stuID_Delete(&s1,2);
    Print_ClassLink(s1);
}