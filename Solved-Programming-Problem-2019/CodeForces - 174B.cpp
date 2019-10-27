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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> dot;
vector<string> vs;

string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    cin>>str;

    int n = str.size();
    for(int i = 0; i < n; i++){
        if(str[i] == '.')
            dot.pb(i);
    }

    if(dot.empty() || dot[0] > 8 || (n - dot.back() - 1) > 3){
        cout<<"NO"<<endl;
        return 0;
    }
    if(dot[0] == 0 || dot.back() == n - 1){
        cout<<"NO"<<endl;
        return 0;
    }

    int k = 0;
    for(int i = 0; i < dot.size() - 1; i++){
        if(dot[i+1] - dot[i] <= 2){
            cout<<"NO"<<endl;
            return 0;
        }
        if(dot[i+1] - dot[i] > 12){
            cout<<"NO"<<endl;
            return 0;
        }
        int x = dot[i+1] - dot[i];
        if(x > 9){
            int temp = x - 9;
            vs.pb(str.substr(k, dot[i] - k + temp + 1));
            k = dot[i] + temp + 1;
        }
        else{
            vs.pb(str.substr(k, dot[i] - k + 2));
            k = dot[i] + 2;
        }
    }
    cout<<"YES"<<endl;
    vs.pb(str.substr(k, n - k + 1));

    for(int i = 0; i < vs.size(); i++){
        cout<<vs[i]<<endl;
    }

    return 0;
}
