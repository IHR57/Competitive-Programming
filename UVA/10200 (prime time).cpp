#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdio>
using namespace std;

const int size=10010;
int s[size];

bool isPrime(long result)
{
    int sqrtResult=sqrt(result+1);

    if(result%2==0)
        return false;
    else{
        for(int i=3; i<=sqrtResult; i+=2){
            if(result%i==0)
                return false;
        }
    }
    return true;
}

int main()
{
    int a, b, count;
    long result;
    double percentage;

    s[0]=0;
    for(int i=0; i<=10000; i++){
        s[i+1]=s[i];
        result=i*i+i+41;
        if(isPrime(result)==true){
            s[i+1]++;
        }
    }
    while(cin>>a>>b){
        percentage=(double)(s[b+1]-s[a])/(double)(b-a+1);
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<percentage*100.00+1e-6<<endl;
    }

    return 0;
}
