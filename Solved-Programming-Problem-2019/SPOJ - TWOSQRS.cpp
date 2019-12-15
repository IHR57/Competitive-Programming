//Date: 22/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mask, int pos) { return (bool) (mask & (1<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

vector<ll> sq;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    for(int i = 0; i <= 1000000; i++){
        sq.pb(1LL*i*i);
    }

    int test;
    ll n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        bool flag = false;
        for(int i = 0; i < sq.size(); i++){
            if(binary_search(sq.begin(), sq.end(), n - sq[i])){
                printf("Yes\n");
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("No\n");
        }
    }

    return 0;
}