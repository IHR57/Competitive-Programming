// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, flag = 0;

    cin>>n>>a>>b;

    int limit = n / max(a, b) + 1;

    if(a < b){
        swap(a, b);
        flag = 1;
    }

    int x, y;

    for(int i = 0; i <= limit; i++){
        int temp = (n - (a*i));
        if(temp < 0 || n == 0)
            break;
        if(temp % b == 0){
            x = i;
            y = (n - (a*i)) / b;
            cout<<"YES"<<endl;
            if(flag){
                cout<<y<<" "<<x<<endl;
            }
            else{
                cout<<x<<" "<<y<<endl;
            }
            return 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;
}
