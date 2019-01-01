#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, w;

    cin>>k>>n>>w;

    int temp = (w * (w + 1)) / 2;
    temp = temp * k;

    if((temp - n) >= 0){
        cout<<temp - n<<endl;
    }
    else
        cout<<0<<endl;

    return 0;
}
