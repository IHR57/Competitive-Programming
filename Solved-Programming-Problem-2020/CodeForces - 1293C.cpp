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
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

bool vis[3][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    int u, v;

    int cnt = 0;
    for(int i = 0; i < k; i++){
        cin>>u>>v;
        if(vis[u][v]){
            if(u == 1){
                if(vis[2][v-1])
                    cnt--;
                if(vis[2][v])
                    cnt--;
                if(vis[2][v+1])
                    cnt--;
            }
            else if(u == 2){
                if(vis[1][v-1])
                    cnt--;
                if(vis[1][v])
                    cnt--;
                if(vis[1][v+1])
                    cnt--;
            }
        }
        else{
            if(u == 1){
                if(vis[2][v-1])
                    cnt++;
                if(vis[2][v])
                    cnt++;
                if(vis[2][v+1])
                    cnt++;
            }
            else if(u == 2){
                if(vis[1][v-1])
                    cnt++;
                if(vis[1][v])
                    cnt++;
                if(vis[1][v+1])
                    cnt++;
            }
        }
        vis[u][v] = !vis[u][v];
        (cnt) ? cout<<"No"<<endl : cout<<"Yes"<<endl;
    }

    return 0;
}
