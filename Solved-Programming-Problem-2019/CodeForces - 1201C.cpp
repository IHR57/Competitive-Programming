//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define debug (printf("PINK FLOYD:)\n"))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
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

ll arr[MAX], cnt[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k;

	cin>>n>>k;

	for(int i = 0; i < n; i++){
        cin>>arr[i];
	}

	sort(arr, arr + n);
    set<ll> s;
    map<ll, int> MP;

	for(int i = n / 2; i < n; i++){
        s.insert(arr[i]);
        MP[arr[i]]++;
	}

	ll c = 0;
    while(s.size() > 1){
        ll x = *s.begin();
        s.erase(*s.begin());
        ll y = *s.begin();
        c = c + MP[x];
        k -= (y - x) * c;
        if(k <= 0){
            cout<<(x + ((k + (y - x) * c)) / c)<<endl;
            return 0;
        }
    }

    cout<<(*s.begin() + (k / ((n / 2) + 1)))<<endl;

    return 0;
}
