#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    if(n % 2 != 0){
        cout<<-1<<endl;
        return 0;
    }

    for(int i = 1; i <= n; i++){
        if(i % 2 != 0)
            cout<<i+1<<" ";
        else
            cout<<i-1<<" ";
    }
    cout<<endl;

    return 0;
}
