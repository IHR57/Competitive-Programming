/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: Psychedelic
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
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
    ll k, d, t;

    cin>>k>>d>>t;

    ll upper = 0, lower = 2 * t, lim;
    if(k < d){
        upper = 2 * k + (d - k);
        lim = d;
    }
    else{
        ll t = (k % d == 0) ? k / d : k / d + 1;
        upper = 2 * k + (t * d - k);
        lim = t * d;
    }
    //cout<<upper<<"/"<<lower<<endl;
    double pos = (lower / upper) * (double) lim;

    ll rem = (lower % upper);

    if(rem <= 2 * k){
        pos += (double) rem / 2;
    }
    else{
        pos += (k + (rem - 2 * k));
    }

    cout<<fixed<<setprecision(12);
    cout<<pos<<endl;


    return 0;
}
