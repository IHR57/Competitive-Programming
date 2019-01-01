#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n, temp, Min, Max;

    cin>>n;

    temp = n / 7;

    Min = temp * 2;

    if(n % 7 == 0){
        Max = Min;
    }
    else if(n % 7 == 1){
        Max = Min + 1;
    }
    else if(n % 7 == 6){
        Max = Min + 2;
        Min = Min + 1;
    }
    else
        Max = Min + 2;

    cout<<Min<<" "<<Max<<endl;

    return 0;
}
