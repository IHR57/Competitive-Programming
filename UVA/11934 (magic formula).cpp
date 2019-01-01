#include <iostream>
using namespace std;

int main()
{
    int a, b, c, divisor, limit, i, equation, count;

    while(cin>>a>>b>>c>>divisor>>limit){
        count=0;
        if(a==0 && b==0 && c==0 && divisor==0 && limit==0)
            break;
        for(i=0; i<=limit; i++){
            equation=(a*(i*i)+b*i+c);
            if(equation%divisor==0)
                count++;
        }
        cout<<count<<endl;
    }

    return 0;
}

