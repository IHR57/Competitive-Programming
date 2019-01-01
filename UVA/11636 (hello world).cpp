#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

bool check_sqrt(int n)
{
    for(int i=1; i<=n/2; i++){
        if(n==pow(2, i))
            return true;
    }
    return false;
}
int main()
{
    int n, i=1, number, count, check;

    while(scanf("%d", &n)==1){
        count=0;
        check=0;
        if(n<0){
            break;
        }
        else if(n==1){
            count=0;
            printf("Case %d: %d\n", i++, count);
            continue;
        }
        if(check_sqrt(n)==true)
            count=count-1;
        while(n!=0){
            n=n/2;
            count++;
        }
        printf("Case %d: %d\n", i++, count);

    }

    return 0;
}
