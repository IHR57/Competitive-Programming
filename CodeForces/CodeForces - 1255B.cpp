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

int arr[MAX];
vector<ii> vp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n, m;

    cin>>test;

    while(test--){
        cin>>n>>m;
        vp.clear();
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            vp.pb(mk(arr[i], i));
        }
        if(m < n || n == 2){
            cout<<-1<<endl;
            continue;
        }

        sort(vp.begin(), vp.end());

        ll cost = 0;
        vector<ii> ans;
        for(int i = 0; i < n - 1; i++){
            ans.pb(mk(vp[i].ss + 1, vp[i+1].ss + 1));
            cost += 1LL * (vp[i].ff + vp[i+1].ff);
        }
        cost += (vp[n-1].ff + vp[0].ff);
        ans.pb(mk(vp[n-1].ss + 1, vp[0].ss + 1));

        for(int i = n + 1; i <= m; i++){
            ans.pb(mk(vp[0].ss + 1, vp[1].ss + 1));
            cost += 1LL * (vp[0].ff + vp[1].ff);
        }

        cout<<cost<<endl;
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
        }
        //vp.clear();

    }

    return 0;
}
