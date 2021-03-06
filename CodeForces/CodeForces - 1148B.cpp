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

int flightA[MAX], flightB[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m, ta, tb, k;

    cin>>n>>m>>ta>>tb>>k;

    for(int i = 0; i < n; i++){
    	cin>>flightA[i];
    }
    for(int i = 0; i < m; i++)
    	cin>>flightB[i];

    if(k >= n || k >= m){
    	cout<<-1<<endl;
    	return 0;
    }

    int Max = 0;
    for(int i = k; i >= 0; i--){
    	int rem = k - i;
    	if(rem > m)
    		break;
    	int x = lower_bound(flightB, flightB + m, (flightA[i] + ta)) - flightB;
    	if(x >= m){
    		cout<<-1<<endl;
    		return 0;
    	}
    	else{
    		if(x + rem >= m){
    			cout<<-1<<endl;
    			return 0;
    		}
    		else{
    			x = x + rem;
    			Max = max(Max, flightB[x] + tb);
    		}
    	}
    }

    cout<<Max<<endl;

    return 0;
}
