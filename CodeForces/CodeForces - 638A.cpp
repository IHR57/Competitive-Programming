#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, ans;

    cin>>n>>k;

    n /= 2;
    if(k % 2 == 0){
        ans = (k - 1) / 2;
        ans = n - ans;
    }
    else{
        ans = (k + 1) / 2;
    }

    cout<<ans<<endl;

    return 0;
}
