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
#define MAX 500005
using namespace std;

typedef long long ll;
typedef pair<int, char> ic;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<ic> dur, dul, ddr,ddl;		//diagonal-upper-right; diagonal-upper-left
vector<ic> hr, hl, vr, vl; 		//horizontal-left, horizontal-right, vertical-left, vertical-right

bool checkD(vector<ic> v)
{
	if(!v.empty()){
    	if(v[0].ss == 'Q' || v[0].ss == 'B'){
    		return true;
    	}
    }
    return false;
}

bool check(vector<ic> v)
{
	if(!v.empty()){
		if(v[0].ss == 'Q' || v[0].ss == 'R'){
			return true;
		}
	}
	return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, kx, ky, x, y;
    char ch;

    cin>>n;
    cin>>kx>>ky;

    for(int i = 0; i < n; i++){
    	cin>>ch>>x>>y;
    	if(x == kx){
    		if(y > ky)
    			hr.pb(mp(y, ch));
    		else
    			hl.pb(mp(y, ch));
    	}
    	else if(y == ky){
    		if(x > kx)
    			vr.pb(mp(x, ch));
    		else
    			vl.pb(mp(x, ch));
    	}
    	else if(abs(kx - x) == abs(ky - y)){
    		int tx = kx - x, ty = ky - y;
    		if(tx > 0 && ty < 0)
    			dur.pb(mp(abs(kx - x), ch));
    		else if(tx > 0 && ty > 0)
    			dul.pb(mp(abs(kx - x), ch));
    		else if(tx < 0 && ty < 0)
    			ddr.pb(mp(abs(kx - x), ch));
    		else
    			ddl.pb(mp(abs(kx - x), ch));
    	}
    }

    sort(vl.begin(), vl.end());
    reverse(vl.begin(), vl.end());
    sort(vr.begin(), vr.end());
    sort(hl.begin(), hl.end());
    reverse(hl.begin(), hl.end());
    sort(hr.begin(), hr.end());
    sort(dur.begin(), dur.end());
    sort(dul.begin(), dul.end());
    sort(ddr.begin(), ddr.end());
    sort(ddl.begin(), ddl.end());

    // for(int i = 0; i < hr.size(); i++){
    // 	cout<<hr[i].ff<<" "<<hr[i].ss<<endl;
    // }

    if(checkD(dur) || checkD(dul) || checkD(ddr) || checkD(ddl)){
    	cout<<"YES"<<endl;
    	return 0;
    }

    if(check(hl) || check(hr) || check(vl) || check(vr)){
    	cout<<"YES"<<endl;
    	return 0;
    }

    cout<<"NO"<<endl;

    return 0;
}
