#include <iostream>
using namespace std;

int main()
{
    int h1, m1, h2, m2, diff;

    while(cin>>h1>>m1>>h2>>m2){
        if(h1==0 && m1==0 && h2==0 && m2==0){
            break;
        }
        if(h1==0)
            h1=24;
        if(h2==0)
            h2=24;

        diff=0;
        if(h1==h2 && m2>m1){
            diff=m2-m1;
            cout<<diff<<endl;
        }
        else if(h1==h2 && m1==m2){
            diff=0;
            cout<<diff<<endl;
        }
        else if(h1==h2 && m1>m2){
            diff=(60-(m1-m2))+(23*60);
            cout<<diff<<endl;
        }
        else if(h1<h2 && m1<m2){
            diff=(m2-m1)+((h2-h1)*60);
            cout<<diff<<endl;
        }
        else if(h1<h2 && m1>=m2){
            diff=(60-(m1-m2))+((h2-h1-1)*60);
            cout<<diff<<endl;
        }
        else if(h1>h2 && m1>=m2){
            diff=(60-(m1-m2))+((23-(h1-h2))*60);
            cout<<diff<<endl;
        }
        else if(h1>h2 && m1<m2){
            diff=((24-(h1-h2))*60)+(m2-m1);
            cout<<diff<<endl;
        }
    }

    return 0;
}
