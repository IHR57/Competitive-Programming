#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c;
    double s, result;

    while(cin>>a>>b>>c){
        if(a==0.0 || b==0.0 || c==0.0){
            cout<<"The radius of the round table is: 0.000"<<endl;
            continue;
        }
        s=(a+b+c)/2;
        result=sqrt(s*(s-a)*(s-b)*(s-c))/s;
        cout<<setiosflags(ios::fixed)<<setprecision(3);
        cout<<"The radius of the round table is: "<<result<<endl;
    }

    return 0;
}
