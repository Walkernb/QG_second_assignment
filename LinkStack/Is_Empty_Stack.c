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

int isEmptyLStack(LinkStack *s)
{
    if(s->count==0)  return 0;
    return 1;
}
void IsEmptyLStack(LinkStack *s)
{
    int i=isEmptyLStack(s);
    if(!i)  printf("ø’’ª£°\n");
    else    printf("∑«ø’’ª£°\n");
}
