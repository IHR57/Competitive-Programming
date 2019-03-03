#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll a, b;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>a>>b;

    while(a > 0 && b > 0){
        if(a >= 2 * b)
            a %= (2 * b);
        else if(b >= 2 * a){
            b %= (2 * a);
        }
        else
            break;
    }

    cout<<a<<" "<<b<<endl;

    return 0;
}
