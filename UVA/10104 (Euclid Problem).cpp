#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int egcd(int a, int b, int &x, int &y)
{
    if(a==0){
        x=0; y=1;
        return b;
    }

    int x1, y1;

    int d=egcd(b%a, a, x1, y1);

    x=y1-(b/a)*x1;
    y=x1;

    return d;
}

int main()
{
    int a, b, div;
    int x, y;

    while(cin>>a>>b){
        div=egcd(a, b, x, y);
        if(a==b){
            x=0;
            y=1;
        }
       printf("%d %d %d\n", x, y, div);
    }
    return 0;
}
