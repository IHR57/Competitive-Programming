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
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int val, n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>val;
        cs[i] = cs[i-1] + val;
    }

    int l = 1, r = 3;
    ll ans = 1e16;
    ll d[4];
    for(int i = 2; i <= n - 2; i++){
        while(l < i && abs(cs[l] - (cs[i] - cs[l])) >= abs(cs[l+1] - (cs[i] - cs[l+1]))){
            l++;
        }
        while(r < n && abs(cs[r] - cs[i] - (cs[n] - cs[r])) >= abs(cs[r+1] - cs[i] - (cs[n] - cs[r+1]))){
            r++;
        }
        d[0] = cs[l], d[1] = cs[i] - cs[l], d[2] = cs[r] - cs[i], d[3] = cs[n] - cs[r];
        //cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
        sort(d, d + 4);
        ans = min(ans, d[3] - d[0]); 
    }

    cout<<ans<<endl;

    return 0;
}
