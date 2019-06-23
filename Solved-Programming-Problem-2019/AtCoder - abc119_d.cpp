//Problem ID: AtCoder - abc119_d (Lazy Faith)
//Programmer: IQBAL HOSSAIN     Description: Binary Search
//Date: 04/06/19
//Problem Link: https://atcoder.jp/contests/abc119/tasks/abc119_d
#include <bits/stdc++.h>
#define MAX 100005
#define INF 1e9
using namespace std;

typedef long long ll;

ll solve(ll s[], ll t[], int a, int b, ll n)
{
    int idx1 = lower_bound(s, s + a, n) - s, idx2;
    if(idx1 == a)
        idx1--;
    ll res1, res2;
    if(idx1 == 0){
        res1 = abs(s[idx1] - n);
        idx2 = lower_bound(t, t + b, s[idx1]) - t;
        if(idx2 == b)
            idx2--;
        if(idx2 == 0){
            res1 += abs(t[idx2] - s[idx1]);
            return res1;
        }
        else{
            ll temp1 = abs(t[idx2] - s[idx1]);
            ll temp2 = abs(t[idx2-1] - s[idx1]);
            res1 += min(temp1, temp2);
            return res1;
        }
    }
    else{
        //cout<<"I AM HERE"<<endl;
        res1 = abs(s[idx1] - n);
        res2 = abs(s[idx1-1] - n);
        idx2 = lower_bound(t, t + b, s[idx1]) - t;
        if(idx2 == b)
            idx2--;
        if(idx2 == 0){
            res1 += abs(t[idx2] - s[idx1]);
        }
        else{
            ll temp1 = abs(t[idx2] - s[idx1]);
            ll temp2 = abs(t[idx2-1] - s[idx1]);
            res1 += min(temp1, temp2);
        }
        idx2 = lower_bound(t, t + b, s[idx1-1]) - t;
        if(idx2 == b)
            idx2--;
        if(idx2 == 0){
            res2 += abs(t[idx2] - s[idx1-1]);
        }
        else{
            ll temp1 = abs(t[idx2] - s[idx1-1]);
            ll temp2 = abs(t[idx2-1] - s[idx1-1]);
            res2 += min(temp1, temp2);
        }
        return min(res1, res2);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int q, a, b;
    ll s[MAX], n, t[MAX];

    cin>>a>>b>>q;

    for(int i = 0; i < a; i++){
        cin>>s[i];
    }
    for(int j = 0; j < b; j++){
        cin>>t[j];
    }

    for(int i = 0; i < q; i++){
        cin>>n;
        ll ans1 = solve(s, t, a, b, n);
        ll ans2 = solve(t, s, b, a, n);
        cout<<min(ans1, ans2)<<endl;
    }

    return 0;
}