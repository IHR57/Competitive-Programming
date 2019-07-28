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

ll mark[(MAX/32) + 100];
int primes[MAX/10], counter = 0;

void bitwiseSieve()
{
	int limit = sqrt(MAX + 1);
	for(int i = 3; i <= limit; i += 2){
		if(check(mark[i/32], i % 32) == 0){
			for(int j = i * i; j < MAX; j += i * 2){
				mark[j/32] = Set(mark[j/32], j % 32);
			}
		}
	}
	primes[counter++] = 2;
	for(int i = 3; i < MAX; i += 2){
		if(check(mark[i/32], i % 32) == 0){
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
   	bitwiseSieve();

   	for(int i = 0; i < 10; i++){
   		cout<<primes[i]<<" ";
   	}
   	cout<<endl;

    return 0;
}
