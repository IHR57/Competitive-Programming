#include <iostream>
using namespace std;

int main()
{
    int n, first, second, count=1;
    cin>>n;

    cin>>first;

    for(int i=1; i<n; i++){
        cin>>second;
        if(second>first){
            count+=1;
        }
        else
            count=1;
        first=second;
    }

    cout<<n-count<<endl;

    return 0;
}
