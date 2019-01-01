#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lint;

int main()
{
    lint n, result, value, sum, prod;
    int count, test, rem;

    cin>>test;

    while(test--){
        count=sum=0;
        cin>>n;
        value=n;
        result=n;

        while(n!=0){
            n=n/10;
            count++;
        }

        while(value!=0){
            rem=value%10;
            prod=1;
            for(int i=1; i<=count; i++){
                prod*=rem;
            }
            sum+=prod;
            value=value/10;
        }

        //cout<<sum<<endl;
        if(sum==result)
            cout<<"Armstrong"<<endl;
        else
            cout<<"Not Armstrong"<<endl;
    }

    return 0;
}
