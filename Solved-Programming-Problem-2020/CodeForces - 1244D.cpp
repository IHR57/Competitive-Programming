//Date: 17/03/2020
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
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}


int n, c[3][MAX], ans[MAX];
vector<int> graph[MAX], seq;

void dfs(int u, int par)
{
    seq.pb(u);
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u);
    }
}


// ll solve(int pos, int prev, int preprev)
// {
//     if(pos >= n)
//         return 0;

//     if(dp[pos][prev][preprev] != -1)
//         return dp[pos][prev][preprev];

//     ll ret = 2e18, temp;

//     for(int i = 0; i < 3; i++){
//         if(pos == 0){
//             temp = (ll) c[i][seq[pos]] + solve(pos + 1, i, 0);
//             if(temp < ret){
//                 ret = temp;
//                 res[seq[pos]] = i;
//             }
//         }
//         else if(pos == 1){
//             if(i != prev){
//                 temp = (ll) c[i][seq[pos]] + solve(pos + 1, i, prev);
//                 if(temp < ret){
//                     ret = temp;
//                     res[seq[pos]] = i;
//                 }
//             }
//         }
//         else{
//             if(i != prev && i != preprev){
//                 temp = (ll) c[i][seq[pos]] + solve(pos + 1, i, prev);
//                 if(temp < ret){
//                     ret = temp;
//                     res[seq[pos]] = i;
//                 }
//             }
//         }
//     }

//     return dp[pos][prev][preprev] = ret;
// }


ll solve(int arr[])
{
    ll res = 0;
    for(int i = 0; i < seq.size(); i++){
        res += c[arr[i%3]][seq[i]];
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin>>c[i][j];
        }
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int idx = -1;
    for(int i = 0; i < n; i++){
        if(graph[i].size() >= 3){
            cout<<-1<<endl;
            return 0;
        }
        if(graph[i].size() == 1){
            if(idx == -1)
                idx = i;
        }
    }

    dfs(idx, -1);

    int ps[6][3] = { {0, 1, 2}, {0, 2, 1},
                     {1, 0, 2}, {1, 2, 0},
                     {2, 0, 1}, {2, 1, 0} };

    ll res= 2e18, temp;
    for(int i = 0; i < 6; i++){
        ll temp = solve(ps[i]);
        if(temp < res){
            res = temp;
            idx = i;
        }
    }

    for(int i = 0; i < n; i++){
        ans[seq[i]] = ps[idx][i%3];
    }
    
    cout<<res<<endl;
    for(int i = 0; i < n; i++){
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;

    return 0;

}
