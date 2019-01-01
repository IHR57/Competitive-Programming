#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lint;

int main()
{
    lint n, k, value;

    cin>>n>>k;

    if(k <= (n+1) / 2){
        value = (2 * k) - 1;
    }
    else{
        if(n % 2 == 0){
            value = (2 * k)  - n;
        }
        else if(n % 2 != 0){
            value = (2 * k) - n - 1;
        }
    }

    cout<<value<<endl;

    return 0;
}
