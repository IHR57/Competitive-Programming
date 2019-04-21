//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x[5];

    int idx, Max = -1;
    for(int i = 0; i < 4; i++){
        cin>>x[i];
        if(x[i] > Max){
            Max = x[i];
            idx = i;
        }
    }

    for(int i = 0; i < 4; i++){
        if(i != idx){
            cout<<Max - x[i]<<" ";
        }
    }
    cout<<endl;

    return 0;
}
