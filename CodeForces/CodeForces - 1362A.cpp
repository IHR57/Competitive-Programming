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
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int test;
 
    cin>>test;
 
    while(test--) {
        ll a, b;
        cin>>a>>b;
        if(a > b)
            swap(a, b);
        int cnt = 0;
        ll ans = -1;
        if(a == b){
            ans = 0;
            cout<<0<<endl;
            continue;
        }
        if(b % a == 0) {
            ans = b / a;
        }
        else{
            cout<<ans<<endl;
            continue;
        }
 
        ll tans = ans;
        while(ans) {
            cnt++;
            ans /= 2;
        }
        if(1LL<<(cnt - 1) != tans) {
            cout<<-1<<endl;
            continue;
        }
 
        cnt -= 1;
        ll res = (cnt % 3 == 0) ? cnt / 3 : cnt / 3 + 1;
 
        cout<<res<<endl;
    }
    return 0;
}
