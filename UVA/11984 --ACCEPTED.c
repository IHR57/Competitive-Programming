#include <stdio.h>

int main()
{
    int i=1, T, C, d;
    float total, celsius;

    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &C, &d);
        celsius=(float)(5*d)/9;
        total=C+celsius;
        printf("Case %d: %0.2f\n", i, total);
        i++;
    }
    return 0;
}
