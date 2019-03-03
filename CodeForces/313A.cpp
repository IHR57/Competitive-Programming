#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    if(n > 0){
        cout<<n<<endl;
        return 0;
    }

    n = -n;
    int r = n % 10;
    int temp1 = n / 10;
    int temp2 = (n / 100) * 10 + r;
    int ans = min(temp1, temp2);
    //cout<<temp1<<" "<<temp2<<endl;

    cout<<-ans<<endl;

    return 0;
}

