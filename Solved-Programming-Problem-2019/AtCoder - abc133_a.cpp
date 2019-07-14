#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;

    cin>>n>>a>>b;

    cout<<min(a * n, b)<<endl;

    return 0;
}
