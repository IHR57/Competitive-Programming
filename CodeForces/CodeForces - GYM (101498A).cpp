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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int temp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, f, n;
    string str;

    cin>>test;

    while(test--){
        cin>>n;

        multiset<string> s[10005];
        map<int, int> MP;
        int idx = 1;
        for(int i = 0; i < n; i++){
            cin>>str>>f;
            if(MP[f] == 0){
                temp[idx] = f;
                MP[f] = idx++;
            }
            s[MP[f]].insert(str);
        }

        int ans = 1e8, MX = 0;
        for(int i = 1; i < idx; i++){
            if(s[i].size() >= MX){
                if(s[i].size() == MX){
                    ans = min(ans, temp[i]);
                    continue;
                }
                MX = s[i].size();
                ans = temp[i];
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
