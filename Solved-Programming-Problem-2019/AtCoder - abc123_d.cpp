//Problem ID: AtCoder - abc123_d (Cake 123)
//Programmer: IQBAL HOSSAIN     Description: Greedy/Sorting
//Date: 13/05/19
//Problem Link: https://atcoder.jp/contests/abc123/tasks/abc123_d
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

vector<ll> a, b, c, res;

int main()
{
    int x, y, z, m;

    scanf("%d %d %d %d",  &x, &y, &z, &m);
    ll val;
    for(int i = 0; i < x; i++){
        scanf("%lld", &val);
        a.push_back(val);
    }
    for(int i = 0; i < y; i++){
        scanf("%lld", &val);
        b.push_back(val);
    }
    for(int i = 0; i < z; i++){
        scanf("%lld", &val);
        c.push_back(val);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int k = 0; k < z; k++){
                if((i + 1) * (j + 1) * (k + 1) <= m)
                    res.push_back(a[i] + b[j] + c[k]);
                else
                    break;
            }
        }
    }

    sort(res.rbegin(), res.rend());

    for(int i = 0; i < m; i++){
        printf("%lld\n", res[i]);
    }

    return 0;
}
