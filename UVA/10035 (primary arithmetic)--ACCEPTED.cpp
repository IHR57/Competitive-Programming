#include <iostream>
using namespace std;

int main()
{
    long int a, _a, b, _b, result, c, count=0;

    while(cin>>a>>b){
        count=0;
        c=0;
        if(a==0 && b==0)
            break;
        while(a!=0 || b!=0){
            _a=a%10;
            a=a/10;
            _b=b%10;
            b=b/10;

            result=_a+_b+c;

            if(result>=10){
                c=1;
                count++;
            }
            else
                c=0;
        }
        if(count==0)
            cout<<"No carry operation."<<endl;
        else if(count==1)
            cout<<count<<" carry operation."<<endl;
        else if(count>0)
            cout<<count<<" carry operations."<<endl;
    }

    return 0;
}

