//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int bit[MAX];

void update(int idx, int val)
{
    while(idx <= MAX) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int getAns(int idx) 
{
    int ans = 0;

    while(idx > 0) {
        ans += bit[idx];
        idx -= (idx & -idx);
    }

    return ans;
}

bool compare(pii A, pii B)
{
    if(A.ff.ff == B.ff.ff)
        return A.ff.ss > B.ff.ss;

    return A.ff.ff < B.ff.ff;
}

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    vector<ii> vt;
    vector<pii> vp;

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        vp.pb(mk(mk(u, v), i));
        vt.pb(mk(u, v));
        update(u, 1);
        update(v + 1, -1);
    }

    sort(vp.begin(), vp.end(), compare);

    set<ii> s;

    vector<int> res;

    for(int i = 0; i < vp.size(); i++) {
        int ans = getAns(vp[i].ff.ff);
        s.insert(mk(vp[i].ff.ss, vp[i].ss));
        int sz = vp.size();
        if(i < (sz - 1) && vp[i].ff.ff == vp[i+1].ff.ff)
            continue;
        // cout<<vp[i].ff.ff<<" "<<vp[i].ff.ss<<" "<<ans<<endl;
        if(ans > k) {
            while(!s.empty()) {
                ii tmp = *s.rbegin();
                if(tmp.ff < vp[i].ff.ff)
                    break;
                update(vt[tmp.ss].ff, -1);
                update(vt[tmp.ss].ss + 1, 1);
                res.pb(tmp.ss + 1);
                ans--;
                s.erase(*s.rbegin());
                if(ans == k)
                    break;
            }
        }
    }

    printf("%d\n", res.size());
    for(int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}


