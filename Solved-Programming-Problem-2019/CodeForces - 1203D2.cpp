/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Date: 19/08/19
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

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string s, t;
int cs[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin>>s>>t;
    int k = 0;
    for(int i = 1; i <= s.size(); i++){
        if(k >= t.size()){
            cs[i][0] = cs[i-1][0];
            continue;
        }
        if(s[i-1] == t[k]){
            cs[i][0] = cs[i-1][0] + 1;
            k++;
        }
        else{
            cs[i][0] = cs[i-1][0];
        }
    }
    k = t.size() - 1;
    for(int i = s.size(); i >= 1; i--){
        if(k < 0){
            cs[i][1] = cs[i+1][1];
            continue;
        }
        if(s[i-1] == t[k]){
            cs[i][1] = cs[i+1][1] + 1;
            k--;
        }
        else{
            cs[i][1] = cs[i+1][1];
        }

    }

    int low = 0, high = s.size(), mid, ans;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        bool flag = false;
        for(int i = 1; i <= s.size() - mid + 1; i++){
            if(cs[i-1][0] + cs[i+mid][1] >= t.size()){
                flag = true;
                break;
            }
        }
        if(flag){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
