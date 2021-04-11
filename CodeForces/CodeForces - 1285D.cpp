//Date: 11/01/20
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
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)((mask >> pos) & 1);}
 
int n, arr[MAX];

int solve(vector<int> &a, int bit)
{
    if(a.empty() || bit < 0)
        return 0;
    vector<int> on, off;
    for(int i = 0; i < a.size(); i++){
        if(check(a[i], bit))
            on.pb(a[i]);
        else
            off.pb(a[i]);
    }

    if(on.empty())
        return solve(off, bit - 1);
    if(off.empty())
        return solve(on, bit - 1);

    return min(solve(on, bit - 1), solve(off, bit - 1)) + (1<<bit);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a;

    cin>>n;

    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        a.pb(val);
    }

    int res = solve(a, 30);

    cout<<res<<endl;
 
    return 0;
}