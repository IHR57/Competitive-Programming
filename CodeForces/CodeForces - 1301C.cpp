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

void bruteForce()
{
    int k = 11, bit = 3;
    int cnt = 0, Max = 0;
    for(int i = 0; i < (1 << (k)); i++){
        //cout<<__builtin_popcount(i)<<endl;
        if(__builtin_popcount(i) == bit){
            cout<<i<<endl;
            int cs[k+5] = {0};
            for(int j = 0; j < k; j++){
                if(check(i, j))
                    cs[j+1] = cs[j] + 1;
                else
                    cs[j+1] = cs[j];
            }
            for(int j = 1; j <= k; j++){
                for(int m = j; m <= k; m++){
                    if(cs[m] - cs[j-1] >= 1){
                        cnt++;
                    }
                }
            }
            Max = max(Max, cnt);
            cnt = 0;
        }
    }
    cout<<Max<<endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //bruteForce();

    ll n, m;
    int test;

    cin>>test;

    while(test--){
        cin>>n>>m;

        ll group = (m + 1);
        ll zeroes = (n - m);

        ll t = (zeroes / group);

        ll ans = (n * (n + 1)) / 2 - ((t * (t + 1)) / 2) * group - (t + 1) * (zeroes % group);

        cout<<ans<<endl;
    }

    return 0;
}
