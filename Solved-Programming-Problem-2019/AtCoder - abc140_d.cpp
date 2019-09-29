//Date: 14/09/19
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

typedef unsigned long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    string str;

    cin>>n>>k;
    cin>>str;

    int same = 0, diff = 0;
    for(int i = 0; i < str.size() - 1; i++){
        if(str[i] == str[i+1])
            same++;
        else
            diff++;
    }

    int ans = same + min(k * 2, diff);

    cout<<ans<<endl;
    

    return 0;
}
