//Date: 24/09/19
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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int low = 1, high = 1e4, mid, ans;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            if((mid * (mid + 1)) / 2 >= n){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        int res;
        if(ans & 1){
            res = ans - (((ans * (ans + 1)) / 2) - n)-1;
        }
        else
            res = ((ans * (ans + 1)) / 2) - n;
        printf("TERM %d IS %d/%d\n", n, ans - res, (ans + 1) - (ans - res));
    }

    return 0;
}