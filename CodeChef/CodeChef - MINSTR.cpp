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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, n;
    string str;

    cin>>test;

    while(test--){
        cin>>n;
        map<string, int> mp;
        for(int i = 0; i < n; i++){
            cin>>str;
            mp[str]++;
        }
        int ans = 0;
        if(mp["aa"] || mp["a"])
            ans++;
        if(mp["bb"] || mp["b"])
            ans++;
        if(mp["ab"] || mp["ba"])
            ans = 0;
        ans += 2 * (mp["ab"] + mp["ba"]) - 2 * min(mp["ab"], mp["ba"]);
        if(mp["ab"] == mp["ba"] && mp["ab"] > 0){
            ans += 1;
        }

        cout<<ans<<endl;
    }

    return 0;
}
