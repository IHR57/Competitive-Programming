//Date: 19/10/19
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
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int a[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
    	cin>>a[i];
    }
    for(int i = 0; i < n; i++){
    	cin>>b[i];
    }

    map<ii, int>  mp;

    int Max = 0, cnt = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] == 0 && b[i] == 0){
    		cnt++;
    		continue;
    	}
    	else if(a[i] == 0)
    		continue;
    	int temp = -b[i];
    	int g = __gcd(abs(b[i]), abs(a[i]));
    	ii tx;
    	tx.ff = abs(b[i]) / g, tx.ss = abs(a[i]) / g;
    	if(temp < 0 && a[i] < 0){
    		mp[mk(tx.ff, tx.ss)]++;
    		Max = max(Max, mp[mk(tx.ff, tx.ss)]);
    	}
    	else if(temp < 0 || a[i] < 0){
    		mp[mk(-tx.ff, tx.ss)]++;
    		Max = max(Max, mp[mk(-tx.ff, tx.ss)]);
    	}
    	else{
    		mp[mk(tx.ff, tx.ss)]++;
    		Max = max(Max, mp[mk(tx.ff, tx.ss)]);
    	}
    }

    cout<<Max + cnt<<endl;

    return 0;
}