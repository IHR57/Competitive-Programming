//Date: 28/10/19
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
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int m = 31;			// for 26 characters m = 29 or 31, for 52 characters m should be 53
ll hash[MAX], p[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    string str;

    cin>>str;

    int n = str.size();

    p[0] = 1;
    for(int i = 1; i <= n; i++)		//precalculating for O(1) comparison
    	p[i] = (p[i-1] * m) % MOD;

    hash[0] = 0;
    for(int i = 0; i < n; i++){		//computing prefix hash value
    	hash[i+1] = (hash[i] + (str[i] - 48) * p[i]) % MOD;
    }

    int x, y, q, len;

    cin>>q;

    for(int i = 0; i < q; i++){
    	cin>>x>>y>>len;			//comparing substring starts at index x and y with given len
    	ll tx = (p[y] * (hash[x+len] - hash[x] + MOD)) % MOD;
    	ll ty = (p[x] * (hash[y+len] - hash[y] + MOD)) % MOD;
    	if(tx == ty){
    		cout<<"EQUAL"<<endl;
    	}
    	else{
    		cout<<"NOT EQUAL!!"<<endl;
    	}
    }
    return 0;
}
