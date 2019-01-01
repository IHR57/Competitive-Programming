#include <stdio.h>

int main()
{
    long int n, sum;
    int i;

    printf("PERFECTION OUTPUT\n");

    while(scanf("%ld", &n)==1){
        sum=0;
        if(n==0)
            break;
        for(i=1; i<=n/2; i++){
            if(n%i==0){
                sum+=i;
            }
        }
        if(sum==n){
            printf("%5ld  PERFECT\n", n);
        }
        else if(sum>n)
            printf("%5ld  ABUNDANT\n", n);
        else
            printf("%5ld  DEFICIENT\n", n);
    }
    printf("END OF OUTPUT\n");
}
