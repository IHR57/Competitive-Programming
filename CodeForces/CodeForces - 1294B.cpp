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
#define MAX 1005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<ii> vp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, u, v;

    cin>>test;

    while(test--){
        int n;
        cin>>n;
        vp.clear();

        for(int i = 0; i < n; i++){
            cin>>u>>v;
            vp.pb(mk(u, v));
        }

        sort(vp.begin(), vp.end());

        string ans = "";
        for(int i = 0; i < vp[0].ff; i++)
            ans += "R";
        for(int i = 0; i < vp[0].ss; i++)
            ans += "U";

        bool flag = true;
        for(int i = 1; i < vp.size(); i++){
            int tx = vp[i].ff - vp[i-1].ff;
            for(int j = 0; j < tx; j++)
                ans += "R";
            int ty = vp[i].ss - vp[i-1].ss;
            if(ty < 0){
                flag = false;
                break;
            }
            for(int j = 0; j < ty; j++)
                ans += "U";
        }

        (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        if(flag)
            cout<<ans<<endl;
    }

    return 0;
}
