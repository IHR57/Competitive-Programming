//Problem ID: Atcoder - abc119_c (Synthetic Kadomatsu)
//Programmer: IQBAL HOSSAIN     Description: Recursion/Backtracking
//Date: 04/06/19
//Problem Link: https://atcoder.jp/contests/abc119/tasks/abc119_c
#include <bits/stdc++.h>
#define MAX 100005
#define INF 1e9
using namespace std;

typedef long long ll;
int n, A, B, C, arr[10];

int solve(int pos, int a, int b, int c)
{
    if(pos >= n){
        if(min(a, min(b, c)) > 0)
            return abs(A - a) + abs(B - b) + abs(C - c) - 30;
        else
            return INF;
    }
    int ret = solve(pos + 1, a, b, c);
    ret = min(ret, solve(pos + 1, a + arr[pos], b, c) + 10);
    ret = min(ret, solve(pos + 1, a, b + arr[pos], c) + 10);
    ret = min(ret, solve(pos + 1, a, b, c + arr[pos]) + 10);

    return ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>n>>A>>B>>C;
    for(int i =  0; i < n; i++){
        cin>>arr[i];
    }

    int res = solve(0, 0, 0, 0);

    cout<<res<<endl;

    return 0;
}