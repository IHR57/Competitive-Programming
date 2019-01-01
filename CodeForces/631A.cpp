#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lint;

int main()
{
    int n, value;
    lint result1 = 0, result2 = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>value;
        result1 = result1 | value;
    }

    for(int i = 0; i < n; i++){
        cin>>value;
        result2 = result2 | value;
    }

    cout<<result1 + result2<<endl;

    return 0;
}
