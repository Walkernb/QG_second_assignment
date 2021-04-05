/*
*错误处理:
*1,处理不合规范的表达式,例如：-12+4；-12+asd34；以及出现其它字符（如：空格）
*2，处理输入数据溢出
*3，处理运算结果溢出
*/
#include<stdio.h>
#include<string.h>

int judge_input(char a[150])        //处理不合规范的表达式
{
    int i,sum=0,term=0;
    if(a[0]>'9'||a[0]<'0')      {printf("输入有误！\n"); return 0; } //处理带有运算符开头的表达式
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')    term++;
        else
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            sum++;
            if(a[i+1]=='+'||a[i+1]=='-'||a[i+1]=='*'||a[i+1]=='/')  {printf("输入有误！\n"); return 0; }
            if(term>=9)  {printf("输入有误！\n"); return 0; }    //处理输入数据溢出
            else        sum+=term;
            term=0;
        }
        else    if((a[i]=='(')||(a[i]==')'))
        {
            sum++;
            if((a[i+1]=='(')||(a[i+1]==')'))  {printf("输入有误！\n"); return 0; }
            if(term>=9)  {printf("输入有误！\n"); return 0; }    //处理输入数据溢出
            else        sum+=term;
            term=0;
        }
    }
    if(term)    sum+=term;
    i=strlen(a)-1;
    if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')  {printf("输入有误！\n"); return 0; }
    //printf("%d\n%d\n",sum,strlen(a));
    if(sum<strlen(a))   {printf("输入有误！\n"); return 0; } //处理出现了其它不合法字符的表达式
    return 1;
}

int judge_output(int  n)           //处理计算结果溢出
{
    int i=0;
    while(n!=0)
        i++, n/=10;
    if(i>=9)    return 0;
    return 1;
}
