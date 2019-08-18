#include <bits/stdc++.h>
#define INF 2147483647
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

vector<int> v[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, m;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        v[a].pb(b);
    }

    priority_queue<int> pq;
    int res = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < v[i].size(); j++){
            pq.push(v[i][j]);
        }
        if(pq.size()){
            res += pq.top();
            pq.pop();
        }
    }

    cout<<res<<endl;

    return 0;
}

