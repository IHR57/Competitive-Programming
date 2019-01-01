#include <iostream>
using namespace std;

typedef unsigned long long int lint;

lint ncr(lint n, lint k)
{
    lint value, result=1;
    value=n;

    for(lint i=1; i<=k; i++){
        result=(result*value--)/i;
    }

    return result;
}

int main()
{
    lint n, k, combination, r;

    while(cin>>n>>k){
        if(n==0 && k==0)
            break;
        r=k;
        if(n-k<r)
            r=n-k;
        combination=ncr(n, r);
        cout<<combination<<endl;
    }

    return 0;
}
