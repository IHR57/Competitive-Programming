/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Date: 10/09/19
//Category: Implementation
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
#define MAX 1005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

priority_queue<ii> pq;
int cell[MAX][MAX], freq[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, val;

    cin>>n;

    for(int i = 0; i < (n * n); i++){
    	cin>>val;
    	freq[val]++;
    }

    for(int i = 1; i <= 1000; i++){
    	if(freq[i]){
    		pq.push(mk(freq[i], i));
    	}
    }

    for(int i = 1; i <= n / 2; i++){
		for(int j = 1; j <= n / 2; j++){
			ii u = pq.top();
			pq.pop();
			if(u.ff >= 4){
				cell[i][j] = cell[i][n-j+1] = cell[n-i+1][j] = cell[n-i+1][n-j+1] = u.ss;
				pq.push(mk(u.ff-4, u.ss));
			}
			else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
    if(n & 1){
    	int m = (n + 1) / 2;
    	for(int i = 1; i <= (n / 2); i++){
    		ii u = pq.top();
    		pq.pop();
    		if(u.ff >= 2){
    			cell[i][m] = cell[n-i+1][m] = u.ss;
    			pq.push(mk(u.ff-2, u.ss));
    		}
    		else{
    			cout<<"NO"<<endl;
    			return 0;
    		}
    		u = pq.top();
    		pq.pop();
    		if(u.ff >= 2){
    			cell[m][i] = cell[m][n-i+1] = u.ss;
    			pq.push(mk(u.ff-2, u.ss));
    		}
    		else{
    			cout<<"NO"<<endl;
    			return 0;
    		}
    	}
    	ii u = pq.top();
    	pq.pop();
    	cell[m][m] = u.ss;
    }

    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cout<<cell[i][j]<<" ";
    	}
    	cout<<endl;
    }


    return 0;
}
