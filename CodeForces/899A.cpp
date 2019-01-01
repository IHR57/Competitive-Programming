// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, xi, yi, side1 = 0, side2 = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>xi>>yi;
        if((xi > 0 && yi >= 0) || (xi > 0 && yi < 0)){
            side1++;
        }
        else
            side2++;
    }

    if(side1 <= 1 || side2 <= 1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}
