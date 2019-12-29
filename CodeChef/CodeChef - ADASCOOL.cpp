#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int test, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n,  &m);
        if((n * m) % 2 == 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
