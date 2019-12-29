//Problem ID: CodeForces - 676C (Vasya and String)
//Programmer: IQBAL HOSSAIN     Description: Binary Search
//Date: 31/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int a[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, str;
    int n, k;

    cin>>n>>k;
    cin>>s;

    str += "#";
    str += s;

    for(int i = 1; i <= n; i++){
        if(str[i] == 'a'){
            a[i] = 1 + a[i-1];
            b[i] = b[i-1];
        }
        else{
            b[i] = 1 + b[i-1];
            a[i] = a[i-1];
        }
    }

    int idx1, idx2, ans , res = 0, cntb = 0;
    for(int i = 1; i <= n; i++){
        if(str[i] == 'a'){
           idx1 = upper_bound(b, b + n + 1, b[i] + k) - b;
           idx2 = upper_bound(a, a + n + 1, a[i] - 1 + k) - a;
        }
        else if(str[i] == 'b'){
           idx1 = upper_bound(b, b + n + 1, b[i] - 1 + k) - b;
           idx2 = upper_bound(a, a + n + 1, a[i] + k) - a;
        }
        ans = max(idx1 - i, idx2 - i);
        res = max(res, ans);
    }


    cout<<res<<endl;

    return 0;
}
