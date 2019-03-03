#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int counter[MAX];
typedef long long ll;

int main()
{
    int test, caseno = 1, n, value;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        memset(counter, 0, sizeof(counter));
        for(int i = 0; i < n; i++){
            scanf("%d", &value);
            counter[value]++;
        }

        ll result = 0;
        for(int i = 0; i < MAX; i++){
            if(counter[i] != 0){
                int temp = counter[i] / (i + 1);
                if(counter[i] % (i + 1) == 0){
                    result += (ll) (temp * (i + 1));
                }
                else{
                    temp++;
                    result += (ll) (temp * (i + 1));
                }
            }
        }

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
