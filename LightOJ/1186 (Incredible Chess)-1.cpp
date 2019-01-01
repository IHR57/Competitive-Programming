#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int test, black[210], white[210], cases=1, n, value;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d", &white[i]);
        }

        for(int i=0; i<n; i++){
            scanf("%d", &black[i]);
        }

        int result = 0;
        for(int i=0; i<n; i++){
            value = (black[i]-white[i]-1);
            //printf("%d\n", value);
            result = result^value;
        }

        if(result)
            printf("Case %d: white wins\n", cases++);
        else
            printf("Case %d: black wins\n", cases++);
    }

    return 0;
}
