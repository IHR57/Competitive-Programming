#include <iostream>
using namespace std;

int main()
{
    int test, a, b, time,  i;

    cin>>test;

    for(i=1; i<=test; i++){
        time=0;
        cin>>a>>b;
        if(a<b){
            time=(b-a)*4+19+a*4;
            cout<<"Case "<<i<<": "<<time<<endl;
        }
        else{
            time=(a-b)*4+(a-b)*4+19+b*4;
            cout<<"Case "<<i<<": "<<time<<endl;
        }
    }

    return 0;
}
