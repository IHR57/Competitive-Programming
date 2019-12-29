/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
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
    int c, d, n, m, k;

    cin>>c>>d;
    cin>>n>>m;
    cin>>k;

    int need = (n * m) - k;
    if(need <= 0){
        cout<<0<<endl;
        return 0;
    }

    int ans = 1e8;
    for(int i = 0; i <= 10000; i++){
        int problems = (i * c);
        if(need > (i * n)){
            problems += (need - (i * n)) * d;
        }
        ans = min(ans, problems);
    }

    cout<<ans<<endl;

    return 0;
}
