#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll factorial[40];

int main()
{
    factorial[0] = 1;
    for(int i = 1; i <= 19; i++){
        factorial[i] = i * factorial[i-1];
    }

    int test, caseNo = 1;
    ll n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll temp = n;
        vector<int> v;

        for(int i = 19; i >= 0; i--){
            if(factorial[i] <= temp){
                temp -= factorial[i];
                if(temp < 0)
                    break;
                else
                    v.push_back(i);
            }
        }

        if(temp != 0)
            printf("Case %d: impossible\n", caseNo++);
        else{
            printf("Case %d: ", caseNo++);
            for(int i = v.size() - 1; i > 0; i--){
                printf("%d!+", v[i]);
            }
            printf("%d!\n", v[0]);
        }
        v.clear();
    }

    return 0;
}
