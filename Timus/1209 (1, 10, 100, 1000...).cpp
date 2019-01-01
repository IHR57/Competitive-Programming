#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int test;
    long long position, value;
    long double result;

    cin>>test;

    vector<int>v;

    while(test--){
        cin>>position;
        result=sqrt(8*position-7.0);
        value=result;
        if(value==result)
            v.push_back(1);     //if it is perfect square
        else
            v.push_back(0);
    }

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    v.clear();

    return 0;
}
