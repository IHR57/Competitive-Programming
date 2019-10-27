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
#define MAX 1005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ii arr[MAX], cap[MAX];
int dp[MAX][MAX], n, k, vis[MAX];
vector <ii> v;

bool compare(ii A, ii B)
{
    if(A.ff == B.ff)
        return A.ss > B.ss;
    return A.ff < B.ff;
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i].ff>>arr[i].ss;
    }

    cin>>k;
    for(int i = 0; i < k; i++){
        cin>>cap[i].ff;
        cap[i].ss = i;
    }

    sort(cap, cap + k);
    int idx;

    int ans = 0;
    for(int i = 0; i < k; i++){
        int Max = 0;
        for(int j = 0; j < n; j++){
            if(cap[i].ff >= arr[j].ff && !vis[j]){
                if(arr[j].ss > Max){
                    Max = arr[j].ss;
                    idx = j;
                }
            }
        }
        if(Max != 0){
            vis[idx] = 1;
            v.pb(mk(idx, cap[i].ss));
            ans += Max;
        }
    }

    cout<<v.size()<<" "<<ans<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i].ff + 1<<" "<<v[i].ss + 1<<endl;
    }

    return 0;
}
