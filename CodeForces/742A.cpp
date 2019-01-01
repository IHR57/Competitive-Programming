//Problem ID: CodeForces Round: 383 Div: 2 (Arpa's hard exam and Mehrdad's naive cheat
//Programmer: IQBAL HOSSAIN
//Date: 06-12-16
#include <iostream>
#include <cstdio>
using namespace std;

typedef long int lint;

int main()
{
    lint n;

    scanf("%ld", &n);

    if(n==0)
        printf("1\n");
    else if(n%4==1)
        printf("8\n");
    else if(n%4==2)
        printf("4\n");
    else if(n%4==3)
        printf("2\n");
    else if(n%4==0)
        printf("6\n");

    return 0;
}
