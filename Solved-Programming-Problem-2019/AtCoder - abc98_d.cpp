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

int arr[MAX];

int cs[MAX][22];
ll dp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
    	cin>>arr[i];
    	for(int j = 0; j < 21; j++){
    		if(check(arr[i], j)){
    			cs[i][j] = cs[i-1][j] + 1;
    		}
    		else
    			cs[i][j] = cs[i-1][j];
    	}
    }

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
    	int low = 1, high = i, mid, ans;
    	while(low <= high){
    		mid = (low + high + 1) >> 1;
    		bool flag = true;
    		for(int j = 0; j < 21; j++){
    			if(cs[i][j] - cs[mid-1][j] >= 2){
    				flag = false;
    				break;
    			}
    		}
    		if(flag){
    			ans = mid;
    			high = mid - 1;
    		}
    		else{
    			low = mid + 1;
    		}
    	}
    	int t = (i - ans + 1);
    	dp[i] = dp[i-1] + t;
    }

    cout<<dp[n]<<endl;

    return 0;
}
