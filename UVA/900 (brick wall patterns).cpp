#include <iostream>
using namespace std;

typedef long long int lint;

lint Fib[52];

void init()
{
    Fib[0]=1;
    Fib[1]=2;

    for(int i=2; i<52; i++){
        Fib[i]=Fib[i-1]+Fib[i-2];
    }
}

int main()
{
    int input;

    init();
    while(cin>>input){
        if(input==0)
            break;
        cout<<Fib[input-1]<<endl;
    }

    return 0;
}
