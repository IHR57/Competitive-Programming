#include <iostream>
using namespace std;

typedef long long int lint;

lint Male[100];
lint Female[100];

int main()
{
    Male[0]=0;
    Male[1]=1;
    Female[0]=1;
    Female[1]=2;

    for(int i=2; i<52; i++){
        Male[i]=Male[i-1]+Male[i-2]+1;
    }

    for(int i=2; i<52; i++){
        Female[i]=Male[i-1]+Female[i-1]+1;
    }

    int input;

    while(cin>>input){
        if(input==-1)
            break;
        cout<<Male[input]<<" "<<Female[input]<<endl;
    }

    return 0;
}
