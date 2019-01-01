#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

typedef pair<int, int> pii;

bool compare(pii a, pii b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    pii a[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
    }

    sort(a, a + n, compare);

    //for(int i = 0; i < n; i++){
      //  cout<<a[i].first<<" "<<a[i].second<<endl;
    //}

    int Max = -1;
    for(int i = 0; i < n; i++){
        if(a[i].second >= Max)
            Max = a[i].second;
        else
            Max = a[i].first;
    }

    cout<<Max<<endl;

    return 0;
}
