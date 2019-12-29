//Problem ID: AtCoder - abc114_c (755)
//Programmer: IQBAL HOSSAIN     Description: Recursion/Backtracking
//Date: 27/06/19
//Problem ID: https://atcoder.jp/contests/abc114/tasks/abc114_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<int> v;
int k, cnt = 0;

int Pow(int a, int b)
{
    int ans = 1;
    for(int i = 0; i < b; i++){
        ans *= 10;
    }
    return ans;
}

bool check(int val)
{
    bool flag3 = 0, flag5 = 0, flag7 = 0;
    while(val){
        int rem = val % 10;
        if(rem == 3)
            flag3 = 1;
        if(rem == 5)
            flag5 = 1;
        if(rem == 7)
            flag7 = 1;
        val /= 10;
    }

    if(flag3 && flag5 && flag7)
        return true;
    return false;
}

int solve(int pos, int val)
{
    if(pos >= k){
        if(check(val)){
            //cout<<val<<endl;
            v.push_back(val);
            cnt++;
        }
        return 0;
    }    
    int ret1 = solve(pos + 1, 3 * Pow(10, pos) + val);
    int ret2 = solve(pos + 1, 5 * Pow(10, pos) + val);
    int ret3 = solve(pos + 1, 7 * Pow(10, pos) + val);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    for(int i = 3; i <= 9; i++){
        k = i;
        solve(0, 0);
    }
    int n;
    cin>>n;
    sort(v.begin(), v.end());
    int idx = upper_bound(v.begin(), v.end(), n) - v.begin();

    cout<<idx<<endl;

    return 0;
}