#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lint;

int main()
{
    int test;
    lint n, result;

    cin>>test;

    while(test--){
        cin>>n;

        result = (-1 + sqrt(1+8*n))/2;

        cout<<result<<endl;
    }

    return 0;
}
