//Problem ID: AtCoder - abc112_d (Partition)
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 06/07/19
//Problem Link: https://atcoder.jp/contests/abc112/tasks/abc112_d
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n, m;

    cin>>n>>m;

    vector<int> div;

    if(n == 1){
        cout<<m<<endl;
        return 0;
    }
    for(int i = 1; i * i <= m; i++){
        if(m % i == 0){
            div.push_back(i);
            if((m / i) != i)
                div.push_back(m/i);
        }
    }

    sort(div.begin(), div.end());
    reverse(div.begin(), div.end());

    for(int i = 0; i < div.size(); i++){
        ll temp = (n - 1) * 1LL * div[i];
        if(temp >= m)
            continue;
        if((m - temp) % div[i] == 0){
            cout<<div[i]<<endl;
            return 0;
        }
    }

    return 0;
}