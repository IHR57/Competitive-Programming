#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int lint;

int main()
{
    lint l1, r1, l2, r2, k, value;

    cin>>l1>>r1>>l2>>r2>>k;

    lint left = max(l1, l2);
    lint right = min(r1, r2);

    if(left > right){
        cout<<0<<endl;
    }
    else{
        if(k >= left && k <= right)
            cout<<right - left<<endl;
        else{
            cout<<right - left + 1<<endl;
        }
    }

    return 0;
}
