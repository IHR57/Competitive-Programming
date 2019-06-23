//Problem ID: AtCoder - abc115_c (Christmas Eve)
//Programmer: IQBAL HOSSAIN     Description: Sorting
//Date: 21/06/19
//Problem Link: https://atcoder.jp/contests/abc115/tasks/abc115_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int Min = 1e9;

    sort(arr, arr + n);

    for(int i = 0; i <= n - k; i++){
        int temp = arr[i+k-1] - arr[i];
        Min = min(Min, temp);
    }

    cout<<Min<<endl;

    return 0;
}