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
#define MAX 205
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<string> vs;
string temp;
int ans[MAX], vis[MAX];

bool check(string s)
{
	memset(ans, -1, sizeof(ans));
	int n = s.size();
	for(int i = 0; i < vs.size(); i++){
		int len = vs[i].size();
		if(s.substr(0, len) == vs[i] && s.substr(n - len, len) == vs[i]){
			ans[i] = 2;
		}
		else if(s.substr(n - len, len) == vs[i]){
			ans[i] = 1;
		}
		else if(s.substr(0, len) == vs[i]){
			ans[i] = 0;
		}
		else{
			return false;
		}
	}

	return true;
}


void printAns()
{
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < vs.size(); i++){
		if(ans[i] == 0)
			cnt0++;
		else if(ans[i] == 1)
			cnt1++;
	}
	int n = vs.size();
	int cnt2 = n - cnt0 - cnt1;
	if(cnt2){
		for(int i = 0; i < n; i++){
			int len = vs[i].size();
			if(ans[i] == 2){
				if(cnt0 < (n / 2) && !vis[len]){
					ans[i] = 0;
					cnt0++;
					vis[len] = 1;
				}
				else if(cnt1 < (n / 2)){
					ans[i] = 1;
					cnt1++;
				}
			}
		}
	}
	for(int i = 0; i < vs.size(); i++){
		(ans[i]) ? cout<<"S" : cout<<"P";
	}
	cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n;
    vector<string> v1;
    string str;

    cin>>n;

    for(int i = 0; i < 2 * n - 2; i++){
    	cin>>str;
    	vs.pb(str);
    	if(str.size() == 1)
    		v1.pb(str);
    	if(str.size() == n - 1)
    		temp = str;
    }

    if(check(temp + v1[0])){
    	printAns();
    	return 0;
    }
    if(check(temp + v1[1])){
    	printAns();
    	return 0;
    }
    if(check(v1[0] + temp)){
    	printAns();
    	return 0;
    }
    if(check(v1[1] + temp)){
    	printAns();
    	return 0;
    }

    return 0;
}
