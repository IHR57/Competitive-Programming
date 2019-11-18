/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-16
#define MOD 1000000007
#define MAX 1005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

double ans[MAX];
ii arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, n;
    double k;

    scanf("%d", &test);

    while(test--){
        scanf("%d %lf", &n, &k);
        for(int i = 0; i < n; i++)
            ans[i] = 0.00;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i].ff);
            arr[i].ss = i;
        }

        sort(arr, arr + n);
        if(arr[n-1].ff < (int) k || arr[0].ff > (int) k){
            printf("-1\n");
            continue;
        }
        if(arr[0].ff == arr[n-1].ff){
            for(int i = 0; i < n; i++){
                ans[i] = 1.0 / (double) n;
                printf("%0.16lf\n", ans[i]);
            }
            continue;
        }

        double low = 0.0, high = 1.0, mid;
        double a = (double) arr[0].ff, b = (double) arr[n-1].ff;

        for(int i = 0; i < 500; i++){
            mid = (low + high) / 2.0;
            double temp = a * mid + b * (1.0 - mid);
            if(temp - k > EPS)
                low = mid;
            else
                high = mid;
        }

        ans[arr[0].ss] = mid, ans[arr[n-1].ss] = 1 - mid;

        for(int i = 0; i < n; i++)
            printf("%0.16lf ", ans[i]);

    }

    return 0;
}
