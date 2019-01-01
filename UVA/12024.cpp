#include <iostream>
using namespace std;

typedef long int lint;

lint derangement(int n)
{
    lint number;

    if(n==0)
        return 1;
    else if(n==1)
        return 0;
    else{
        number=(n-1)*derangement(n-2)+(n-1)*derangement(n-1);
    }
    return number;
}

lint factorial(int n)
{
    lint prod=1;

    for(int i=1; i<=n; i++){
        prod*=i;
    }
    return prod;
}

int main()
{
    int n, test;
    lint fac, der;

    cin>>test;

    while(test--){
        cin>>n;
        fac=factorial(n);
        der=derangement(n);
        cout<<der<<"/"<<fac<<endl;
    }

    return 0;
}
