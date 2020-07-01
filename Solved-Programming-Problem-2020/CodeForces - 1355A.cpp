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
 
ll a1, a2, k;
 
ii minMaxDigit(ll n)
{
    int Min = 9, Max = 0;
    while(n) {
        int r = (n % 10);
        Min = min(Min, r);
        Max = max(Max, r);
        n /= 10;
    }
 
    return mk(Min, Max);
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int test;
 
    cin>>test;
 
    while(test--) {
        cin>>a1>>k;
 
        ll ans;
        if(k == 1){
            cout<<a1<<endl;
            continue;
        }
        for(int i = 2; ; i++) {
            ii temp = minMaxDigit(a1);
            a2 = a1 + (temp.ff * temp.ss);
            a1 = a2;
            if(i == k || (temp.ff * temp.ss == 0)) {
                ans = a1;
                break;
            }
 
        }
 
        cout<<ans<<endl;
    }
 
    return 0;
}