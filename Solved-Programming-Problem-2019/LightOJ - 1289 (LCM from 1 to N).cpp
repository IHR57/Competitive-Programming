//Problem ID: LightOJ - 1289 (LCM from 1 to N)
//Programmer: IQBAL HOSSAIN 	Description: Number Theory
//Date: 23/07/19
#include <bits/stdc++.h>
#define MAX 100000100
#define pb push_back
#define INF 2147483647
#define MOD 4294967296
using namespace std;

typedef long long ll;

ll mark[(MAX/64) + 100];
unsigned primes[5800000];
vector<unsigned> p[10005];
unsigned int cs[5800000];
int counter = 0;

void genSieve()
{
	int limit = sqrt(MAX);
	// mark[1] = 1;
	// for(int i = 4; i < MAX; i += 2)
	// 	mark[i] = 1;
	// primes.pb(2);
	// for(int i = 3; i < MAX; i += 2){
	// 	if(!mark[i]){
	// 		primes.pb(i);
	// 		if(i <= limit){
	// 			for(ll j = i * i; j < MAX; j += i * 2)
	// 				mark[j] = 1;
	// 		}
	// 	}
	// }
	for(ll i = 3; i <= limit; i += 2){
		if(!(mark[i/64] & (1LL<<(i%64)))){
			for(ll j = i * i; j < MAX; j += i * 2){
				mark[j/64] |= (1LL<<(j%64));
			}
		}
	}

	primes[counter++] = 2;
	for(ll i = 3; i < MAX; i += 2){
		if(!(mark[i/64] & (1LL<<(i%64)))){
			primes[counter++] = i;
		}
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
    //cout<<primes[primes.size()-1]<<endl;
    for(int i = 0; (primes[i] * primes[i]) < MAX; i++){
    	ll temp = 1;
    	for(int j = 1; ; j++){
    		temp = temp * primes[i];
    		if(temp > 100000000)
    			break;
    		p[primes[i]].pb(temp);
    	}
    }

    cs[0] = 2;
    for(int i = 1; i < counter; i++){
    	cs[i] = (cs[i-1] * primes[i]);
    }

    int test, caseno = 1, n;

    scanf("%d", &test);

    while(test--){
    	scanf("%d", &n);
    	int idx = upper_bound(primes, primes + counter, n) - primes;
    	unsigned ans = 1;
    	ans = (ans * cs[idx-1]);
    	//cout<<cs[idx-1]<<endl;
    	for(int i = 0; (primes[i] * primes[i]) <= n; i++){
    		int x = upper_bound(p[primes[i]].begin(), p[primes[i]].end(), n) - p[primes[i]].begin();
    		if(x - 2 >= 0){
    			ans = (ans * p[primes[i]][x-2]);
    		}
    		//cout<<p[primes[i]][x-2]<<endl;
    	}
    	printf("Case %d: %u\n", caseno++, ans);
    }

    return 0;
}