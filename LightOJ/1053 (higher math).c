#include <stdio.h>

typedef long long int lint;

int main()
{
    int test, j=1;
    lint a, b, c;

    scanf("%d", &test);
    while(test--){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a*a==b*b+c*c || b*b==c*c+a*a || c*c==a*a+b*b){   //condition for forming a triangle
            printf("Case %d: yes\n", j++);
        }
        else
            printf("Case %d: no\n", j++);
    }

    return 0;
}
