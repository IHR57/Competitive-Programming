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
#define MAX 1050
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int primes[MAX], counter = 0, mark[MAX];

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
                    mark[j] = 1;
            }
        }
    }

}

int largestPrimeFactor(int n)
{
    int maxFactor = 0;
    int idx = 0, pf = primes[idx];

    while(pf * pf <= n){
        if(n % pf == 0){
            while(n % pf == 0){
                n /= pf;
            }
            maxFactor = max(maxFactor, pf);
        }
        pf = primes[++idx];
    }

    if(n != 1)
        maxFactor = max(maxFactor, n);

    return maxFactor;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    genSieve();
    int n, ans = INF;

    cin>>n;

    int x = largestPrimeFactor(n);

    for(int i = n - x + 1; i <= n; i++){
        int y = largestPrimeFactor(i);
        if(i - y + 1 != 1)
            ans = min(ans, i - y + 1);
    }

    cout<<ans<<endl;

    return 0;
}
