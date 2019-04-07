//Problem ID: CodeForces - 609C (Load Balancing)
//Programmer: IQBAL HOSSAIN     Description: MATH
//Date: 07/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, sum = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);
    int idx1 = sum / n, idx2;
    if(sum % n == 0)
        idx2 = idx1;
    else
        idx2 = idx1 + 1;

    for(int i = 0; i < n; i++){
        if(i < (sum % n)){
            b[i] = idx2;
        }
        else
            b[i] = idx1;
    }

    sort(b, b + n);

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(arr[i] - b[i]);
    }

    cout<<ans / 2<<endl;

    return 0;
}
