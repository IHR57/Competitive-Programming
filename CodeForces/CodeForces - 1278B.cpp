//Date: 10/03/2020
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
#define MAX 1005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

    vector<int> v;
    int cs = 0;

    v.pb(cs);
    for(int i = 1; ; i++){
        cs += i;
        v.pb(cs);
        if(cs > 2e9)
            break;
    }

    int test;

    cin>>test;

    while(test--){
        int a, b;

        cin>>a>>b;

        if(a > b)
            swap(a, b);

        int diff = b - a;
        if(diff == 0){
            cout<<0<<endl;
            continue;
        }

        for(int i = 1; i < v.size(); i++){
            if(v[i] >= diff){
                if(diff % 2  == v[i] % 2){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}
