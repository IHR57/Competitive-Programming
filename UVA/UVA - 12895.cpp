/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
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

ll Pow(ll a, ll b)
{
    ll ans = 1;
    for(int i = 1; i <= b; i++){
        ans *= a;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test;
    ll n;

    cin>>test;

    while(test--){
        cin>>n;
        for(int i = 0; ; i++){
            ll temp = n, sum = 0;
            bool flag = true;
            while(temp){
                sum += Pow((ll)(temp % 10), (ll) i);
                if(sum > n){
                    flag = false;
                    break;
                }
                temp /= 10;
            }
            if(!flag){
                cout<<"Not Armstrong"<<endl;
                break;
            }
            if(sum == n){
                cout<<"Armstrong"<<endl;
                break;
            }
        }
    }

    return 0;
}
