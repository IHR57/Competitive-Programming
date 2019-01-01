#include <iostream>
using namespace std;

typedef long long int lint;

int main()
{
    int test, cases=1;
    lint n, result, up, low, value;

    cin>>test;

    while(test--){
        cin>>n;
        value=n*n-n;
        cout<<"Case "<<cases++<<": ";
        if(value%4!=0){
            up=value/2;
            low=4/2;
            cout<<up<<"/"<<low<<endl;
        }
        else{
            result=value/4;
            cout<<result<<endl;
        }
    }

    return 0;
}
