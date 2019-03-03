#include <bits/stdc++.h>
#define MAX 100005
#define EPS 1e-8
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    double value;

    cin>>n;

    double sum = 0;
    for(int i = 1; i <= n; i++){
        cin>>value;
        sum += value;
    }

    double ans = sum / (n * 100);

    cout<<setiosflags(ios::fixed)<<setprecision(8);
    cout<<ans * 100.0 + EPS<<endl;

    return 0;
}
