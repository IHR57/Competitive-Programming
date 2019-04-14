//Problem ID: CodeForces - 1062C (Banh-mi)
//Programmer: IQBAL HOSSAIN     Description: Greedy/MATH
//Date: 14/04/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;
int one[MAX], zero[MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    string st, str;

    cin>>n>>q;
    cin>>st;
    str = "$" + st;

    for(int i = 1; i <= n; i++){
        if(str[i] == '1'){
            one[i] = one[i-1]+1;
            zero[i] = zero[i-1];
        }
        else{
            one[i] = one[i-1];
            zero[i] = zero[i-1] + 1;
        }
    }

    int l, r;
    for(int i = 0; i < q; i++){
        cin>>l>>r;
        ll tmp1 = 1LL * (zero[r] - zero[l-1]);
        ll tmp2 = 1LL * (one[r] - one[l-1]);
        ll ans = bigMod(2, tmp2) - 1;
        if(ans < 0)
            ans += MOD;
        ll a = ans;
        ans = (ans + (ans * bigMod(2, tmp1)) % MOD) % MOD;
        ans -= a;
        if(ans < 0){
            ans += MOD;
        }

        cout<<ans<<endl;
    }
}
