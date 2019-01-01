#include <iostream>
using namespace std;

int main()
{
    int test, n, m, result, temp;

    cin>>test;

    while(test--){
        cin>>n>>m;
        if(n==m){
            temp=(n+1)/2;
            result=(temp*(temp+1))/2;
        }
        else
            result=((n+1)/2)*((m+1)/2);
        cout<<result<<endl;
    }

    return 0;
}
