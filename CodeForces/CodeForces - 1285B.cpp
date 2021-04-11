#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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

ll arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, test;

    cin>>test;

    while(test--){
        cin>>n;

        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        bool flag = false;

        ll cs = 0;
        for(int i = 0; i < n; i++){
            cs += arr[i];
            if(cs <= 0){
                flag = true;
                break;
            }
        }
        cs = 0;
        for(int i = n - 1; i >= 0; i--){
            cs += arr[i];
            if(cs <= 0){
                flag = true;
                break;
            }
        }

        (flag) ? cout<<"NO"<<endl : cout<<"YES"<<endl;


    }

    return 0;
}
