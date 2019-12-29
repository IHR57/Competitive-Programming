//Problem ID: CodeForces - 709B (CheckPoints)
//Programmer: IQBAL HOSSAIN     Description: Greedy/Sorting
//Date: 27/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
ll arr[MAX];
int n, a;

ll solve(int x, int y, int idx)
{
    ll sum = 0;
    if(idx - 1 >= x)
        sum += a - arr[idx-1];
    for(int i = idx - 1; i > x; i--){
        sum += (arr[i] - arr[i-1]);
    }
    if(idx < y)
        sum += (idx - 1 >= x) ? arr[idx] - arr[x] : arr[idx] - a;
    for(int i = idx + 1; i < y; i++){
        sum += (arr[i] - arr[i-1]);
    }
    //cout<<"SUM1 : "<<sum<<endl;
    ll sum1 = arr[idx] - a;
    for(int i = idx + 1; i < y; i++){
        sum1 += (arr[i] - arr[i-1]);
    }
    sum1 += arr[y-1] - arr[idx - 1];
    for(int i = idx - 1; i > x; i--){
        sum1 += (arr[i] - arr[i-1]);
    }

    return min(sum, sum1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>a;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    if(n == 1){
        cout<<0<<endl;
        return 0;
    }

    sort(arr, arr + n);

    ll ans = 1e14;
    int idx = upper_bound(arr, arr + n, a) - arr;
    if(idx == 0){
        ans = arr[n-2] - a;
        cout<<ans<<endl;
        return 0;
    }
    if(idx == n){
        ans = a - arr[1];
        cout<<ans<<endl;
        return 0;
    }

    ans = min(solve(1, n, idx), solve(0, n - 1, idx));

    cout<<ans<<endl;

    return 0;
}
