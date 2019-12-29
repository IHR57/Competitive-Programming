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

int arr[105];

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
        cin>>arr[i];
    }

    int ans = 0;
    for(int i = 1; i < n; i++){
        if((arr[i] == 2 && arr[i-1] == 3) || (arr[i] == 3 && arr[i-1] == 2)){
            cout<<"Infinite"<<endl;
            return 0;
        }
        if((arr[i] == 1 && arr[i-1] == 2) || (arr[i] == 2 && arr[i-1] == 1))
            ans += 3;
        if((arr[i] == 1 && arr[i-1] == 3) || (arr[i] == 3 && arr[i-1] == 1)){
            ans += 4;
        }
        if(i >= 2){
            if(arr[i] == 2 && arr[i-1] == 1 && arr[i-2] == 3)
                ans--;
        }
    }

    cout<<"Finite"<<endl;
    cout<<ans<<endl;


    return 0;
}
