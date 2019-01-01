/*Problem ID: 12157*/
#include <stdio.h>

int main()
{
    int test, duration, mile, juice, p_mile, p_juice, i, n, sum_m, sum_j, k=1;

    scanf("%d", &test);

    while(test--){
        sum_m=0;
        sum_j=0;
        scanf("%d", &n);
        for(i=1; i<=n; i++){
            scanf("%d", &duration);
            mile=(duration/30)+1;
            juice=(duration/60)+1;
            p_mile=mile*10;
            p_juice=juice*15;
            sum_m+=p_mile;  /*storing total cost for mile*/
            sum_j+=p_juice; /*storing total cost for juice*/
        }

        if(sum_m<sum_j){
            printf("Case %d: Mile %d\n", k, sum_m);
        }
        else if(sum_m>sum_j)
            printf("Case %d: Juice %d\n", k, sum_j);
        else if(sum_m==sum_j)
            printf("Case %d: Mile Juice %d\n", k, sum_m);
        k++;
    }

    return 0;
}
