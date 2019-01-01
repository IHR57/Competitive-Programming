#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int five = 0, zero = 0, n, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        if(value == 0)
            zero++;
        if(value == 5)
            five++;
    }

    if(zero >= 1 && five < 9)
        cout<<0<<endl;
    else if(zero >= 1 && five >= 9){
        int num = five / 9;

        for(int i = 1; i <= num * 9; i++){
            cout<<"5";
        }
        for(int i = 1; i <= zero; i++)
            cout<<"0";
        cout<<endl;
    }
    else
        cout<<"-1"<<endl;

    return 0;
}
