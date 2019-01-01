#include <iostream>
using namespace std;

int main()
{
    int N;
    long int sum;

    while(cin>>N){
        sum=0;
        if(N==0)
            break;
        for(int i=N; i>=1; i--){
            sum=(long)sum+(i*i);
        }
        cout<<sum<<endl;
    }

    return 0;
}
