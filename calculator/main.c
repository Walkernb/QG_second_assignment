/*
*�������������
*ֻ�ܴ���1+2+5��1*2+4��12+��34+4��......���Ƶļ�����
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

int compare(char a,char b)          //�Ƚ�����������ȼ�
{
    int n,m;
    if(a=='-'||a=='+')  n=1;
    else                n=2;
    if(b=='-'||b=='+')  m=1;
    else                m=2;
    return      n>m?1:0;
}
void  separate_num(char a[150],char b[150],stack2 *st2) //��׺���ʽת��Ϊ��׺���ʽ
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
                 if(t==1)    st2->count++,   st2->c[st2->count]=a[i];           //�����ڵ��������ջ
                 if(st2->count==-1)     st2->count++, st2->c[st2->count]=a[i];
                 else
                 if(compare(a[i],st2->c[j])&&t!=1)                            //�Ƚ�����������ȼ�
                        st2->count++,   st2->c[st2->count]=a[i];            //��ջ
                 else
                 {
                     while(j!=-1&&t!=1)                                    //ջ������������ȼ����ڻ����Ŀǰ�����
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
            else                        //��������
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
    while(i!=-1)                //��ջ��ȫ���������ջ
       b[k]=' ', k++,  b[k]=st2->c[i],i--,k++;
}

int Counter(stack1 *st1,char b[150])        //������
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
extern int judge_input(char a[150]);    //�����Ϲ淶�ı��ʽ
extern int judge_output(int  n);        //������������
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
    printf("\n������ʽ��");
    gets(a);
    if(!judge_input(a))     {getchar(); getchar();  return 0;}
    separate_num(a,b,st2);
    int n=Counter(st1,b);
    if(!judge_output(n))    printf("������������Χ��\n");
    else    printf("��������%d\n",n);
    getchar();
    getchar();
    return 0;
}
