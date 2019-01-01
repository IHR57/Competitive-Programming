#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    int x, y, sum1 = 0, sum2 = 0, diff = 0;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        sum1 += x, sum2 += y;
        if((x % 2 == 0 && y % 2 != 0) || (x % 2 != 0 && y % 2 == 0))
            diff = 1;
    }

    int temp1 = sum1 % 2, temp2 = sum2 % 2;
    if(temp1 == 0 && temp2 == 0)
        cout<<0<<endl;
    else if(temp1 == 1 && temp2 == 1){
        if(diff)
            cout<<1<<endl;
        else
            cout<<-1<<endl;
    }
    else
        cout<<-1<<endl;

    return 0;
}
