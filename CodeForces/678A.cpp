#include <iostream>
using namespace std;

int main()
{
    long long int n, k, result, mod, value;

    cin>>n>>k;

    mod = n % k;

    if(mod == 0){
        result = n + k;
    }
    else{
        result = (k - mod) + n;
    }

    cout<<result<<endl;

    return 0;
}
