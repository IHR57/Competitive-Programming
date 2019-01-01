#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x[MAX], y[MAX], home[MAX] = {0};

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i];
        home[x[i]]++;
    }

    int h, a;
    for(int i = 0; i < n; i++){
        h = (n - 1) + home[y[i]];
        a = (2 * (n - 1)) - h;
        cout<<h<<" "<<a<<endl;
    }

    return 0;
}
