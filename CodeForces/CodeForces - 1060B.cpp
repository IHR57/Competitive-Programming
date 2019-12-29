//Date: 14/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<int> res;
int u;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, ans = 1;

    cin>>n;

    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            res.push_back(cnt);
            while((1 << u) < cnt){
                u++;
            }
            ans *= (1LL * i);
        }
    }

    for(int i = 0; i < res.size(); i++){
        if((1 << u) != res[i]){
            cout<<ans<<" "<<u + 1<<endl;
            return 0;
        }
    }
    cout<<ans<<" "<<u<<endl;

    return 0;
}
