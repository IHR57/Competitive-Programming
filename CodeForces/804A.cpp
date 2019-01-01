#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int lint;

int main()
{
    lint l, r, diff;

    cin>>l>>r;

    diff = r - l;

    if(diff == 0 || diff == 1){
        cout<<l<<endl;
    }
    else if(diff == 2){
        cout<<2<<endl;
    }
    else
        cout<<2<<endl;

    return 0;
}
