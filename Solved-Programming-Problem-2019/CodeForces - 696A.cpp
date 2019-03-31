//Problem ID: CodeForces - 696A (Lorenzo Von Matterhorn)
//Programmer: IQBAL HOSSAIN     Description: Brute Force/Data Structures
//Date: 30/30/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;
map<ll, ll> mp;
int idx = 0;

void update(ll u, ll v, ll w)
{
    while(u != v){
        while(v > u){
            mp[v] += w;
            v /= 2;
        }
        while(u > v){
            mp[u] += w;
            u /= 2;
        }
    }
}

ll query(ll u, ll v)
{
    ll ret = 0;
    while(u != v){
        while(v > u){
            ret += mp[v];
            v /= 2;
        }
        while(u > v){
            ret += mp[u];
            u /= 2;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, cmd;
    ll u, v, w;

    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>cmd;
        if(cmd == 1){
            cin>>u>>v>>w;
            update(u, v, w);
        }
        if(cmd == 2){
            cin>>u>>v;
            ll res = query(u, v);
            cout<<res<<endl;
        }
    }

    return 0;
}
