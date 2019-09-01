//Problem ID: CodeForces - 1178B (WOW Factor)
//Programmer: IQBAL HOSSAIN     Description: DP
//Date: 23/08/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 1000005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cnt[MAX], cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    string str;

    cin>>str;

    int n = str.size();
    for(int i = 1; i < n; i++){
        if(str[i] == 'v' && str[i-1] == 'v'){
            cnt[i] = cnt[i-1] + 1;
            cnt[i-1] = 0;
        }
        else
            cnt[i] = 0;
    }

    for(int i = 1; i < n; i++){
        cs[i] = cs[i-1] + cnt[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(str[i] == 'o'){
            ans += 1LL * (ll) (cs[i-1] - cs[0]) * (ll) (cs[n-1] - cs[i]);
        }
    }

    cout<<ans<<endl;

    return 0;
}
