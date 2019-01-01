#include <iostream>
using namespace std;

int main()
{
    int div, m, n, test;

    cin>>test;

    while(test--){
        cin>>m>>n;
        if((m-1)%(n-1)!=0)
            cout<<"cannot do this"<<endl;
        else{
            div=(m-1)/(n-1);
            cout<<div<<endl;
        }
    }

    return 0;
}
