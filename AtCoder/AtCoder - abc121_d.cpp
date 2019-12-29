#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    int test;

    ll l, r;
    ll ans1 = 0, ans2 = 0;

    cin>>l>>r;

    if(r % 4 == 0){
        ans1 = ans1 ^ r;
    }
    else if(r % 4 == 1)
        ans1 ^= 1;
    else if(r % 4 == 2)
        ans1 ^= (r + 1);
    else if(r % 4 == 3)
        ans1 = 0;

    l--;

    if(l % 4 == 0){
        ans2 = ans2 ^ l;
    }
    else if(l % 4 == 1)
        ans2 ^= 1;
    else if(l % 4 == 2)
        ans2 ^= (l + 1);
    else if(l % 4 == 3)
        ans2 = 0;

    cout<<(ans1 ^ ans2)<<endl;

    return 0;
}
