#include<stdio.h>
#include<stdlib.h>

typedef struct  ElemType
{
    char a[30];
    struct ElemType *next;
}ElemType;

typedef struct SqStack                //�������ṹ�����ķ�ʽ
{
       ElemType	*elem;
       int			top;      //����ջ��ָ��
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
    if(!n)      {printf("��ջ�ǿ�ջ��\n"); }
    else        printf("��ջ��Ϊ�գ�\n");
}
