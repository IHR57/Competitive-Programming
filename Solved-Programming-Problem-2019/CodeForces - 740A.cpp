#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, a, b, c;

    cin>>n>>a>>b>>c;

    ll rem = 4 - (n % 4);
    if(rem == 4){
        cout<<0<<endl;
        return 0;
    }

    ll ans = 1e18;
    for(int i = 0; i <= 50; i++){
        for(int j = 0; j <= 50; j++){
            for(int k = 0; k <= 50; k++){
                int temp = i * 1 + j * 2 + k * 3;
                if((n + temp) % 4 == 0){
                    ans = min(ans, i * a + j * b + k * c);
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
