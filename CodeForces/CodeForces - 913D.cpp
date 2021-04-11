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
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
bool vis[MAX];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int n, T, val, t;
 
    cin>>n>>T;

    vector<ii> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i].ff>>v[i].ss;
    }
 
    int low = 1, high = n, mid, ans = -1;
    vector<int> indices;

    while(low <= high) {
        mid = (low + high + 1) >> 1;
        vector<ii> vs;
        for(int i = 0; i < n; i++) {
            if(v[i].ff >= mid) {
                vs.pb(mk(v[i].ss, i));
            }
        }

        sort(vs.begin(), vs.end());

        vector<int> tans;
        int totalTime = 0;
        int cnt = 0;

        for(int i = 0; i < vs.size(); i++) {
            if(totalTime + vs[i].ff <= T) {
                totalTime += vs[i].ff;
                cnt++;
                tans.pb(vs[i].ss);
            }
            if(cnt == mid){
                break;
            }
        }

        if(cnt == mid) {
            ans = mid;
            indices = tans;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(ans == -1) {
        cout<<0<<endl<<0<<endl;
        return 0;
    }

    cout<<ans<<endl;
    cout<<indices.size()<<endl;
    for(int i = 0; i < ans; i++) {
        cout<<indices[i] + 1<<" ";
    }
    cout<<endl;
 
    return 0;
}
 
