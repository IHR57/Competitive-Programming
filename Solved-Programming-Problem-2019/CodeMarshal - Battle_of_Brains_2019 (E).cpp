//Problem Link: https://algo.codemarshal.org/contests/bob19/problems/E
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define tan(a) tan(a*PI/180)
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    int caseno = 1, test;
    int n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        n = n - 2;
        ll a = (n / 2), b = (n + 1) / 2;
        ll Min = (a + b + 1);
        ll Max = (a * b) + (a + b);

        printf("Case %d: %lld %lld\n", caseno++, Min, Max);
    }

    return 0;
}
