#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d, e, Min, sum;

    cin>>a>>b>>c>>d>>e;

    Min = a + b + c + d + e;

    if(a == b && a == c){
        sum = d + e;
        if(sum <= Min)
            Min = sum;
    }

    if(a == b && a == d){
        sum = c + e;
        if(sum <= Min)
            Min = sum;
    }

    if(a == b && a == e){
        sum = c + d;
        if(sum <= Min)
            Min = sum;
    }

    if(a == b && a == c){
        sum = d + e;
        if(sum <= Min)
            Min = sum;
    }

    if(a == c && a == d){
        sum = b + e;
        if(sum <= Min)
            Min = sum;
    }

    if(a == c && a == e){
        sum = b + d;
        if(sum <= Min)
            Min = sum;
    }

    if(a == d && a == e){
        sum = b + c;
        if(sum <= Min)
            Min = sum;
    }
    if(b == c && b == d){
        sum = a + e;
        if(sum <= Min)
            Min = sum;
    }
    if(b == d  && b == e){
        sum = a + c;
        if(sum <= Min)
            Min = sum;
    }
    if(c == d && c == e){
        sum = a + b;
        if(sum <= Min)
            Min = sum;
    }
    if(a == b){
        sum = c + d + e;
        if(sum <= Min)
            Min = sum;
    }

    if(a == c){
        sum = b + d + e;
        if(sum <= Min)
            Min = sum;
    }

    if(a == d){
        sum = b + c + e;
        if(sum <= Min)
            Min = sum;
    }
    if(a == e){
        sum = b + c + d;
        if(sum <= Min)
            Min = sum;
    }
    if(b == c){
        sum = a + d + e;
        if(sum <= Min)
            Min = sum;
    }
    if(b == d){
        sum = a + c + e;
        if(sum <= Min)
            Min = sum;
    }
    if(b == e){
        sum = a + c + d;
        if(sum <= Min)
            Min = sum;
    }
    if(c == d){
        sum = a + b + e;
        if(sum <= Min)
            Min = sum;
    }

    if(c == e){
        sum = a + b + d;
        if(sum <= Min)
            Min = sum;
    }
    if(d == e){
        sum = a + b + c;
        if(sum <= Min)
            Min = sum;
    }

    cout<<Min<<endl;

    return 0;

}
