//Problem ID: CodeForces - 1061B (Views Matter)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 11/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, arr[MAX], Max = -1;
    ll tot = 0;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        tot += (ll) arr[i];
    }

    if(n == 1){
        cout<<0<<endl;
        return 0;
    }

    sort(arr, arr + n);

    int last = 0;
    ll sum = n;
    for(int i = 0; i < n; i++){
        if(arr[i] > last)
            last++;
    }

    sum += (ll) (arr[n-1] - last);

    cout<<(tot - sum)<<endl;

    return 0;
}
