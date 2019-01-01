#include <iostream>
using namespace std;

int main()
{
    int n, result;

    while(cin>>n){
        if(n>0){
            result=n*(n+1)/2;
        }
        else if(n<=0){
            result=1+(n*(1-n)/2);
        }
        cout<<result<<endl;
    }

    return 0;
}
