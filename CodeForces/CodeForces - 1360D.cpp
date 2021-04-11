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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n, k;

    cin>>test;

    while(test--) {
        cin>>n>>k;
        vector<int> div;
        for(ll i = 1; i * i <= n; i++) {
            if(n % i == 0 && i <= k) {
                div.pb(i);
                if(n / i != i && n / i <= k)
                    div.pb(n / i);
            }
        }

        sort(div.begin(), div.end());

        int x = div[div.size()-1];

        cout<<n / x<<endl;

    }
    return 0;
}
