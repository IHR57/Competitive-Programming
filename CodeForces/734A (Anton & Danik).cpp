#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;

    cin>>n;
    cin>>str;

    int count_A, count_D;

    count_A  = count_D = 0;

    for(int i=0; i<str.size(); i++){
        if(str[i]=='A')
            count_A++;
        else if(str[i]=='D')
            count_D++;
    }

    if(count_A>count_D){
        cout<<"Anton"<<endl;
    }
    else if(count_D>count_A)
        cout<<"Danik"<<endl;
    else
        cout<<"Friendship"<<endl;

    return 0;
}
