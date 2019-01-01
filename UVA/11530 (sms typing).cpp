#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int test;
    string str;

    cin>>test;
    cin.ignore(100, '\n');

    while(test--){
        getline(cin, str);
        int len, j=1, sum=0, press, i, sz;

        sum=0;
        for(i=0,  sz=str.size(); i<sz;  i++){
            if(str[i]=='a' || str[i]=='d' || str[i]=='g' || str[i]=='j' || str[i]=='m' || str[i]=='p' || str[i]=='t' || str[i]=='w' || str[i]==' '){
                press=1;
            }
            else if(str[i]=='b' || str[i]=='e' || str[i]=='h' || str[i]=='k' || str[i]=='n' || str[i]=='q' || str[i]=='u' || str[i]=='x'){
                press=2;
            }
            else if(str[i]=='c' || str[i]=='f' || str[i]=='i' || str[i]=='l' || str[i]=='o' || str[i]=='r' || str[i]=='v' || str[i]=='y'){
                press=3;
            }
            else if(str[i]=='s' || str[i]=='z')
                press=4;
            sum+=press;
        }
        cout<<"Case #"<<j<<": "<<sum<<endl;
        j++;
    }
    return 0;
}
