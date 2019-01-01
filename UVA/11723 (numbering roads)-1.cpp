#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int road, integers, required, i=1;

    while(cin>>road>>integers){
        if(road==0 && integers==0)
            break;
        required=(road-1)/integers;
        if(required>26)
            printf("Case %d: impossible\n", i++);
        else
            printf("Case %d: %d\n", i++, required);
    }

    return 0;
}
