/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Date: 10/09/19
//Category: Number Theory
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
#define MAX 1000105
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int primes[80000], counter;
bool mark[MAX];

void genSieve()
{
	int limit = sqrt(MAX + 1);
	mark[1] = 1;
	for(int i = 4; i < MAX; i += 2)
		mark[i] = 1;
	primes[counter++] = 2;
	for(int i = 3; i < MAX; i += 2){
		if(!mark[i]){
			primes[counter++] = i;
			if(i <= limit){
				for(int j = i * i; j < MAX; j += i * 2)
					mark[j] = 1 ;
			}
		}
	}
}

vector<ll> factor;
map<ll, int> freq;

void factorize(ll n)
{
	int idx = 0;
	ll pf = primes[idx];

	while(pf * pf <= n){
		if(n % pf == 0){
			factor.pb(pf);
			while(n % pf == 0){
				n /= pf;
				freq[pf]++;
			}
		}
		pf = primes[++idx];
	}
	if(n != 1){
		factor.pb(n);
		freq[n]++;
	}
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    genSieve();
    ll n, b;

    cin>>n>>b;
    factorize(b);

    ll trailingZero = 1e18;
    for(int i = 0; i < factor.size(); i++){
    	ll x = factor[i];
    	ll s = 0, t = n;
    	while(t){
    		s += (t / x);
    		t = t / x;
    	}
    	s /= freq[factor[i]];
    	//cout<<s<<endl;
    	trailingZero = min(trailingZero, s);
    }

    cout<<trailingZero<<endl;

    return 0;
}
