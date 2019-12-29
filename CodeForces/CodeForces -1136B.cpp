//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    int sum = (n + 1);
    sum += (n - 1) + min(k - 1, n - k);
    sum += n;

    cout<<sum<<endl;

    return 0;
}
