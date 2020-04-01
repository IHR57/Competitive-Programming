/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: Psychedelic
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
#define MAX 300005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int freq[MAX][26], ind[MAX];
vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n, m;

    cin>>n>>m;

    string str;

    cin>>str;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        graph[u].pb(v);
        ind[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(ind[i] == 0){
            q.push(i);
            freq[i][str[i]-'a'] = 1;
        }
    }

    int Max = 1, cnt = n;
    while(!q.empty()){
        cnt--;
        int x = q.front();
        q.pop();
        for(int i = 0; i < graph[x].size(); i++){
            //cout<<"HELL:("<<endl;
            int v = graph[x][i];
            ind[v]--;
            if(ind[v] == 0)
                q.push(v);
            for(int j = 0; j < 26; j++){
                freq[v][j] = max(freq[v][j], freq[x][j] + ((str[v]-'a') == j));
                Max = max(Max, freq[v][j]);
            }
        }
    }
    
    (cnt) ? cout<<-1<<endl : cout<<Max<<endl;

    return 0;
}
