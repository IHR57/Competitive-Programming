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

vector<string> vs;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    vs.pb(" ");
    vs.pb(".,?\"");
    vs.pb("abc");
    vs.pb("def");
    vs.pb("ghi");
    vs.pb("jkl");
    vs.pb("mno");
    vs.pb("pqrs");
    vs.pb("tuv");
    vs.pb("wxyz");

    int n, test, x[205],  y[205];

    cin>>test;

    while(test--){
        cin>>n;
        string res = "";
        for(int i = 0; i < n; i++){
            cin>>x[i];
        }
        for(int i = 0; i < n; i++){
            cin>>y[i];
        }
        for(int i = 0; i < n; i++){
            res += vs[x[i]][y[i]-1];
        }

        cout<<res<<endl;
    }

    return 0;
}
