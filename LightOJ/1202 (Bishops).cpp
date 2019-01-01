#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>

int main()
{
    int test, cases = 1, r1, c1, r2, c2;
    int moveNeed;       //number of move need to take one another

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        int diff1 = abs(r1 - r2);
        int diff2 = abs(c1 - c2);

        if(diff1 == diff2)
            printf("Case %d: %d\n", cases++, 1);
        else if((diff1 % 2 == 0 && diff2 % 2 == 0) || (diff1 % 2 != 0 && diff2 % 2 != 0))
        {
            printf("Case %d: %d\n", cases++, 2);
        }
        else
            printf("Case %d: impossible\n", cases++);
    }

    return 0;
}
