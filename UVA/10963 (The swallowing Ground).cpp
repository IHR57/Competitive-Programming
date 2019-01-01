#include <iostream>
using namespace std;

int main()
{
    int test, column, y1, y2, i, difference, d;
    bool flag;

    cin>>test;

    while(test--){
        flag=true;
        cin>>column;
        cin>>y1>>y2;
        difference=y1-y2;
        for(i=0; i<column-1; i++){
            cin>>y1>>y2;
            d=y1-y2;
            if(d!=difference){
                flag=false;
            }
        }

        if(flag)        //if each difference same then print yes
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        if(test)
            cout<<endl;
    }

    return 0;
}
