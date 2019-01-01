#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int test, cases = 1, a, b, result, Size, i;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &Size);

        result = 0;
        for(i=0; i<Size; i++){
            scanf("%d %d", &a, &b);
            result = result^(b-a-1);
        }

        if(result)
            printf("Case %d: Alice\n", cases++);
        else
            printf("Case %d: Bob\n", cases++);
    }

    return 0;
}
