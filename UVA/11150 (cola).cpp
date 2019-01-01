#include <iostream>
using namespace std;

int main()
{
    int n, sum, div, empty_bottle;

    while(cin>>n){
        sum=0;
        div=n;
       // if(n%3==2){
        n=n+1;
        while(div!=0){
            sum+=div;
            div=n/3;
            empty_bottle=n%3;
            n=empty_bottle+div;
        }
        cout<<sum<<endl;
    }

    return 0;
}
