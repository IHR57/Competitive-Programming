#include <iostream>
using namespace std;

typedef long int lint;

int main()
{
    lint n, count, digit, p;
    int test;

    cin>>test;

    for(int i=1; i<=test; i++){
        cin>>n>>digit;
        count=1;
        p=digit;
        while(p%n!=0){
            p=(p*10+digit)%n;
            count++;
        }
        cout<<"Case "<<i<<": "<<count<<endl;

    }

    return 0;
}
