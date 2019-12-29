//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;
int odd[(1<<21)], even[(1<<21)];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int xorSum = 0, n, val;

    cin>>n;

    ll sum = 0;
    even[0] = 1;
    for(int i = 1; i <= n; i++){
        cin>>val;
        xorSum = xorSum ^ val;
        if(i % 2 == 0){
            sum += (ll) even[xorSum];
            even[xorSum]++;
        }
        else{
            sum += (ll) odd[xorSum];
            odd[xorSum]++;
        }
    }

    cout<<sum<<endl;

    return 0;
}
