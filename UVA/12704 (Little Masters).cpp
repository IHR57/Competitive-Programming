#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double x, y, radius, result, Min, Max;
    int test;

    cin>>test;

    while(test--){
        cin>>x>>y>>radius;
        result=sqrt(x*x+y*y);
        Min=(radius-result);
        Max=(radius+result);

        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<Min<<" "<<Max<<endl;
    }

    return 0;
}
