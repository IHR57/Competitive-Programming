#include <bits/stdc++.h>
#define MAX 105
#define MOD 1000000007
using namespace std;

typedef long long ll;

int visited[MAX][30];
ll cnt[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    string str;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < m; j++){
            int idx = str[j] - 'A';
            if(!visited[j][idx]){
                visited[j][idx] = 1;
                cnt[j]++;
            }
        }
    }

    ll ans = 1;
    for(int i = 0; i < m; i++){
        ans = (ans * cnt[i]) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}
