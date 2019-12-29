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
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> graph[MAX];
int mark[MAX], cs[MAX], seq[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        cin>>seq[i];
        cs[i] = cs[i-1] + seq[i];
    }
    if(seq[1] != 1){
        cout<<"No"<<endl;
        return 0;
    }

    int idx = 1;

    for(int i = 1; i <= n; i++){
        mark[seq[i]] = 1;
        int cnt = 0, sum = 0;
        for(int j = 0; j < graph[seq[i]].size(); j++){
            int v = graph[seq[i]][j];
            if(!mark[v]){
                cnt++;
                sum += v;
            }
        }
        int temp = cs[idx+cnt] - cs[idx];
        //cout<<idx<<endl;
        if(temp != sum){
            cout<<"No"<<endl;
            return 0;
        }
        idx += cnt;
    }

    cout<<"Yes"<<endl;


    return 0;
}
