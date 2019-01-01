#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a1, a2, a3, a4, a5, a6;

    cin>>a1>>a2>>a3>>a4>>a5>>a6;

    int result = ((a1 + a2 + a3) * (a1 + a2 + a3)) - (a1 * a1 + a3 * a3 + a5 * a5);

    cout<<result<<endl;

    return 0;
}
