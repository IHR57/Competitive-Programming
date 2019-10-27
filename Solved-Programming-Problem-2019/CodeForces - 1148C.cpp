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
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int pos[MAX], arr[MAX];
vector<ii> v;
int n;

void move(int i)
{
	v.pb(mk(pos[arr[i]], pos[i]));
	int t = pos[i], x = arr[i];
	swap(arr[pos[i]], arr[i]);
	pos[i] = i;
	pos[x] = t; 
}

void moveBackward(int i)
{
	v.pb(mk(pos[i], n));
	int t = pos[i], x = arr[n];
	swap(arr[pos[i]], arr[n]);
	pos[x] = pos[i];
	pos[i] = n;
}

void moveForward(int i)
{
	v.pb(mk(pos[i], 1));
	int t = pos[i], x = arr[1];
	swap(arr[pos[i]], arr[1]);
	pos[x] = pos[i];
	pos[i] = 1;
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    cin>>n;

    for(int i = 1; i <= n; i++){
    	cin>>arr[i];
    	pos[arr[i]] = i;
    }

    for(int i = 1; i <= n; i++){
    	if(arr[i] == i)
    		continue;
		if(abs(pos[arr[i]] - pos[i]) >= n / 2){
			move(i);
		}    	
		else{
			if(pos[i] - 1 >= (n / 2)){
				moveForward(i);
				if((i - pos[i]) >= n / 2)
					move(i);
				else{
					moveBackward(i);
					move(i);
				}
			}
			else{
				moveBackward(i);
				if(pos[i] - i >= n / 2){
					move(i);
				}
				else{
					moveForward(i);
					move(i);
				}
			}
		}
    }

    cout<<v.size()<<endl;
    for(int i = 0; i < v.size(); i++){
    	cout<<v[i].ff<<" "<<v[i].ss<<endl;
    }
    
    return 0;
}
