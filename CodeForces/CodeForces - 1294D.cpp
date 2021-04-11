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
#define MAX 400005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int ans[MAX], cnt[MAX], res[MAX], vis[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int q;
    ll x;

    cin>>q>>x;

    int curr = 0;
    for(int i = 0; i < q; i++){
        ll val;
        cin>>val;

        if(val - x < 0){
            ans[i] = val;
            if(val >= q)
                ans[i] = q;
        }
        else{
            int t = (val - x) / x;
            val -= (x * (t + 1));
            ans[i] = val;
        }
    }

    for(int i = 0; i < q; i++){
        if(ans[i] >= q)
            res[i] = ans[i];
        if(!vis[ans[i]]){
            res[i] = ans[i];
            vis[ans[i]] = 1;
            cnt[ans[i]]++;
        }
        else{
            res[i] = ans[i] + (x * cnt[ans[i]]);
            cnt[ans[i]]++;
        }
    }

    set<int> s;
    curr = 0;
    for(int i = 0; i < q; i++){
        s.insert(res[i]);
        while(s.find(curr) != s.end()){
            curr++;
        }
        cout<<curr<<endl;
    }
    return 0;
}
