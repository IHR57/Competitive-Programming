//Problem ID: CodeForces - 1059C (Sequence Transformation)
//Programmer: IQBAL HOSSAIN     Description: Math
//Date: 11/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 1; i <= n; i *= 2){
        int rem = n / i;
        if(rem == 3){
            cout<<i<<" "<<i<<" "<<3*i;
            break;
        }
        for(int j = i; j <= n; j += i * 2){
            cout<<i<<" ";
        }
    }

    cout<<endl;

    return 0;

}
