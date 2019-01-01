#include <iostream>
using namespace std;

void print(int n)
{
    int i, j;
    for(i=1; i<=n; i++){
        for(j=0; j<i; j++){
            cout<<i;
        }
        cout<<endl;
    }
    for(i=n-1; i>=1; i--){
        for(j=0; j<i; j++){
            cout<<i;
        }
        cout<<endl;
    }
}

int main()
{
    int amp, freq, test;
    int flag=0;

    cin>>test;

    for(int j=1; j<=test; j++){
        cin>>amp>>freq;
        for(int i=1; i<=freq; i++){
            if(flag)    cout<<endl;
            print(amp);
            flag=1;
        }
        //cout<<endl;
    }

    return 0;
}
