#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, result;

    cin>>n;

    if(n % 5 != 0){
        result = n / 5 + 1;
    }
    else
        result = n / 5;

    cout<<result<<endl;

    return 0;
}
