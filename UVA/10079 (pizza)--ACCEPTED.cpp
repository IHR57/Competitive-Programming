#include <iostream>
using namespace std;

int main()
{
    long long int n, c;

    while(cin>>n){
        if(n<0)
            break;
        c=(n*(n+1))/2+1;
        cout<<c<<endl;
    }

    return 0;
}
