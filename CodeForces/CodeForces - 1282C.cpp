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


int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test;
    ll n, totalTime, a, b;

    scanf("%d", &test);

    while(test--) {
        scanf("%lld %lld %lld %lld", &n, &totalTime, &a, &b);
        vector<ii> vp(n + 1);

        ll type1 = 0, type2 = 0;

        for(int i = 0; i < n; i++) {    
            scanf("%d", &vp[i].ss);
            (vp[i].ss == 0) ? type1++ : type2++;
        }

        for(int i = 0; i < n; i++)
            scanf("%d", &vp[i].ff);

        vp[n] = {totalTime + 1, 0};
        sort(vp.begin(), vp.end());

        ll ans = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i <= n; i++) {
            ll req = cnt1 * a + cnt2 * b;
            ll extra = vp[i].ff - req - 1;
            if(extra >= 0) {
                ll t1 = min(type1 - cnt1, extra / a);
                extra -= (t1 * a);
                ll t2 = min(type2 - cnt2, extra / b);
                extra -= (t2 * b);
                ans = max(ans, cnt1 + cnt2 + t1 + t2);
            }

            int idx = i;
            while(idx < vp.size() && vp[idx].ff == vp[i].ff) {
                (vp[idx].ss == 0) ? cnt1++ : cnt2++;
                idx++;
            }

            i = idx - 1;
        }

        printf("%lld\n", ans);

    }


    return 0;
}