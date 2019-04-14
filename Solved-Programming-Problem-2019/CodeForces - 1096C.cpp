//Problem ID: CodeForces - 1096C (Polygon for the Angle)
//Programmer: IQBAL HOSSAIN     Description: Geometry/Brute Force
//Date: 09/04/19
#include <bits/stdc++.h>
#define MAX 205
using namespace std;

int res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, ang;

    for(int i = 3; i <= 180; i++){
        double div = (double) 180 / i;
        double temp = div;
        for(int j = 1; j <= i - 2; j++){
            //cout<<temp<<endl;
            if(temp == floor(temp)){
                int t = (int) temp;
                if(!res[t]){
                    res[t] = i;
                }
            }
            temp += div;
        }
    }
    res[179] = 360;

    cin>>q;
    while(q--){
        cin>>ang;
        cout<<res[ang]<<endl;
    }

    return 0;
}
