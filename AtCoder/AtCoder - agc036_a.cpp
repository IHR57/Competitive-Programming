#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define INF 2147483647
using namespace std;

typedef long long ll;

void test(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll ans = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll s;

    cin>>s;
    ll low = 1, high = 1e9, mid, sq;
    while(low <= high){
        mid = (low + high + 1) / 2;
        if(mid * mid >= s){
            sq = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    //cout<<y3<<endl;

    ll rem = ((sq * sq) - s);
    //test(0, 0, sq, 1, rem, sq);
    cout<<0<<" "<<0<<" "<<sq<<" "<<1<<" "<<rem<<" "<<sq<<endl;

    return 0;
}