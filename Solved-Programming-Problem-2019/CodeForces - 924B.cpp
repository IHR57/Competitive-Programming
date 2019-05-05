//CodeForces - 924B (Three-level Laser)
//Programmer: IQBAL HOSSAIN     Description: Binary Search/Greedy/Two Pointers
//Date: 05/05/19
#include <bits/stdc++.h>
#define MAX 100005
#define iosflags (cout<<setiosflags(ios::fixed)<<setprecision(10))
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u;

    cin>>n>>u;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    double Max = 0.0;
    int flag = 0;

    for(int i = 0; i < n; i++){
        int idx = lower_bound(arr, arr + n, arr[i] + u) - arr;
        if(idx >= n)
            idx--;
        if(arr[idx] - arr[i] > u)
            idx--;
        if(idx - i >= 2){
            flag = 1;
            double res = ((double) arr[idx] - (double) arr[i+1]) / ((double) arr[idx] - (double) arr[i]);
            Max = max(res, Max);
        }
    }

    iosflags;
    (flag) ? cout<<Max<<endl : cout<<-1<<endl;

    return 0;
}
