#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        if(i % 4 == 0)
            cout<<"a";
        else if(i % 4 == 1)
            cout<<"b";
        else if(i % 4 == 2)
            cout<<"c";
        else if(i % 4 == 3)
            cout<<"d";
    }

    cout<<endl;

    return 0;
}
