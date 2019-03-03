#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c;

    cin>>a>>b>>c;

    int ans;
    if(a == 1 && b == 1 && c == 1)
        ans = 3;
    else if(a == 1 && c == 1){
        ans = a + b + c;
    }
    else if(a == 1 && b == 1){
        ans = (a + b) * c;
    }
    else if(b == 1 && c == 1){
        ans = (b + c) * a;
    }
    else if(a == 1){
        ans = (a + b) * c;
    }
    else if(b == 1)
        ans = max((a + b) * c, (b + c) * a);
    else if(c == 1)
        ans = (b + c) * a;
    else
        ans = a * b * c;

    cout<<ans<<endl;

    return 0;
}
