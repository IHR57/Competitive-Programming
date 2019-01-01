//UVA 12577(Hajj-e-Akbar)
//Programmer: IQBAL HOSSAIN

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int i=1;
    char ch[10];

    //we should check only first character as there is no other word than Hajj and Umrah
    while(cin>>ch){
        if(ch[0]=='*')//terminate with *
            break;
        else if(ch[0]=='H')
            cout<<"Case "<<i<<": "<<"Hajj-e-Akbar"<<endl;
        else if(ch[0]='U')
            cout<<"Case "<<i<<": "<<"Hajj-e-Asghar"<<endl;
        i++;
    }

    return 0;
}
