//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int parent[MAX], Rank[MAX];
int conn[MAX];

int findSet(int x)          
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}


void unionSet(int a, int b)
{
    if(Rank[a] < Rank[b])
        swap(a, b);
    if(Rank[a] == Rank[b])
        Rank[a]++;
    parent[b] = a;
    conn[a] += conn[b];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, m, k;

    cin>>n>>m>>k;

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }

    vi special(k);
    for(int i = 0; i < k; i++) {
        cin>>special[i];
        conn[special[i]] = 1;
    }

    vector<pii> edges(m);

    for(int i = 0; i < m; i++) {
        cin>>edges[i].ss.ff>>edges[i].ss.ss>>edges[i].ff;
    }

    sort(edges.begin(), edges.end());

    int ans;

    for(int i = 0; i < m; i++) {
        int u = findSet(edges[i].ss.ff);
        int v = findSet(edges[i].ss.ss);

        if(u != v) {
            if(conn[u] + conn[v] == k) {
                ans = edges[i].ff;
                break;
            }
            unionSet(u, v);
        }
    }

    for(int i = 0; i < k; i++) {
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}


