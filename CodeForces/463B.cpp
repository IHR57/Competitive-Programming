#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int value, n, Max = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>value;
        Max = (value > Max) ? value : Max;
    }

    cout<<Max<<endl;

    return 0;
}
