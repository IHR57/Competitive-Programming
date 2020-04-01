//Date: 26/03/2020
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

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test;

    cin>>test;

    while(test--){
        int r, b, k;

        cin>>r>>b>>k;

        int g = __gcd(r, b);
        r /= g;
        b /= g;

        if(r > b)
            swap(r, b);

        if(1LL * r * (k - 1)  + 1 < b){
            cout<<"REBEL"<<endl;
        }
        else{
            cout<<"OBEY"<<endl;
        }
    }

    return 0;

}
