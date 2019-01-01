#include <iostream>
using namespace std;

int main()
{
    int test, Empty, Found, Required, a;
    int sum, total;

    cin>>test;

    while(test--){
        sum=0;
        cin>>Empty>>Found>>Required;
        total=Empty+Found;
        while(total!=0){
            a=(total/Required);
            sum+=a;
            total=a+(total%Required);
            if(total<Required)
                break;
        }
        cout<<sum<<endl;
    }

    return 0;
}
