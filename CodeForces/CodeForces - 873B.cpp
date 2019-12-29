#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[MAX];
    int n;

    cin>>n;
    cin>>str;

    int a = 0, b = 0, ans = 0;
    map<int, int> mp;
    mp[0] = -1;

    for(int i = 0; i < n; i++){
        if(str[i] == '1')
            a++;
        else
            b++;
        if(mp.count(a - b)){
            ans = max(ans, i - mp[a-b]);
        }
        else{
            mp[a-b] = i;
        }
    }

    cout<<ans<<endl;

    return 0;
}
