#include <stdio.h>

int main()
{
    int n, k, sum, m;

    while(scanf("%d %d", &n, &k)==2){
        sum=n;
        while(n>=k){
            if(n%k==0)
                m=0;
            else
                m=n%k;
            n=n/k;
            sum=sum+n;
            n=m+n;
        }
        printf("%d\n", sum);
    }

    return 0;
}
