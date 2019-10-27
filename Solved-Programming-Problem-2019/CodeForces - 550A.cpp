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

vector<int> v[2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    string str;

    cin>>str;

    int n = str.size();

    string temp = "";
    temp += str[0];
    for(int i = 1; i < n; i++){
        temp += str[i];
        if(temp == "AB")
            v[0].pb(i-1);
        else if(temp == "BA")
            v[1].pb(i-1);
        temp = str[i];
    }
    if(v[0].empty() || v[1].empty()){
        cout<<"NO"<<endl;
        return 0;
    }

    int dist = v[1][v[1].size()-1] - v[0][0];
    if(dist >= 2){
        cout<<"YES"<<endl;
        return 0;
    }
    dist = v[0][v[0].size()-1] - v[1][0];
    if(dist >= 2){
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;

    return 0;
}
