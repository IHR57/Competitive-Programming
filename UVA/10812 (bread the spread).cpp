//problem ID: 10812

#include <iostream>
using namespace std;

int main()
{
    int n, s, d, x, y, temp;

    cin>>n;

    while(n--){
        cin>>s>>d;
        temp=(s+d);
        x=temp/2;
        y=s-x;
        if((d>s) || (temp%2!=0)){
            cout<<"impossible"<<endl;
            continue;
        }
        if(y>x){
            temp=y;
            y=x;
            x=temp;
        }

        cout<<x<<" "<<y<<endl;
    }

    return 0;
}
