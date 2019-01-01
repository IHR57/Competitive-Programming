#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x, y, flag = 0;

    cin>>n>>x>>y;

    ll temp = (int) sqrt(x) + 1;

    if(temp + (n - 1) <= y){
        cout<<temp<<endl;
        for(int i = 0; i < n - 1; i++){
            cout<<1<<endl;
        }
        return 0;
    }
    else{
        while(temp--){
            if((temp * temp + (n - 1) < x) || (temp <= 0)){
                flag = 1;
                break;
            }
            if(temp + (n - 1) <= y){
                break;
            }
        }
    }

    if(flag){
        cout<<-1<<endl;
    }
    else{
        cout<<temp<<endl;
        for(int i = 0; i < n - 1; i++){
            cout<<1<<endl;
        }
    }

    return 0;
}
