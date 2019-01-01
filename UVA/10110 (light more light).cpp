//Problem ID: 10110
#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lint;

int main()
{
    lint input, check_input;

    while(cin>>input){
        if(input==0)
            break;
        check_input=sqrt(input);
        if((check_input*check_input)==input)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}
