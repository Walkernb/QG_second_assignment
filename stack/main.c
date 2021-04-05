#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

SqStack *initStack(SqStack *s,int size)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->elem=NULL;
    s->size=size;
    s->top=-1;
    return s;
}

void getTopStack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)    {printf("��ջ�ǿ�ջ��\n"); return ;}
    printf("ջ��Ԫ�أ�%s\n",s->elem->a);
}

void clearStack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("��ջ�ǿ�ջ��\n"); return ;}
    s->top=-1;
    s->elem=NULL;
    printf("�����ϣ�\n");
}

void destroyStack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("��ջ�ǿ�ջ��\n"); return ;}
    ElemType *p=s->elem,*q;
    q=p;
    s->top=-1;
    while(q!=NULL)
    {
        p=p->next;
        free(q);
        q=p;
    }
    printf("������ϣ�\n");
}

void  stackLength(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("��ջ�ǿ�ջ��\n"); return ;}
    printf("��ջ�ĳ����ǣ�%d\n",s->top+1);
}

SqStack *pushStack(SqStack *s)
{
    if(s->size-1<=s->top)   {printf("��ջ������\n");return s; }
    ElemType *e=(ElemType *)malloc(sizeof(ElemType));
    printf("��������Ԫ�ص����ݣ�");
    scanf("%s",e->a);
    e->next=s->elem;
    s->elem=e;
    s->top++;
    printf("��ӳɹ���\n");
    return s;
}
SqStack *popStack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("��ջ�ǿ�ջ��\n"); return s;}
    printf("Ԫ�� %s �ѳ�ջ��\n",s->elem->a);
    ElemType *e=s->elem;
    s->elem=e->next;
    s->top--;
    free(e);
    return s;
}
int Input()
{
    printf("��ʼ��ջ������ջ�ĳ��ȣ�");
    char c[30];
    int n=0,t=1;
    scanf("%s",c);
    for(int i=strlen(c)-1;i>=0;i--)
    {
        if(c[i]-'0'>9)    return 0;
        n+=(c[i]-'0')*t;
        t*=10;
    }
    return n;
}

extern void IsEmpty_Stack(SqStack *s);
extern int isEmptyStack(SqStack *s);
extern void interface();
 int main()
 {
     char c[30];
     SqStack *s;
     int n,p=1,i;
     n=Input();
     //printf("%d\n",n);
     if(n==0)   {printf("��ʼ��ջ����\n");return 0;}
     s=initStack(s,n);
     while(p)
     {
         interface();
         scanf("%s",c);
         if(strlen(c)>1)    i=100;
         else               i=c[0]-'0';
         switch(i)
         {
             case 1:IsEmpty_Stack(s);break;
             case 2:getTopStack(s);break;
             case 3:clearStack(s);break;
             case 4:destroyStack(s);break;
             case 5:stackLength(s);break;
             case 6:s=pushStack(s);break;
             case 7:s=popStack(s);break;
             case 0:p=0;break;
             default:printf("��������\n");
         }
     }
     getchar();
     getchar();
     return 0;
 }
