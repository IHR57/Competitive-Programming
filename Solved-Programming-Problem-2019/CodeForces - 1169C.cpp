#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
#define debug (printf("PINK FLOYD:)\n"))
#define iosflags (cout<<setiosflags(ios::fixed)<<setprecision(8))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], n, m;

bool ok(int val)
{
	int prev = 0, k;
	for(int i = 0; i < n; i++){
		if(arr[i] >= prev){
			k = m - (arr[i] - prev);
			if(k > val){
				prev = arr[i];
			}
		}
		else{
			k = prev - arr[i];
			if(k > val)
				return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

	cin>>n>>m;

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}	

	int low = 0, high = m, mid, ans;

	while(low <= high){
		mid = (low + high + 1) >> 1;
		if(ok(mid)){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	cout<<ans<<endl;

    return 0;
}