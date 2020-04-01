//Date: 19/03/2020
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
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}


int dp[MAX][2], a[MAX], b[MAX], n, c;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test, a, b, c;

    cin>>test;

    while(test--){
        cin>>a>>b>>c;
        if(a > c)
            swap(a, c);
        int arr[3] = {c/2, c - c/2, a};

        while(b){
            sort(arr, arr + 3);
            arr[0]++;
            b--;
        }

        cout<<max(arr[0], max(arr[1], arr[2]))<<endl;

    }

    return 0;

}
