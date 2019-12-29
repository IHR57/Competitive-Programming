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
#define MAX 55
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int minOp[55][55];
const int inf = 1<<28;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    string str;

    map<string, int> mp;
    cin>>n;
    cin>>str;

    int len = str.size(), idx = 1;
    str += str;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            minOp[i][j] = inf;
    }

    for(int i = 0; i <= (int) str.size() - len - 1; i++){
        string temp = str.substr(i, len);
        if(mp[temp] == 0)
            mp[temp] = idx++;
        minOp[0][mp[temp]] = min(minOp[0][mp[temp]], i);
    }

    for(int i = 1; i <= n - 1; i++){
        cin>>str;
        str += str;
        for(int j = 0; j <= (int) str.size() - len - 1; j++){
            string temp = str.substr(j, len);
            if(mp[temp] == 0)
                continue;
            minOp[i][mp[temp]] = min(minOp[i][mp[temp]], j);
        }
    }

    int ans = inf;

    for(int i = 1; i < idx; i++){
        int tot = 0;
        for(int j = 0; j < n; j++){
            if(minOp[j][i] == inf){
                tot = inf;
                break;
            }
            tot += minOp[j][i];
        }
        if(tot < ans){
            ans = tot;
        }
    }

    (ans == inf) ? cout<<-1<<endl : cout<<ans<<endl;

    return 0;
}
