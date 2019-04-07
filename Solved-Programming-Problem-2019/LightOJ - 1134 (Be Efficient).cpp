//Problem ID: LightOJ - 1134 (Be Efficient)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 05/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int counter[MAX], cs[MAX];

int main()
{
    int test, caseno = 1, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        int val;
        cs[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &val);
            cs[i] = (val + cs[i-1]) % m;
        }
        memset(counter, 0, sizeof(counter));
        counter[0] = 1;

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ans += (ll) counter[cs[i]];
            counter[cs[i]]++;
        }

        printf("Case %d: %lld\n", caseno++, ans);
    }

    return 0;
}
