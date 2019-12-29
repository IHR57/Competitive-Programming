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
#define MAX 1000005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], dp[MAX], n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    cin>>n;

    int m;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        dp[arr[i]] = 1;
        m = arr[i];
    }


    for(int i = 0; i <= m; i++){
        if(dp[i] != 0){
            for(int j = 2 * i; j <= m; j += i){
                if(dp[j] != 0){
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
    }   

    cout<<*max_element(dp, dp + m + 1)<<endl; 

    return 0;
}
