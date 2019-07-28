/*
Template for vjudge contest
	CodeForces ID: The_Silent_Man
	LightOJ ID: 29578
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
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, m, q;
vector<ii> vp;
ii arr[MAX];
int bit[MAX], ans[MAX], temp[MAX];

struct Query
{
	int u, v, x, idx;
	Query(int a, int b, int c, int d)
	{
		u = a, v = b, x = c, idx = d;
	}
};
vector<Query> query;

void update(int idx, int val)
{	
	while(idx <= m){
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

int getValue(int idx)
{
	int sum = 0;
	while(idx > 0){
		sum += bit[idx];
		idx -= (idx & -idx);
	}

	//cout<<"debug"<<endl;
	return sum;
}
bool compare(Query q1, Query q2)
{
	return q1.x < q2.x;
}

bool comp(ii a, ii b)
{
	return a.ss < b.ss;
}


void solve()
{
	//cout<<"I came Here"<<endl;
	int curr = 0;
	for(int i = 0; i < q; i++){
		while(arr[curr].ss <= query[i].x){
			if(arr[curr].ss > query[i].x || curr >= m)
				break;
			update(arr[curr].ff + 1, 1);
			curr++;
		}
		ans[query[i].idx] = getValue(query[i].v + 1) - getValue(query[i].u); 
	}
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin>>n>>m>>q;

    int l, r;
    for(int i = 0; i < m; i++){
    	cin>>l>>r;
    	vp.pb(mp(l, r));
    }

    sort(vp.begin(), vp.end());


    for(int i = 0; i < vp.size(); i++){
    	arr[i].ff = i;
    	arr[i].ss = vp[i].ss;
 		temp[i] = vp[i].ff;
    }

    for(int i = 0; i < q; i++){
    	cin>>l>>r;
    	int lidx = lower_bound(temp, temp + m, l) - temp;
    	int ridx = upper_bound(temp, temp + m, r) - temp;
    	query.pb(Query(lidx, ridx - 1, r, i));
    	//cout<<lidx<<" "<<ridx<<" "<<r<<endl;
    }

    sort(query.begin(),  query.end(), compare);
    sort(arr, arr + m, comp);

    solve();

    for(int i = 0; i < q; i++){
    	cout<<ans[i]<<endl;
    }

    return 0;
}
