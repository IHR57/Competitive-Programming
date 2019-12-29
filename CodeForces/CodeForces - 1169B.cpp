#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
#define debug (printf("PINK FLOYD:)\n"))
#define iosflags (cout<<setiosflags(ios::fixed)<<setprecision(8))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

map<ii, int> counter;
int cnt[MAX];
vii vc;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;

	cin>>n>>m;

	int u, v;
	for(int i = 0; i < m; i++){
        cin>>u>>v;
        if(u > v)
            swap(u, v);
        counter[mp(u, v)]++;
        cnt[u]++;
        cnt[v]++;
	}

    for(int i = 1; i <= n; i++){
        vc.pb(mp(cnt[i], i));
    }
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());

    for(int i = 0; i < vc.size(); i++){
        for(int j = i + 1; j < vc.size(); j++){
            if(vc[i].ff + vc[j].ff < m)
                break;
            u = vc[i].ss, v = vc[j].ss;
            if(u > v)
                swap(u, v);
            int ans = vc[i].ff + vc[j].ff - counter[mp(u, v)];
            if(ans >= m){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}
