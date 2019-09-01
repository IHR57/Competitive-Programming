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
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll hashes[MAX];
string str;

vector<int> prefix_function(string s)
{
    int n = str.size();
    vector<int> pn(n, 0);
    for(int i = 1; i < n; i++){
        int j = pn[i-1];
        while(j > 0 && s[i] != s[j])
            j = pn[j-1];
        if(s[i] == s[j])
            j++;
        pn[i] = j;
    }

    return pn;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin>>str;
    int n = str.size();
    
    vector<int> p = prefix_function(str);
    int Max = 0;
    if(p[n-1] == 0){
        cout<<"Just a legend"<<endl;
        return 0;
    }
    for(int i = 1; i < n - 1; i++){
        if(p[i] >= p[n-1]){
            cout<<str.substr(0, p[n-1])<<endl;
            return 0;
        }
    }
    if(p[p[n-1]-1] == 0){
        cout<<"Just a legend"<<endl;
        return 0;
    }
    cout<<str.substr(0, p[p[n-1]-1]);
    /*
    p[0] = 1;
    for(int i = 1; i < n; i++)
        p[i] = (p[i-1] * 31) % MOD;

    hashes[0] = 0;
    for(int i = 0; i < n; i++){
        hashes[i+1] = (hashes[i] + ((str[i]-'a'+1) * p[i]) % MOD) % MOD;
    }
    int low = 1, high = n - 2, mid, ans = -1;
    while(low <= high){
        mid = (low + high + 1) >> 1;
        ll h1 = (hashes[mid]);
        ll h2 = (hashes[n] + MOD - hashes[n-mid]) % MOD;
        h2 = (h2 * powMod(p[n-mid], MOD - 2)) % MOD;
        bool flag = false;
        if(h1 == h2){
            for(int i = 1; i <= n - mid - 2; i++){
                ll temp = (hashes[i+mid-1] + MOD - hashes[i-1]) % MOD;
                temp = (temp * p[i]) % MOD;
                if(temp == h1){
                    flag = true;
                    break;
                }
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
    */

    return 0;
}
