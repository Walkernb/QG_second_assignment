/*
*������:
*1,�����Ϲ淶�ı��ʽ,���磺-12+4��-12+asd34���Լ����������ַ����磺�ո�
*2�����������������
*3���������������
*/
#include<stdio.h>
#include<string.h>

int judge_input(char a[150])        //�����Ϲ淶�ı��ʽ
{
    int i,sum=0,term=0;
    if(a[0]>'9'||a[0]<'0')      {printf("��������\n"); return 0; } //��������������ͷ�ı��ʽ
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')    term++;
        else
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            sum++;
            if(a[i+1]=='+'||a[i+1]=='-'||a[i+1]=='*'||a[i+1]=='/')  {printf("��������\n"); return 0; }
            if(term>=9)  {printf("��������\n"); return 0; }    //���������������
            else        sum+=term;
            term=0;
        }
        else    if((a[i]=='(')||(a[i]==')'))
        {
            sum++;
            if((a[i+1]=='(')||(a[i+1]==')'))  {printf("��������\n"); return 0; }
            if(term>=9)  {printf("��������\n"); return 0; }    //���������������
            else        sum+=term;
            term=0;
        }
    }
    if(term)    sum+=term;
    i=strlen(a)-1;
    if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')  {printf("��������\n"); return 0; }
    //printf("%d\n%d\n",sum,strlen(a));
    if(sum<strlen(a))   {printf("��������\n"); return 0; } //����������������Ϸ��ַ��ı��ʽ
    return 1;
}

int judge_output(int  n)           //������������
{
    int i=0;
    while(n!=0)
        i++, n/=10;
    if(i>=9)    return 0;
    return 1;
}
