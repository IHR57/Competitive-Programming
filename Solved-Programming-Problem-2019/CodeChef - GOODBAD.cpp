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
    int test, n, k;
    string str;

    cin>>test;

    while(test--){
        cin>>n>>k;
        cin>>str;
        int cap = 0, sml = 0;
        for(int i = 0; i < n; i++){
            if(str[i] >= 'a' && str[i] <= 'z')
                sml++;
        }
         cap = n - sml;
        if(cap <= k && sml <= k){
            cout<<"both"<<endl;
        }
        else if(cap <= k){
            cout<<"chef"<<endl;
        }
        else if(sml <= k){
            cout<<"brother"<<endl;
        }
        else{
            cout<<"none"<<endl;
        }
    }

    return 0;
}
