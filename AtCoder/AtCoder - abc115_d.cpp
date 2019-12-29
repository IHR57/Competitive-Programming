#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
ll pat[55], total[55];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;
    ll x;
    pat[0] = total[0] = 1;
    for(int i = 1; i <= 50; i++){
        total[i] = total[i-1] * 2 + 3;
        pat[i] = pat[i-1] * 2 + 1;
    }

    cin>>n>>x;

    ll res = 0;
    for(int i = n; i >= 0; i--){
        if(x == 0)
            break;
        if(x == total[i]){
            res += pat[i];
            break;
        }
        if(x == 1)
            break;
        if(i){
            if(x <= 1 + total[i-1]){
                x--;
            }
            else{
                res += pat[i-1] + 1;
                x -= total[i-1] + 2;
            }
        }
    }

    cout<<res<<endl;

    return 0;
}