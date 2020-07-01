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
#define MAX 300005
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
 
 
bool compare(ii A, ii B)
{
    return (1LL * A.ff * B.ss) > (1LL * A.ss * B.ff);
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
 
    int n;
 
    cin>>n;
 
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin>>str;
        int k = str.size();
        int s = 0, h = 0;
        for(int j = 0; j < k; j++) {
            if(str[j] == 's')
                s++;
            else{
                ans += (ll) s;
                h++;
            }
        }
 
        vp.pb(mk(s, h));
    }
 
    sort(vp.begin(), vp.end(), compare);
 
    ll curr = 0;
    for(int i = 0; i < vp.size(); i++) {
        ans += (curr * vp[i].ss);
        curr += (ll) vp[i].ff;
    }
 
    cout<<ans<<endl;
 
    return 0;
}