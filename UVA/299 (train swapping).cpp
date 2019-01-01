#include <stdio.h>

int main()
{
    int test, length[1000], exchange, i, j, n, temp;

    scanf("%d", &test);

    while(test--){
        exchange=0;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &length[i]);
        }

        for(i=0; i<n; i++){
            for(j=0; j<n-1;  j++){
                if(length[j]>length[j+1]){
                    temp=length[j];
                    length[j]=length[j+1];
                    length[j+1]=temp;
                    exchange+=1;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", exchange);
    }

    return 0;
}
