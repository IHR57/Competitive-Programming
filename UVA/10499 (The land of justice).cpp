#include <iostream>
using namespace std;

typedef long long int lint;

int main()
{
    lint n, percentage;

    while(cin>>n && n>=0){
        if(n==0 || n==1)
            percentage=0;
        else{
            percentage=n*25;
        }
        cout<<percentage<<"%"<<endl;
    }

    return 0;
}
