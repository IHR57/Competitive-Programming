// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, s, t, parent[MAX], value;

    cin>>n>>s>>t;

    for(int i = 1; i <= n; i++){
        cin>>value;
        parent[i] = value;
    }

    int cnt = 0;

    if(s == t){
        cout<<0<<endl;
        return 0;
    }

    int flag = 0;
    while(cnt <= n){
        cnt++;
        if(parent[s] == t){
            flag = 1;
            break;
        }
        s = parent[s];
    }

    if(flag)
        cout<<cnt<<endl;
    else{
        cout<<-1<<endl;
    }
    return 0;
}
