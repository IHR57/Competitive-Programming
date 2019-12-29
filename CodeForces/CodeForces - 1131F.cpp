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
#define MAX 150005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> v[MAX];
int parent[MAX], Rank[MAX];

void init()
{
    for(int i = 0; i < MAX; i++){
        Rank[i] = 1;
        parent[i] = i;
    }
}

int findParent(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

void unionSet(int a, int b)
{
    int x = findParent(a);
    int y = findParent(b);
    if(x != y){
        if(Rank[x] < Rank[y])
            swap(x, y);
        parent[y] = x;
        if(v[x].size() > 1){
            v[v[x][v[x].size()-1]].pb(y);
        }
        else
            v[x].pb(y);
        Rank[x] += Rank[y];
    }
}

void dfs(int u, int par)
{
    cout<<u<<" ";
    for(int i = 0; i < v[u].size(); i++){
        int x = v[u][i];
        if(x == par)
            continue;
        dfs(x, u);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    init();
    int n, u, v;

    cin>>n;
    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        unionSet(u, v);
    }
    int x = findParent(1);
    dfs(x, -1);
    cout<<endl;

    return 0;
}
