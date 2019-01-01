#include <iostream>
using namespace std;

int increase(int a[])
{
    int i, in_exchange=0;

    for(i=0; i<9; i++){
        if(a[i]<a[i+1])
            in_exchange+=1;
    }
    return in_exchange;
}

int decrese(int a[])
{
    int i, out_exchange=0;

    for(i=0; i<9; i++){
        if(a[i]>a[i+1])
            out_exchange+=1;
    }
    return out_exchange;
}

int main()
{
    int i, value[20], j, k, cases;

    cin>>cases;
    cout<<"Lumberjacks:"<<endl;
    while(cases--){
        for(i=0; i<10; i++){
            cin>>value[i];
        }
        j=increase(value);
        k=decrese(value);
        if(j==9 || k==9){
            cout<<"Ordered"<<endl;
        }
        else
            cout<<"Unordered"<<endl;
    }

    return 0;
}
