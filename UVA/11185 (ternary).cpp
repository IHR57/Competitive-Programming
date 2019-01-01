#include <iostream>
using namespace std;

int main()
{
    long int n;
    int ternary[100];
    int i, len;

    while(cin>>n){
        if(n<0)
            break;

        i=0;
        len=0;
        while(n!=0){
            ternary[i]=(n%3);
            i++;
            n=n/3;
            len++;
        }

        for(i=len-1; i>=0; i--)
            cout<<ternary[i];
        cout<<endl;
    }

    return 0;
}
