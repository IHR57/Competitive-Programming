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
#define MAX 400005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> v, vs;
set<int> s;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, I, val;

    cin>>n>>I;
    I = I * 8;

    for(int i = 0; i < n; i++){
        cin>>val;
        s.insert(val);
        v.pb(val);
    }

    sort(v.begin(), v.end());

    int k = (int) log2((int)s.size());
    int p = s.size();
    if((p & (p - 1)) != 0)
        k++;

    if(k * n <= I){
        cout<<0<<endl;
        return 0;
    }
    while(k * n > I){
        k--;
    }

    for(set<int> :: iterator it = s.begin(); it != s.end(); it++){
        vs.pb(*it);
    }

    int ans = 1e8;
    k = (1 << k) - 1;
    for(int i = 0; i < vs.size() - k; i++){
        int idx2 = upper_bound(v.begin(), v.end(), vs[i+k]) - v.begin();
        int idx1 = lower_bound(v.begin(), v.end(), vs[i]) - v.begin();
        int res = idx2 - idx1;
        ans = min(ans, n - res);
    }

    cout<<ans<<endl;

    return 0;
}
