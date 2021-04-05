#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    if(!n)    {printf("该栈是空栈！\n"); return ;}
    printf("栈顶元素：%s\n",s->elem->a);
}

void clearStack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("该栈是空栈！\n"); return ;}
    s->top=-1;
    s->elem=NULL;
    printf("清空完毕！\n");
}

void destroyStack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("该栈是空栈！\n"); return ;}
    ElemType *p=s->elem,*q;
    q=p;
    s->top=-1;
    while(q!=NULL)
    {
        p=p->next;
        free(q);
        q=p;
    }
    printf("销毁完毕！\n");
}

void  stackLength(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("该栈是空栈！\n"); return ;}
    printf("该栈的长度是：%d\n",s->top+1);
}

SqStack *pushStack(SqStack *s)
{
    if(s->size-1<=s->top)   {printf("该栈已满！\n");return s; }
    ElemType *e=(ElemType *)malloc(sizeof(ElemType));
    printf("请输入新元素的数据：");
    scanf("%s",e->a);
    e->next=s->elem;
    s->elem=e;
    s->top++;
    printf("添加成功！\n");
    return s;
}
SqStack *popStack(SqStack *s)
{
    int n=isEmptyStack(s);
    if(!n)      {printf("该栈是空栈！\n"); return s;}
    printf("元素 %s 已出栈！\n",s->elem->a);
    ElemType *e=s->elem;
    s->elem=e->next;
    s->top--;
    free(e);
    return s;
}
int Input()
{
    printf("初始化栈，输入栈的长度：");
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
     if(n==0)   {printf("初始化栈有误！\n");return 0;}
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
             default:printf("输入有误！\n");
         }
     }
     getchar();
     getchar();
     return 0;
 }
