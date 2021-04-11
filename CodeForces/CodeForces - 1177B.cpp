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
#define MAX 2750132
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll totalDigit(ll x)
{
    ll p = 10, k = 9, sum = 0, cnt = 1;
    ll t = x;
    while((x / p) != 0) {
        sum += 1LL * cnt * k;
        k *= 10;
        p *= 10;
        cnt++;
    }
    p /= 10;
    sum += 1LL * cnt * (t - p + 1);

    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll p, k;

    cin>>k;

    ll low = 1, high = k, mid, ans = -1;

    while(low <= high) {
        mid = (low + high + 1) >> 1;
        ll cnt = totalDigit(mid);
        if(cnt >= k) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    ll x = totalDigit(ans - 1);
    vector<int> digit;
    while(ans) {
        digit.pb(ans % 10);
        ans /= 10;
    }
    reverse(digit.begin(), digit.end());

    int res;
    for(int i = 0; i <  digit.size(); i++) {
        res = digit[i];
        x++;
        if(x == k) {
            break;
        }
    }


    cout<<res<<endl;

    return 0;
}


