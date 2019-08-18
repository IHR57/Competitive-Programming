/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 998244353
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, arr[MAX], tt[MAX];
int cnt[MAX], counter[MAX], cs[MAX];
ll p[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        int k = 0, temp = arr[i];
        while(temp){
            int r = temp % 10;
            temp /= 10;
            k++;
            counter[k] += 1;
            cs[k] += r;
        }
        cnt[k]++;
        tt[i] = arr[i];
    }

    p[0] = 1;
    for(int i = 1; i < 20; i++)
        p[i] = (p[i-1] * 10) % MOD;

    ll ans = 0;
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] == 0)
                continue;
            int t = arr[j] % 10;
            arr[j] /= 10;
            ans += ((((counter[i] - 1) * p[i + i - 1] * t) % MOD + ((cs[i] - t) * p[i+i-2]) % MOD)) % MOD;
            //cout<<((((counter[i] - 1) * p[i + i - 1] * t) % MOD + ((cs[i] - t) * p[i+i-2]) % MOD)) % MOD<<endl;
            for(int k = i - 1; k >= 0; k--){
                ans += (((cnt[k] * p[i+k-1]) % MOD * 2) % MOD * t) % MOD;
                //cout<<(cnt[k] * p[i+k-1] * 2 * t)<<endl;
            }
        }
    }

    for(int i = 0; i < n; i++){
        int k = 0;
        ll res = 0;
        while(tt[i]){
            res += (tt[i] % 10 * p[k]);
            k++;
            res += (tt[i] % 10 * p[k]);
            k++;
            tt[i] /= 10;
        }
        ans = (ans + res) % MOD;
    }
    cout<<ans % MOD<<endl;

    return 0;
}
