//Date: 28/12/19
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
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cost[MAX], p[MAX], degree[MAX], zeroD[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;

    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>cost[i];

    for(int i = 1; i <= n; i++){
        cin>>p[i];
        degree[p[i]]++;
    }

    int k = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            zeroD[k++] = i;
        }
    }

    for(int i = 0; i < k; i++){
        int v = zeroD[i];
        degree[p[v]]--;
        if(degree[p[v]] == 0){
            zeroD[k++] = p[v];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] != 0){
            int par = i, minIdx = -1, MinCost = INF;
            while(degree[par] != 0){
                degree[par]--;
                if(cost[par] < MinCost){
                    MinCost = cost[par];
                }
                par = p[par];
            }
            ans += MinCost;
        }
    }

    cout<<ans<<endl;


    return 0;
}