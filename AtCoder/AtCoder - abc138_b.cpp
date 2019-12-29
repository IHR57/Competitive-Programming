#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    double arr[105];

    cin>>n;
    double sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += (1 / arr[i]);
    }

    double res = 1 / sum;
    cout<<setiosflags(ios::fixed)<<setprecision(10);
    cout<<res<<endl;

    return 0;
}

