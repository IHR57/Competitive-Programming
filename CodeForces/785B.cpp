#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

int main()
{
    lint n, m, l, r, maxla, minra, maxlb, minrb;

    maxla = -1, minra = INT_MAX, maxlb = -1, minrb = INT_MAX;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>l>>r;
        maxla = max(maxla, l);
        minra = min(minra, r);
    }

    cin>>m;

    for(int i = 0; i < m; i++){
        cin>>l>>r;
        maxlb = max(maxlb, l);
        minrb = min(minrb, r);
    }

    //cout<<maxla<<" "<<minra<<" "<<maxlb<<" "<<minrb<<endl;

    lint ans = 0;

    ans = max(ans, (maxla - minrb));
    ans = max(ans, (maxlb - minra));

    cout<<ans<<endl;

    return 0;
}
