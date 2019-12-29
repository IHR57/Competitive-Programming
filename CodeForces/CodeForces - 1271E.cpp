#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
using namespace std;
 
typedef long long ll;
 
ll n, k;
 
ll check(ll x)
{
    ll ans = 1, t = 1;
    if(x % 2 == 0){
        if(x + 1 <= n){
            ans += 1;
            t += 1;
        }
    }
    
    ll temp = x;
    while(true){
        temp *= 2;
        t *= 2;
        if(temp > n)
            break;
        if(temp + t <= n){
            ans += t;
        }
        else{
            ans += (n - temp + 1);
            break;
        }
    }
    
    return ans;
    
}
 
ll bs1()
{
    ll low = 1, high = (n) /2, mid, ans = -1;
    
    while(low <= high){
        mid = (low + high + 1) >> 1;
        if(check(mid * 2) >= k){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
    return ans * 2;
}
 
ll bs2()
{
    ll low = 0, high = n/2, mid, ans = -1;
    if(n % 2 == 0)
        high = high - 1;
    while(low <= high){
        mid = (low + high + 1) >> 1;
        if(check(mid * 2 + 1) >= k){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
    return ans * 2 + 1;
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>n>>k;
    
    ll ans = bs1();
    ans = max(ans, bs2());
 
    
    cout<<ans<<endl;
    
    return 0;
}