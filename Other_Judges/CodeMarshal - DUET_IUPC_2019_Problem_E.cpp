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
    int test, x, y, z, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &x, &y, &z);
        printf("Case %d: ", caseno++);
        if(x < y && x < z){
            printf("Possible\n");
        }
        else if(x % y == 0 || x % z == 0){
            printf("Impossible\n");
        }
        else{
            printf("Possible\n");
        }
    }

    return 0;
}