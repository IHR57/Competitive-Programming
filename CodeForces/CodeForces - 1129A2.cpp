/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 5005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> v[MAX];
int dest[MAX];

bool compare(ii A, ii B)
{
    return A.ss < B.ss;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m, a, b;

    cin>>n>>m;

    for(int i = 1; i <= m; i++){
        cin>>a>>b;
        int x = (b > a) ? (b - a) : (b - a + n);
        v[a].pb(x);
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }

    for(int i = 1; i <= n; i++){
        int ans = -1;
        for(int j = 1; j <= n; j++){
            int cnt = 0;
            if(v[j].empty())
                continue;
            if(j >= i)
                cnt = j - i;
            else
                cnt = j - i + n;
            cnt += (v[j].size() - 1) * n;
            cnt += v[j][0];
            ans = max(ans, cnt);
        }
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}
