#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main()
{
    int test, i=1;
    double circle_area, shade, square, radius, length,  pi;

    cin>>test;

    pi=2*acos(0.0);
    while(test--){
        cin>>radius;
        length=radius*2;
        square=length*length;
        circle_area=pi*radius*radius;
        shade=square-circle_area;
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<"Case "<<i++<<": "<<shade<<endl;
    }

    return 0;
}
