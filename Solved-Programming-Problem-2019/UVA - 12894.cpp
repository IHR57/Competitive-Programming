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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int x1, x2, y1, y2, cx, cy, r, test;

    cin>>test;

    while(test--){
        cin>>x1>>y1>>x2>>y2>>cx>>cy>>r;
        if(r * 5 != (x2 - x1)){
            cout<<"NO"<<endl;
            continue;
        }
        if((x2 - x1) * 6 != (y2 - y1) * 10){
            cout<<"NO"<<endl;
            continue;
        }
        if((x2 - x1) * 9 % 20 != 0){
            cout<<"NO"<<endl;
            continue;
        }
        if(x1 + ((x2 - x1) * 9) / 20 != cx){
            cout<<"NO"<<endl;
            continue;
        }
        if((y1 + y2) % 2){
            cout<<"NO"<<endl;
            continue;
        }
        if((y1 + y2) / 2 != cy){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}
