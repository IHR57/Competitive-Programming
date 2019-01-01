#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    long long int Fib[60], n;
    int index;

    Fib[0] = 0, Fib[1] = 1;

    for(int i = 2; i <= 50; i++){
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }

    //cout<<Fib[50]<<endl;
    scanf("%lld", &n);

    if(n == 0)
        cout<<"0 0 0"<<endl;
    else if(n == 1)
        cout<<"0 0 1"<<endl;
    else if(n == 2)
        cout<<"0 1 1"<<endl;
    else{
        for(int i = 4; i <= 50; i++){
            if(n == Fib[i]){
                index = i;
                break;
            }
        }
        cout<<Fib[index - 4]<<" "<<Fib[index-3]<<" "<<Fib[index-1]<<endl;
    }

    return 0;
}
