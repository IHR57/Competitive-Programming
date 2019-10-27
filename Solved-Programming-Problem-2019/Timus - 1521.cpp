//Date: 22/10/19
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
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
#define all(a) a.begin(), a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<int, int> ii;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    orderedSet;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    orderedSet os;
	orderedSet :: iterator it;
	
	int n, k;
	
	cin>>n>>k;
	
	for(int i = 1; i <= n; i++)
		os.insert(i);
	
	int cur = 0;
	
	while(n){
		cur = (cur + k - 1) % n;
		it = os.find_by_order(cur);
		cout<<*it<<" ";
		os.erase(*it);
		n--;
	}
	cout<<endl;

    return 0;
}
