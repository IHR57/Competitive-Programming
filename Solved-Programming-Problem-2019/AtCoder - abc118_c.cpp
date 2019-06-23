//Problem ID: AtCoder - abc118_c (Monsters Battle Royale)
//Programmer: IQBAL HOSSAIN     Description: GCD
//Date: 07/06/19
//Problem Link: https://atcoder.jp/contests/abc118/tasks/abc118_c
#include <bits/stdc++.h>
#define MAX 100005
#define INF 1e9
using namespace std;

typedef long long ll;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;

    cin>>n;

    cin>>arr[0];
    int g = arr[0];
    for(int i = 1; i < n; i++){
        cin>>arr[i];
        g = __gcd(g, arr[i]);
    }    

    cout<<g<<endl;

    return 0;
}