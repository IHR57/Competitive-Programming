//problem ID: 10696

#include <iostream>
using namespace std;

long int f91(long int N)
{
    if(N<=100)
        return f91(f91(N+11));
    if(N>=101){
        return N-10;
    }
}

int main()
{
    long int n;

    while(cin>>n){
        if(n==0)
            break;
        cout<<"f91("<<n<<") = "<<f91(n)<<endl;
    }

    return 0;
}
