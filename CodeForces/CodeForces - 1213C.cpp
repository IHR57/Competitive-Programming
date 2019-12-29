//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
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

    int q;
    ll n, m;

    cin>>q;

    while(q--){
        cin>>n>>m;
        if(m > n){
            cout<<0<<endl;
            continue;
        }
        ll x = m;
        ll sum = 0;
        bool flag = false;
        for(int i = 1; i <= 10; i++){
            x = (m * i);
            if(x > n){
                flag = true;
                break;
            }
            sum += (x % 10);
        }
        if(flag){
            cout<<sum<<endl;
            continue;
        }
        ll rem = (n / (m * 10));
        sum = (sum * rem);
        for(ll i = (m * 10 * rem); i <= n; i += m){
            sum += (i % 10);
        }

        cout<<sum<<endl;
    }
    return 0;
}
