#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int a, b, c, flag = 0;


    cin>>a>>b>>c;
    int div = 0;

    int value = a * div;

    if(c < a  && c < b){
        flag = 0;
    }
    else{
        while(value <= c){
            value = a * div;
            if(value > c)
                break;
            int dif = c - value;
            if(dif % b == 0){
                flag = 1;
                break;
            }
            div = div + 1;
        }
    }

    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
