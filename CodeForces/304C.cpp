#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a[MAX], b[MAX], c[MAX];

    cin>>n;

    if(n % 2 == 0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        a[i] = b[i] = i;
        c[i] = (a[i] + b[i]) % n;
    }

    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;
    for(int i = 0; i < n; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++){
        cout<<c[i]<<" ";
    }

    cout<<endl;

    return 0;
}
