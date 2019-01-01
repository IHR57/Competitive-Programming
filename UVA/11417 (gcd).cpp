#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int gcd, t;

    if(a==0)
        gcd=b;
    else if(b==0)
        gcd=a;
    else{
        while(b!=0){
            t=b;
            b=a%b;
            a=t;
        }
        gcd=a;
    }

    return gcd;
}

int main()
{
    int sum, i, j, n;

    while(cin>>n && n!=0){
        sum=0;
        for(i=1; i<n; i++){
            for(j=i+1; j<=n; j++){
                sum+=gcd(i, j);
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
