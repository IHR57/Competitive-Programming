#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, value, t;

    cin>>n;
    cin>>value;
    t = value;

    ll result = 1;

    while(value % 2 == 0){
        value /= 2; result *= 2;
    }
    while(value % 3 == 0){
        value /= 3; result *= 3;
    }

    result = t / result;

    for(int i = 1; i < n; i++){
        cin>>value;
        t = value;
        ll temp = 1;
        while(value % 2 == 0){
            value /= 2; temp *= 2;
        }
        while(value % 3 == 0){
            value /= 3; temp *= 3;
        }

        //cout<<t/temp<<endl;
        if(t / temp != result){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;

    return 0;
}
