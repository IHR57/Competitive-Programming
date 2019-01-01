// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    int k = n % 10;

    if(k == 0)
        cout<<n<<endl;
    else if(k <= 5){
        cout<<n-k<<endl;
    }
    else if(k > 5)
        cout<<n+(10-k)<<endl;

    return 0;
}
