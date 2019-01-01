#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    signed int a, b, c;

    while(cin>>a>>b>>c){
        if(a==0 && b==0 && c==0)
            break;
        else if(sqrt(a*a+b*b)==c)
            cout<<"right"<<endl;
        else if(sqrt(a*a+c*c)==b)
            cout<<"right"<<endl;
        else if(sqrt(b*b+c*c)==a)
            cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }

    return 0;
}
