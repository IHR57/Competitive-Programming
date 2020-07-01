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

ll arr[MAX], cnt[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll a, b, n;
    ll sum = 0;

    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        cnt[arr[i]]++;
        sum += arr[i];
    }

    int q;
    cin>>q;

    while(q--) {
        cin>>a>>b;
        if(!cnt[a]) {
            cout<<sum<<endl;
            continue;
        }
        sum -= 1LL * cnt[a] * a;
        sum += 1LL * cnt[a] * b;
        cnt[b] += cnt[a];
        cnt[a] = 0;

        cout<<sum<<endl;
    }

    return 0;
}
