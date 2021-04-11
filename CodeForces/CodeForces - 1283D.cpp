//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 400005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int treeX[MAX], dist[MAX], n, m;

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    queue<int> q;

    map<int, int> mp;

    int idx = 1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &treeX[i]);
        q.push(treeX[i]);
        mp[treeX[i]] = idx++;
        dist[mp[treeX[i]]] = 0;
    }

    vector<int> res;
    int cnt = 0;
    ll ans = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int tu = u - 1;
        int tv = u + 1;
        if(mp[tu] == 0) {
            mp[tu] = idx++;
            dist[mp[tu]] = dist[mp[u]] + 1;
            cnt++;
            res.pb(tu);
            ans += dist[mp[tu]];
            if(cnt == m)
                break;
            q.push(tu);
        }
        if(mp[tv] == 0) {
            mp[tv] = idx++;
            dist[mp[tv]] = dist[mp[u]] + 1;
            cnt++;
            res.pb(tv);
            ans += dist[mp[tv]];
            if(cnt == m)
                break; 
            q.push(tv);  
        }
    }

    printf("%lld\n", ans);
    for(int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");


    return 0;
}