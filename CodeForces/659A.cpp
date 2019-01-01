#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b, result;

    cin>>n>>a>>b;

    if(b >= 0){
        result = (a + b) % n;

        if(result == 0){
            result = n;
        }
    }
    else if(b < 0){
        int value = -(b);
        result = a;
        for(int i = 1; i <= value; i++){
            result = result - 1;
            if(result == 0)
                result = n;
        }
    }

    cout<<result<<endl;

    return 0;
}
