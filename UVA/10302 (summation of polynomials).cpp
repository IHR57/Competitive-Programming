#include <iostream>
using namespace std;

typedef long long int lint;

int main()
{
    lint x, sum, i;

    while(cin>>x){
        sum=0;
        for(i=1; i<=x; i++){
            sum+=(i*i*i);
        }
        cout<<sum<<endl;
    }

    return 0;
}
