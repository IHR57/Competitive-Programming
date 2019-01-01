#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long int a, b, data[100000];

    cin>>a>>b;
    int i = 1, flag = 0;

    data[0] = b;

    while(a < b){
        int t = b % 10;

        if(t == 1){
            b = (b - 1) / 10;
            data[i++] = b;
            continue;
        }
        else if(t % 2 == 1){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            b = b / 2;
            data[i++] = b;
        }
    }

    if(b < a){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    cout<<i<<endl;
    for(int j = i-1; j >= 0; j--){
        cout<<data[j]<<" ";
    }
    cout<<endl;

    return 0;
}
