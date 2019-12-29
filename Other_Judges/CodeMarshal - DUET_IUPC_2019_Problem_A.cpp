//Date: 24/09/19
//Problem Link: https://algo.codemarshal.org/contests/duet-iupc-19/problems/A
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
 
typedef unsigned long long ll;
typedef pair<string, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int spaces[105], dist[105], vis[105];
vector<ii> graph[105];

bool compare(ii A, ii B)
{
    return A.ff < B.ff;
}
void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        ii v = graph[u][i];
        if(!vis[v.ss]){
            dist[v.ss] = dist[u] + 1;
            for(int j = 0; j < dist[v.ss] - 1; j++){
                cout<<" ";
            }
            cout<<v.ff<<endl;
            dfs(v.ss);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, caseno = 1;
    int n;
    string str;

    cin>>test;

    while(test--){
        cin>>n;
        map<string, int> mp;
        int idx = 1;

        getline(cin,str);
        for(int i = 0; i < n; i++){
            getline(cin, str);
            string temp = "";
            int sp = 0;
            for(int i = 0; i < str.size(); i++){
                if(str[i] == ' ')
                    sp++;
                else
                    temp += str[i];
            }
            if(mp[temp] == 0){
                mp[temp] = idx++;
            }
            if(sp == 0){
                graph[0].pb(mk(temp, mp[temp]));
            }
            else{
                graph[spaces[sp-1]].pb(mk(temp, mp[temp]));
            }
            spaces[sp] = mp[temp];
        }
        for(int i = 0; i < idx; i++){
            sort(graph[i].begin(), graph[i].end(), compare);
        }
        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        cout<<"Case "<<caseno++<<":"<<endl;
        dfs(0);
        for(int i = 0; i < 105; i++)
            graph[i].clear();
    }
    return 0;
}