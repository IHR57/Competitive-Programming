#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int SumPositive, SumNegative, i, length, displacement;

    while(cin>>str){
        if(str=="0")
            break;

        SumPositive=SumNegative=0;

        for(i=0; i<str.size(); i+=2){
            SumPositive+=str[i]-48;
        }
        for(i=1; i<str.size(); i+=2){
            SumNegative+=str[i]-48;
        }

        if(SumPositive>=SumNegative)
            displacement=SumPositive-SumNegative;
        else
            displacement=SumNegative-SumPositive;

        if(displacement%11==0)
            cout<<str<<" is a multiple of 11."<<endl;
        else
            cout<<str<<" is not a multiple of 11."<<endl;
    }

    return 0;
}

