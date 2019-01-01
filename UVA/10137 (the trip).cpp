#include <stdio.h>

int main()
{
    double money[1001], average, substract, sum, sumpositive, sumnegative, add;
    int n, i;


    while(scanf("%d", &n)==1){
        if(n==0)
            break;
        sum=0;
        sumpositive=0;
        sumnegative=0;
        for(i=0; i<n; i++){
            scanf("%lf", &money[i]);
        }
        for(i=0; i<n; i++){
            sum=sum+money[i];
        }
        average=sum/n;

        for(i=0; i<n; i++){
            add=(long)((money[i]-average)*100.0)/100.0;
            if(add>0)
                sumpositive+=add;
            else
                sumnegative-=add;
        }
       printf("$%.2f\n", sumpositive>sumnegative?sumpositive:sumnegative);
    }

    return 0;
}
