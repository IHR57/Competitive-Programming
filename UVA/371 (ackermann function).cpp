#include <iostream>
using namespace std;

typedef long long int lint;

lint cycle(lint m);
void show(lint l, lint h, lint value, lint max);

lint cycle(lint m)
{
    int i=0;

    do{
        if((m%2)==0)
            m=m/2;
        else
            m=3*m+1;
        i++;
    }
    while(m!=1);

    return i;
}

int main()
{
    lint l, h, temp, value, max;
    int i;

    while(cin>>l>>h){
        if(l==0 && h==0)
            break;
        if(l>h){
            temp=l;
            l=h;
            h=temp;
        }

        max=0;
        for(i=l; i<=h; i++){
            temp=cycle(i);
            if(temp>max){
                max=temp;
                value=i;
            }
        }
        show(l, h, value, max);
    }

    return 0;
}

void show(lint l, lint h, lint value, lint max)
{
    cout<<"Between "<<l<<" and "<<h<<", "<<value<<" generates the longest sequence of "<<max<<" values."<<endl;
}
