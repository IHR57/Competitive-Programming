#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c;

    cin>>a>>b>>c;
    cout<<max(0, (c - (a - b)))<<endl;

    return 0;
}

