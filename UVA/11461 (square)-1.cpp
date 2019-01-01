#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, count, value;

    while(cin>>a>>b){
        count = 0;
        if(a==0 && b==0){
            break;
        }
        for(int i=a; i<=b; i++){
            value = sqrt(i);
            if(value*value == i)
                count++;
        }

        cout<<count<<endl;
    }

    return 0;
}
