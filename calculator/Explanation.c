#include<stdio.h>

void Explain()
{
    int i;
    for(i=0;i<35;i++)   printf(" ");
    for(i=0;i<44;i++)   printf("*");    printf("\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    for(i=0;i<12;i++)   printf(" ");
    printf("简版四则运算器说明");
    for(i=0;i<12;i++)   printf(" ");    printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("1, 运算器只能进行类似:2+4, 2+(2*5) 等运算 *\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("2, 计算的数据范围是8位及8位以内");
    for(i=0;i<11;i++)   printf(" ");    printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("3, 表达式中不允许出现非法字符");
    for(i=0;i<13;i++)   printf(" ");    printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("   若不按以上说明操作，则无法使用计算器");
    for(i=0;i<3;i++)    printf(" ");    printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    for(i=0;i<44;i++)   printf("*");    printf("\n");
}
