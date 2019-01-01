#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    int test, n, i;
    double a, b, result, c[3000], sum;

    cin>>test;

    for(i=0; i<test; i++){
        sum=0;
        cin>>n;
        cin>>a>>b;
        for(int j=0; j<n; j++){
            cin>>c[j];
        }

        int k=2;
        for(int j=n-1; j>=0; j--){
            sum+=k*c[j];
            k+=2;
        }

        cout<<setiosflags(ios::fixed)<<setprecision(2);
        result=((n*a+b)-sum)/(n+1);
        cout<<result<<endl;

        if(i!=test-1)
            cout<<endl;
    }

    return 0;
}

