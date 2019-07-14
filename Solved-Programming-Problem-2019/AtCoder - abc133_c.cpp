#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, r;

    cin>>l>>r;

    if((l / 2019) != (r / 2019)){
        cout<<0<<endl;
        return 0;
    }
    l %= 2019, r %= 2019;

    int ans = 2e9;
    for(int i = l; i < r; i++){
        for(int j = l + 1; j <= r; j++){
            int temp = (i * j) % 2019;
            ans = min(ans, temp);
        }
    }

    cout<<ans % 2019<<endl;

    return 0;
}

