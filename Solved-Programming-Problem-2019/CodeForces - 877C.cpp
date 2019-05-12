//Problem ID: CodeForces - 877C (Slava and Tanks)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 12/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    int ans = n + (n / 2);

    cout<<ans<<endl;
    for(int i = 2; i <= n; i += 2)
        cout<<i<<" ";
    for(int i = 1; i <= n; i += 2)
        cout<<i<<" ";
    for(int i = 2; i <= n; i += 2)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
