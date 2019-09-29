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

int a[105], b[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;
    int n;

    cin>>n;
    cin>>str;

    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i];
    }

    int ans = 0;
    for(int i = 0; i <= 10000; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(i < b[j])
                sum += (str[j] - 48);
            else
                sum += (((i - b[j]) / a[j]) & 1) ? (str[j] - 48) : !(str[j] - 48);
        }

        ans = max(ans, sum);
    }

    cout<<ans<<endl;

    return 0;
}
