#include <iostream>
using namespace std;

typedef long long int lint;

int main()
{
    int test, n;
    lint a, b, c, sum;

    cin>>test;
    while(test--){
        sum=0;
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a>>b>>c;
            sum+=a*c;
        }
        cout<<sum<<endl;
    }

    return 0;
}
