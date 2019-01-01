#include <bits/stdc++.h>
#define MAX 255
using namespace std;

typedef long long ll;

string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>str;

    int len = (int) str.length();

    int st = 0;
    ll ans = 1;
    str += "#";
    for(int i = 1; i <= len; i++){
        int val = (str[i] - 48) + (str[i-1] - 48);
        if(val != 9){
            if((i - st) > 2  && (i - st) % 2 != 0){
                ans *= (ll) ((i - st + 1) / 2);
            }
            st = i;
        }
    }

    cout<<ans<<endl;

    return 0;
}
