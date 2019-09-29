//Date: 22/09/19
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
#define MAX 1000005
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cs[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;

    cin>>str;

    int n = str.size(), cap = 0;
    for(int i = 0; i < n; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            cap++;
    }

    int x = 0, ans = INF;
    for(int i = 0; i < n; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            x++;
        }
        ans = min(ans, i + 1 - x + cap - x);
    }
    ans = min(ans, cap);

    cout<<ans<<endl;

    return 0;
}