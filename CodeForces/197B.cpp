#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a[MAX], b[MAX];

    cin>>n>>m;

    for(int i = 0; i <= n; i++)
        cin>>a[i];
    for(int j = 0; j <= m; j++)
        cin>>b[j];

    if(n > m){
        if((a[0] > 0 && b[0] > 0) || (a[0] <= 0 && b[0] <= 0))
            cout<<"Infinity"<<endl;
        else
            cout<<"-Infinity"<<endl;
    }
    else if(m > n){
        cout<<"0/1"<<endl;
    }
    else{
        int ta, tb;
        (a[0] < 0) ? ta = -a[0] : ta = a[0];
        (b[0] < 0) ? tb = -b[0] : tb = b[0];
        int g = __gcd(ta, tb);

        if((a[0] < 0 && b[0] > 0) || (a[0] > 0 && b[0] < 0)){
            cout<<"-"<<ta/g<<"/"<<tb/g<<endl;
        }
        else{
            cout<<ta/g<<"/"<<tb/g<<endl;
        }
    }

    return 0;
}
