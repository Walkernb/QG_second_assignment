#include<stdio.h>
#include<stdlib.h>

typedef struct  ElemType
{
    char a[30];
    struct ElemType *next;
}ElemType;

typedef struct SqStack                //简化声明结构体对象的方式
{
       ElemType	*elem;
       int			top;      //用于栈顶指针
       int			size;
}SqStack;

int isEmptyStack(SqStack *s)
{
    if(s->top==-1) return 0;
    return 1;
}
extern int isEmptyStack(SqStack *s);

void IsEmpty_Stack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("该栈是空栈！\n"); }
    else        printf("该栈不为空！\n");
}
