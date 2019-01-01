#include <iostream>
using namespace std;

int main()
{
    int N, K, P, T, sum, Net, j=1;

    cin>>T;
    for(int i=1; i<=T; i++){
        cin>>N>>K>>P;
        sum=K+P;
        Net=sum%N;
        if(Net==0)
        {
            sum=N;
            cout<<"Case "<<j<<": "<<N<<endl;
        }
        else
            cout<<"Case "<<j<<": "<<Net<<endl;

        j++;
    }

    return 0;
}
