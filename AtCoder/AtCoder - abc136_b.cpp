#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;

int lg(int n)
{
    int cnt = 0;
    while(n){
        n /= 10;
        cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(lg(i) % 2){
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}

