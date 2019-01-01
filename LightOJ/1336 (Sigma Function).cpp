#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100000005
using namespace std;

typedef long long lint;

int main()
{
    lint n;
    int test, cases = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);

        /*lint p1 = (int)log2((double)n);
        lint sq = (int)sqrt((double)n);
        lint sq2 = (int)sqrt((double)(n/2));
        lint p2 = (int)log2((double)sq);
        //cout<<p1<<" "<<sq<<" "<<sq2<<" "<<p2<<endl;*/

        lint result = n - (int)sqrt(n) - (int)sqrt(n/2);

        printf("Case %d: %lld\n", cases++, result);
    }

    return 0;
}
