#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int cs[MAX], a[MAX], n, k;

bool check()
{
    int len = n - k - 1;
    if(a[1] == a[n])
        return false;
    if(a[len] == a[len+1] || a[n-len] == a[n-len+1])
        return false;
    if(2 * k < n)
        return false;
    for(int i = 2; i <= len; i++){
        if(a[i] != a[i-1] || a[n-i+1] != a[n-i+2])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt",  "w", stdout);
    #endif
    string str;

    cin>>n>>k;
    cin>>str;

    for(int i = 0; i < n; i++){
        a[i+1] = str[i] - 48;
    }

    for(int i = 1; i <= n; i++){
        cs[i] = cs[i-1] + a[i];
    }

    for(int i = 1; i <= (n - k + 1); i++){
        int ans = cs[i-1] + (cs[n] - cs[i + k - 1]);
        if(ans == 0 || ans == n - k){
            cout<<"tokitsukaze"<<endl;
            return 0;
        }
    }

    if(check()){
        cout<<"quailty"<<endl;
    }
    else{
        cout<<"once again"<<endl;
    }


    return 0;
}