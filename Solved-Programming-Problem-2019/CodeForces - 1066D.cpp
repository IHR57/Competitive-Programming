//Date: 18/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 998244353
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mask, int pos) { return (bool) (mask & (1<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;

    cin>>n>>m>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    reverse(arr, arr + n);

    int x = 0;
    for(int i = 0; i < n; i++){
        if(x - arr[i] < 0){
            if(m == 0){
                cout<<i<<endl;
                return 0;
            }
            else{
                x = k - arr[i];
                m--;
            }
        }
        else{
            x -= arr[i];
        }
    }

    cout<<n<<endl;

    return 0;
}