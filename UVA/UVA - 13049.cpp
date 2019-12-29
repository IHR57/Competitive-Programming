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
    int test, caseno = 1, n;
    string s, t;

    cin>>test;

    while(test--){
        cin>>n>>s>>t;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int x = s[i] - 48, y = t[i] - 48;
            int t = abs(x - y);
            cnt += min(t, 10 - t);
        }
        cout<<"Case "<<caseno++<<": "<<cnt<<endl;
    }

    return 0;
}
