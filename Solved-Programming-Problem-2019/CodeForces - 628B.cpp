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

char str[3*MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%s", str);

    int n = strlen(str);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int x = str[i] - 48;
        if(x % 4 == 0)
            ans += 1;
        if(i - 1 >= 0 && (((str[i-1] - 48) * 10 + x) % 4 == 0)){
            ans += (ll) i;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
