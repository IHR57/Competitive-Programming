//Problem ID: UVA 369 (combinations)
#include <stdio.h>
#define MAXTRI 110

unsigned long int pas[MAXTRI][MAXTRI];

void pascals(int n)
{
    register int i, j;

    pas[0][0]=1;
    pas[1][0]=pas[1][1]=1;

    for(i=2; i<=n; i++){
        pas[i][0]=1;
        for(j=1; j<i; j++){
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
        }
        pas[i][j]=1;
    }
}

int main()
{
    pascals(100);
    int n, m;

    while(scanf("%d %d", &n, &m)==2){
        if(n==0 && m==0)
            break;
        printf("%d things taken %d at a time is %lu exactly.\n", n, m, pas[n][m]);
    }

    return 0;
}
