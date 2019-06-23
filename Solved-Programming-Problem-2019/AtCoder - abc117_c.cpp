//Problem ID: AtCoder - abc117_c (Streamline)
//Programmer: IQBAL HOSSAIN     Description: Sorting/Greedy
//Date: 09/06/19
//Problem Link: https://atcoder.jp/contests/abc117/tasks/abc117_c
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
#define INF 1e9
#define mp make_pair
using namespace std;

typedef long long ll;
int arr[MAX];
vector<int> diff;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, k;

    cin>>k>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    if(k >= n){
        cout<<0<<endl;
        return 0;
    }
    sort(arr, arr + n);

    int sum = arr[n-1] - arr[0];
    for(int i = 1; i < n; i++){
        diff.push_back(arr[i] - arr[i-1]);
    }

    sort(diff.begin(), diff.end());
    reverse(diff.begin(), diff.end());

    for(int i = 0; i < k - 1; i++){
        sum -= diff[i];
    }

    cout<<sum<<endl;

    return 0;
}
