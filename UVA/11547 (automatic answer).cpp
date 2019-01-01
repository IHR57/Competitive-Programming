#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n, i, test;
    long long int p, q, r, remainder;

    cin>>test;

    while(test--){
        cin>>n;
        p=(long long)(n*567)/9;
        q=(p+7492)*235;
        r=(q/47)-498;
        //cout<<r<<endl;
        for(i=1; i<=2; i++){
            remainder=r%10;
            r=r/10;
        }
        if(n>=0)
            cout<<remainder<<endl;
        else if(n<0)
            cout<<abs(remainder)<<endl;
    }

    return 0;
}
