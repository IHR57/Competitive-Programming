//Date: 20/01/20
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
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string str, res = "";

    int n;
    cin>>n;
    cin>>str;

    int l = 0, r = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '('){
            l++;
            if(l & 1)
                res += "0";
            else
                res += "1";
        }
        else{
            r++;
            if(r & 1)
                res += "0";
            else
                res += "1";
        }
    }

    cout<<res<<endl;

    return 0;
}