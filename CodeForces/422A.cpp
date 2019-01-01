#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 100005
using namespace std;

long long int fact(int n)
{
    long long int prod = 1;

    for(int i = 1; i <= n; i++){
        prod *= i;
    }

    return prod;
}

int main()
{
    long long int  a, b, result;

    cin>>a>>b;

    int temp = min(a, b);

    result = fact(temp);

    cout<<result<<endl;

    return 0;
}
