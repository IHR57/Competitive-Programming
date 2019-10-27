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
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, k, arr[MAX];
ll ksum[MAX];
ii maxSum[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int m = 0;
    ll sum = 0;
    for(int i = n - 1; i >= 0; i--){
        m++;
        sum += (ll) arr[i];
        if(m >= k){
            ksum[i] = sum;
            sum -= arr[i+k-1];
        }
    }

    ll Max = 0;
    for(int i = n - k; i >= 0; i--){
        if(ksum[i] >= Max){
            Max = ksum[i];
            maxSum[i].ff = Max;
            maxSum[i].ss = i;
        }
        else{
            maxSum[i].ff = maxSum[i+1].ff;
            maxSum[i].ss = maxSum[i+1].ss;
        }
    }

    Max = 0;
    int a, b;
    for(int i = 0; i < n - k; i++){
        ll res = (ll) ksum[i] + maxSum[i+k].ff;
        if(res > Max){
            Max = res;
            a = i;
            b = maxSum[i+k].ss;
        }
    }

    cout<<a + 1<<" "<<b + 1<<endl;

    return 0;
}
