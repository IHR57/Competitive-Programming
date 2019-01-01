#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

long int GCD(long int x, long int y)
{
    long int r;
    while(y!=0){
        r=x%y;
        x=y;
        y=r;
    }

    return x;
}

int main()
{
    long int first, second, temp;

    while(cin>>first){
        if(first==0)
            break;
        cin>>second;
        if(second==0)   break;
        temp=abs(second-first);     //subtract every value to first value

        while(cin>>second){
            if(second==0)   break;
            temp=GCD(temp, abs(second-first));
        }

        cout<<temp<<endl;
    }

    return 0;
}
