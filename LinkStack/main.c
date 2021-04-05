#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef  struct StackNode
{
	char  a[30];
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;
extern int isEmptyLStack(LinkStack *s);
extern void IsEmptyLStack(LinkStack *s);
extern void interface();

LinkStack *initLStack(LinkStack *s)
{
    s=(LinkStack *)malloc(sizeof(LinkStack));
    s->top=NULL;
    s->count=0;
    printf("栈已初始化！\n");
    return s;
}
void  getTopLStack(LinkStack *s)
{
    int i=isEmptyLStack(s);
    if(!i)  {printf("空栈！\n");   return ;}
    printf("栈顶是：%s\n",s->top->a);
}
void clearLStack(LinkStack *s)
{
    int i=isEmptyLStack(s);
    if(!i)  {printf("空栈！\n");   return ;}
    s->top=NULL;
    s->count=0;
    printf("已清空栈！\n");
}
void destroyLStack(LinkStack *s)
{
    int i=isEmptyLStack(s);
    if(!i)  {printf("空栈！\n");   return ;}
    s->count=0;
    LinkStackPtr p=s->top,*q;
    q=p;
    while(q!=NULL)
    {
        p=p->next;
        free(q);
        q=p;
    }
    s->top=NULL;
    printf("已销毁栈！\n");
}
void LStackLength(LinkStack *s)
{
    int i=isEmptyLStack(s);
    if(!i)  {printf("空栈！\n");   return ;}
    printf("该栈的长度为：%d\n",s->count);
}
LinkStack *pushLStack(LinkStack *s)
{
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
    printf("请输入新元素的数据：");
    scanf("%s",p->a);
    p->next=s->top;
    s->top=p;
    s->count++;
    printf("已添加新元素！\n");
    return s;
}
LinkStack *popLStack(LinkStack *s)
{
    int i=isEmptyLStack(s);
    if(!i)  {printf("空栈！\n");   return ;}
    printf("元素 %s 已出栈！\n",s->top->a);
    LinkStackPtr p=s->top;
    s->top=p->next;
    s->count--;
    free(p);
    return s;
}

int main()
{
    LinkStack *s;
    s=initLStack(s);
    int p=1,i;
    char c[30];
    while(p)
    {
        interface();
        scanf("%s",c);
        if(strlen(c)>1) i=100;
        else    i=c[0]-'0';
        switch(i)
        {
            case 1:IsEmptyLStack(s);break;
            case 2:getTopLStack(s);break;
            case 3:clearLStack(s);break;
            case 4:destroyLStack(s);break;
            case 5:LStackLength(s);break;
            case 6:s=pushLStack(s);break;
            case 7:s=popLStack(s);break;
            case 0:p=0;break;
            default:printf("输入错误！\n");
        }
    }
    getchar();
    getchar();
    return 0;
}
