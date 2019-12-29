#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;
    ll a, b;

    cin>>test;

    while(test--){
        cin>>a>>b;
        int lga = log2(a), lgb = log2(b);
        if(lga != lgb){
            cout<<0<<endl;
            continue;
        }
        ll ans = (1LL << lga);
        int k = lga - 1;
        while(true){
            if(k < 0)
                break;
            else if(a >= (ans + (1LL << k)) && (ans + (1LL << k)) + (1LL << k) >= b){
                //cout<<(1LL << k)<<endl;
                ans += (1LL << k);
            } 
            k--;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
