//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, v;

    cin>>n>>v;


    int r = min(v, n - 1);
    int rem = (n - 1) - r;

    int cost = r;
    for(int i = 2; i <= n; i++){
        if(rem == 0)
            break;
        if(rem){
            cost += i;
            rem--;
        }
    }

    cout<<cost<<endl;

    return 0;
}
