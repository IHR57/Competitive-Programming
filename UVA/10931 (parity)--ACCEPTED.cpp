#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    long long n, p, r;
    int j, i, k;
    char binary[100], Reverse[100];

    while(cin>>n){
        if(n==0)
            break;
        p=0;
        j=0;
        while(n!=0){
            r=n%2;
            n=n/2;
            p=p+r;
            binary[j]=r+48;
            j++;
        }
        binary[j]='\0';
        for(i=j-1, k=0; i>=0; i--, k++){
            Reverse[k]=binary[i];
        }
        Reverse[k]='\0';
        cout<<"The parity of "<<Reverse<<" is "<<p<<" (mod 2)."<<endl;
    }

    return 0;
}
