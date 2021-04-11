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

int cnt[40005][2], prop[40005][2];

void cal(int n, int idx)
{
    int val, c = 0;;
    for(int i = 0; i < n; i++) {
        cin>>val;
        if(val == 1) {
            c++;
            cnt[c][idx] += 1;
            if(c >= 2)
                prop[c][idx] += 1;
        }
        else
            c = 0;
    }

    for(int i = 40000; i >= 1; i--) {
        cnt[i][idx] += prop[i+1][idx];
        prop[i][idx] += prop[i+1][idx];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;

    cin>>n>>m>>k;

    cal(n, 0);
    cal(m, 1);

    ll ans = 0;
    for(int i = 1; i * i <= k; i++) {
        if(k % i == 0 && i <= 40000 && (k / i) <= 40000) {
            ans += 1LL * cnt[i][0] * cnt[k/i][1];
            if(k / i != i) {
                ans += 1LL * cnt[k/i][0] * cnt[i][1];
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

