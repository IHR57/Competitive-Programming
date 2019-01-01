#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long int n, result, sum, power, res;
    int test;

    cin>>test;

    while(test--){
        cin>>n;

        sum = (n * (n + 1)) / 2;

        for(int i = 1; i <= n; i *= 2){
            sum = sum - (i*2);
        }

        cout<<sum<<endl;
    }

    return 0;
}
