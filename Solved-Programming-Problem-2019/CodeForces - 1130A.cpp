//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val, pos = 0, neg = 0;

    cin>>n;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin>>val;
        if(val == 0)
            cnt++;
        if(val > 0)
            pos++;
        if(val < 0)
            neg++;
    }

    if(cnt > n / 2){
        cout<<0<<endl;
    }
    else{
        if(neg >= (n+1) / 2)
            cout<<-1<<endl;
        else if(pos >= (n+1) / 2){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }

    return 0;
}
