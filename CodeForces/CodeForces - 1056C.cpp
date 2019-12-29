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
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, m, p[2010], par[MAX], mark[MAX];
set<ii> s;
vector<int> vp;
set<int> ps;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int x;
    cin>>n>>m;

    for(int i = 1; i <= 2 * n; i++){
    	cin>>p[i];
    }

    for(int i = 0; i < m; i++){
    	int u, v;
    	cin>>u>>v;
    	par[u] = v;
    	par[v] = u;
    	mark[u] = mark[v] = 1;
    	if(p[u] >= p[v])
    		ps.insert(u);
    	else
    		ps.insert(v);
    }

    for(int i = 1; i <= 2 * n; i++){
    	if(!mark[i]){
    		s.insert(mk(p[i], i));
    	}
    }

    cin>>x;

    int k = 0;
    set<ii> :: iterator it;

    if(x == 1){
    	for(int i = 0; i < n; i++){
	    	if(!ps.empty()){
	    		cout<<*ps.begin()<<endl;
	    		cout.flush();
	    		ps.erase(*ps.begin());
	    	}
	    	else{
	    		cout<<s.rbegin()->ss<<endl;
	    		cout.flush();
	    		s.erase(*s.rbegin());
	    	}
	    	int t;
	    	cin>>t;
	    	if(!mark[t]){
	    		s.erase(mk(p[t], t));
	    	}
	    }
    }
    else{
    	bool flag = false;
    	for(int i = 0; i < n; i++){
    		int t;
    		cin>>t;
    		if(mark[t] == 1 && flag){
    			if(!ps.empty()){
    				cout<<*ps.begin()<<endl;
    				cout.flush();
    				ps.erase(*ps.begin());
    				flag = true;
    			}
    			else{
    				cout<<s.rbegin()->ss<<endl;
    				cout.flush();
    				s.erase(*s.rbegin());
    				flag = false;
    			}
    		}
    		else if(mark[t] == 1 && !flag){
    			if(ps.count(t))
    				ps.erase(t);
    			else if(ps.count(par[t]))
    				ps.erase(par[t]);
    			cout<<par[t]<<endl;
    			cout.flush();
    			flag = false;
    		}
    		else{
    			s.erase(mk(p[t], t));
    			if(!ps.empty()){
    				cout<<*ps.begin()<<endl;
    				cout.flush();
    				flag = true;
    				ps.erase(*ps.begin());
    			}
    			else{
    				cout<<s.rbegin()->ss<<endl;
    				cout.flush();
    				s.erase(*s.rbegin());
    				flag = false;
    			}
    		}
    	}
    }

    return 0;
}
