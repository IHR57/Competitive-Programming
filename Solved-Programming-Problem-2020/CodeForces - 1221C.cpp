//Date: 03/01/20
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
#define MAX 1005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

multiset<string> ms;
int dp[1505];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int test, c, m, x;

    cin>>test;

    while(test--){
        cin>>c>>m>>x;
        int temp = min(c, m);
        x += max(c, m) - temp;
        if(x >= temp){
            cout<<temp<<endl;
        }
        else{
            int t = (temp - x) / 3;
            if((temp - x) % 3 != 0)
                t++;
            cout<<temp - t<<endl;
        }
    }

    return 0;
}