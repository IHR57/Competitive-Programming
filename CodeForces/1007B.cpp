// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;

    bool flag = true;

    cin>>n;

    cin>>a>>b;

    int Max = max(a, b);
    for(int i = 1; i < n; i++){
        cin>>a>>b;
        int m = max(a, b);
        int n = min(a, b);
        if(m <= Max)
            Max = m;
        else{
            if(n <= Max){
                Max = n;
            }
            else{
                flag = false;
                break;
            }
        }
    }

    (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}

