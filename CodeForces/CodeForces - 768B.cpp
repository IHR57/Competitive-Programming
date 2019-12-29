/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
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
    ll n, l, r;

    cin>>n>>l>>r;
    ll temp;

    ll sum = 0;
    int lg = log2(n);
    for(ll i = l; i <= r; i++){
        ll t = i, k = n, tlg = lg;
        while(true){
            if(k <= 1){
                sum += k;
                break;
            }
            ll tm = ((1LL << tlg) - 1);
            if(t - tm > 0){      //out of range
                t -= tm;
                if(t  - 1 > 0)      //out of range
                    t -= 1;
                else if(t - 1 == 0){
                    sum += (k % 2);
                    break;
                }
            }
            k /= 2;
            tlg--;
        }
    }

    cout<<sum<<endl;

    return 0;
}
