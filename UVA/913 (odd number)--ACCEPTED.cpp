#include <iostream>
using namespace std;

int main()
{
    long long int N, last_value, sum, i;

    while(cin>>N){
        sum=0;
        last_value=N*(N+1)/2+(N/2);
        for(i=last_value; i>=last_value-4; i-=2){
            sum=sum+i;
        }
        cout<<sum<<endl;
    }

    return 0;
}
