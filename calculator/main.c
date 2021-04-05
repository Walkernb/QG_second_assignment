/*
*简版四则运算器
*只能处理：1+2+5；1*2+4；12+（34+4）......类似的简单运算
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct stack1
{
    int n[100];
    int count;
}stack1;

typedef struct stack2
{
    char c[100];
    int count;
}stack2;

int compare(char a,char b)          //比较运算符的优先级
{
    int n,m;
    if(a=='-'||a=='+')  n=1;
    else                n=2;
    if(b=='-'||b=='+')  m=1;
    else                m=2;
    return      n>m?1:0;
}
void  separate_num(char a[150],char b[150],stack2 *st2) //中缀表达式转化为后缀表达式
{
    int i,k=0,j=0;
    int t=0;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')    b[k]=a[i], k++;
        else
            if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
            {
                 b[k]=' ',   k++;
                 int j=st2->count;
                 if(t==1)    st2->count++,   st2->c[st2->count]=a[i];           //括号内的运算符入栈
                 if(st2->count==-1)     st2->count++, st2->c[st2->count]=a[i];
                 else
                 if(compare(a[i],st2->c[j])&&t!=1)                            //比较运算符的优先级
                        st2->count++,   st2->c[st2->count]=a[i];            //入栈
                 else
                 {
                     while(j!=-1&&t!=1)                                    //栈顶运算符的优先级大于或等于目前运算符
                     {
                         if(compare(a[i],st2->c[j]))
                            {j++,    st2->c[j]=a[i], st2->count=j;  break;}
                         else
                            b[k]=st2->c[j], k++,b[k]=' ', k++, j--;
                     }
                     if(j==-1)
                     {
                         j++;
                         st2->count=j;
                         st2->c[j]=a[i];
                     }
                 }

            }
            else                        //处理括号
            {
                if((a[i]=='('))
                    t=1, st2->count++,  st2->c[st2->count]=a[i];
                else    if(a[i]==')')
                {
                    int p=st2->count;
                    while(st2->c[p]!='(')
                           b[k]=' ', k++,  b[k]=st2->c[p], k++, p--;
                    st2->count=p-1;
                    t=0;
                }
            }
    }
    i=st2->count;
    while(i!=-1)                //将栈里全部运算符出栈
       b[k]=' ', k++,  b[k]=st2->c[i],i--,k++;
}

int Counter(stack1 *st1,char b[150])        //计算结果
{
    int t=0,i;
    int sum=0;
    for(i=0;i<strlen(b);i++)
    {
        if(b[i]>='0'&&b[i]<='9')
            t=t*10+b[i]-'0';
        else
            if(b[i]==' ')
            {
                if(t!=0)
                    {st1->count++;
                    st1->n[st1->count]=t;
                    t=0;}
            }
            else
            {
                int current=st1->n[st1->count]; st1->count--;
                int front=st1->n[st1->count];
                switch(b[i])
                {
                    case '+':st1->n[st1->count]=front+current;break;
                    case '-':st1->n[st1->count]=front-current;break;
                    case '*':st1->n[st1->count]=front*current;break;
                    case '/':st1->n[st1->count]=front/current;break;
                }
            }
    }
    i=st1->count;
    return st1->n[st1->count];
}
extern int judge_input(char a[150]);    //处理不合规范的表达式
extern int judge_output(int  n);        //处理计算结果溢出
extern void Explain();
int main()
{
    stack1 *st1=(stack1 *)malloc(sizeof(stack1));
    st1->count=-1;
    stack2 *st2=(stack2 *)malloc(sizeof(stack2));
    st2->count=-1;
    char a[150],b[150];
    memset(b,'\0',sizeof(b));
    Explain();
    printf("\n输入表达式：");
    gets(a);
    if(!judge_input(a))     {getchar(); getchar();  return 0;}
    separate_num(a,b,st2);
    int n=Counter(st1,b);
    if(!judge_output(n))    printf("计算结果超出范围！\n");
    else    printf("计算结果：%d\n",n);
    getchar();
    getchar();
    return 0;
}
