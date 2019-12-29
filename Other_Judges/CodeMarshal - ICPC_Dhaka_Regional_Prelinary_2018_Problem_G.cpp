//Problem ID: ACM ICPC Dhaka Regional Preliminary 2018 (Problem G)
//Programmer: IQBAL HOSSSAIN    Description: Number Theory/Brute Force
//Date: 13/09/19
//Problem Link: https://algo.codemarshal.org/contests/icpc-dhaka-preli-18/problems/G
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

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, q, k;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &k);
        int g = 0;
        bool flag = false;
        for(int j = 0; j < n; j++){
            if(arr[j] % k == 0){
                g = __gcd(g, arr[j] / k);
                if(g == 1){
                    flag = true;
                    break;
                }
            }
        }
        (flag) ? printf("Y\n") : printf("N\n");
    }

    return 0;
}
