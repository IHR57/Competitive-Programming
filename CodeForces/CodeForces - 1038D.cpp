/*
Template for vjudge.net

    Author: Iqbal Hossain Rasel
    CodeForces: The_Silent_Man
    AtCoder   : IHR57
    TopCoder  : IHR57

*/
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
#define MAX 500005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll arr[MAX], sum = 0;
int n;


ll check()
{
    ll Max = 0;
    for(int i = 0; i < n - 1; i++){
        ll temp = sum;
        ll t = abs(abs(arr[i]) - abs(arr[i+1]));
        temp -= abs(arr[i]);
        temp -= abs(arr[i+1]);
        temp += t;
        Max = max(Max, temp);
    }

    return Max;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n;

    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] >= 0)
            pos++;
        else
            neg++;
        sum += abs(arr[i]);
    }
    if(n == 1){
        cout<<arr[0]<<endl;
        return 0;
    }

    if(pos > 0 && neg > 0){
        cout<<sum<<endl;
        return 0;
    }
    ll ans = check();

    cout<<ans<<endl;

    return 0;
}
