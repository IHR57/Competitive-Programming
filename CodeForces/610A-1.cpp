#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int n, result;

    cin>>n;

    if(n % 2 != 0){
        result = 0;
    }
    else if(n % 4 == 0){
        result = (n / 4) - 1;
    }
    else{
        result = n / 4;
    }

    cout<<result<<endl;

    return 0;

}
