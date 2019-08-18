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
#define MAX 100005
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<ii> v;

bool comp(ii A, ii B)
{
    if(A.ff == B.ff)
        return A.ss < B.ss;
    return A.ff < B.ff;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int l, r, n, m;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>l>>r;
        v.pb(mp(l, r));
    }

    sort(v.begin(), v.end(), comp);

    int Mx = 0, Mn = 1e9;
    int cnt = 1;
    for(int i = 0; i < v.size(); i++){
        Mx = max(Mx, v[i].ff);
        Mn = min(Mn, v[i].ss);
        if(Mn - Mx <= 0){
            cnt++;
            if(i < v.size() - 1){
                Mx = v[i].ff;
                Mn = v[i].ss;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
