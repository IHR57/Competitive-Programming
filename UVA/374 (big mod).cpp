#include <iostream>
using namespace std;

typedef long long int lint;

lint bigMod(lint b, lint p, lint M)
{
    if(p==0)
        return 1%M;
    lint x=bigMod(b, p/2, M);

    x=(x*x)%M;

    if(p%2==1)
        x=(x*b)%M;

    return x;
}

int main()
{
    lint a, b, m, r;

    while(cin>>a>>b>>m){
        r=bigMod(a, b, m);
        cout<<r<<endl;
    }

    return 0;
}
