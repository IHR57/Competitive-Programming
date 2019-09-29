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
    int test, a, b, caseno = 1;

    cin>>test;

    while(test--){
        cin>>a>>b;
        cout<<"Case "<<caseno++<<": ";
        if(a == 0 && b == 0){
            cout<<"0.000"<<" "<<"0.000"<<endl;
        }
        else if(a == 0 && b != 0){
            if(b & 1){
                cout<<"0.000"<<" "<<"1.000"<<endl;
            }
            else
                cout<<"1.000"<<" "<<"0.000"<<endl;
        }
        else if(a != 0 && b == 0){
            cout<<"1.000"<<" "<<"0.000"<<endl;
        }
        else if(b & 1){
            cout<<"0.000"<<" "<<"1.000"<<endl;
        }
        else
            cout<<"1.000"<<" "<<"0.000"<<endl;
    }

    return 0;
}
