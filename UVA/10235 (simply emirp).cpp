#include <iostream>
#include <math.h>
using namespace std;
long int reverse;
long int prime(long int n)
{
    int lim, check=0;
    lim=sqrt(n);
    int i;
    for(i=2; i<=lim; i++){
        if(n%i==0)
            check=1;
    }
    if(check==0)
        return n;
}

long int reverse_number(long int n)
{
   // long int reverse;
    while(n!=0){
        reverse=reverse*10;
        reverse=reverse+n%10;
        n=n/10;
    }
    return reverse;
}

int main()
{
    long int n, tmp=0, rev=0;

    while(cin>>n){
        reverse=0;
        if(n==prime(n) && n!=0){
            tmp=reverse_number(n);
            //cout<<reverse<<endl;
           // prime(reverse);
            if(tmp==prime(tmp)){
                if(tmp==n)
                    cout<<n<<" is prime."<<endl;
                else
                    cout<<n<<" is emirp."<<endl;
            }
            else
                cout<<n<<" is prime."<<endl;
        }
        else
            cout<<n<<" is not prime."<<endl;
    }

    return 0;
}
