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

int cnt[MAX];
vector<string> vs;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    map<string, int> MP;
    string str;
    int idx = 1;
    for(int i = 0; i < n; i++){
        cin>>str;
        sort(str.begin(), str.end());
        if(MP[str] == 0){
            MP[str] = idx++;
            vs.pb(str);
        }
        cnt[MP[str]]++;
    }
    ll res = 0;
    for(int i = 0; i < vs.size(); i++){
        ll x = cnt[MP[vs[i]]];
        res += (x * (x - 1)) / 2LL;
    }

    cout<<res<<endl;

    return 0;
}

