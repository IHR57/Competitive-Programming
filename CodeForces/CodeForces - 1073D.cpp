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

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n;

ll totalMoney, arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    ll Mn = 1e9 + 7;
    cin>>n>>totalMoney;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        Mn = min(Mn, arr[i]);
    }

    ll res = 0;
    while(totalMoney >= Mn){
        int cnt = 0;
        ll sum = 0;
        ll temp = totalMoney;
        for(int i = 1; i <= n; i++){
            if(arr[i] <= totalMoney){
                sum += arr[i];
                totalMoney -= arr[i];
                cnt++;
            }
        }
        res += (1LL * cnt * (temp / sum));
        totalMoney %= sum;
    }

    cout<<res<<endl;

    return 0;
}
