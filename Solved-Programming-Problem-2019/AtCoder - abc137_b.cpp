#include <bits/stdc++.h>
#define INF 2147483647
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, x;

    cin>>k>>x;

    k--;
    for(int i = x - k; i <= x + k; i++){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

