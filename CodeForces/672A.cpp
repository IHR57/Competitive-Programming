#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n, data[1005], value;

    cin>>n;

    for(int i = 1; i <= 9; i++){
        data[i] = i;
    }

    for(int i = 10, j = 10; i <= 99; i++, j += 2){
        data[j] = i;
        data[j+1] = i;
    }

    for(int i = 100, j = 190; j <= 1000; i++, j += 3){
        data[j] = i;
        data[j+1] = i;
        data[j+2] = i;
    }

    if(n <= 9){
        value = data[n];
    }
    else if(n >= 10 && n <= 189){
        if(n % 2 == 0){
            value = data[n] / 10;
        }
        else{
            value = data[n] % 10;
        }
    }
    else if(n >= 190)
    {
        int temp = n - 187;

        if(temp % 3 == 0){
            value = data[n] / 100;
        }
        else if(temp % 3 == 2)
            value = data[n] % 10;
        else if(temp % 3 == 1){
            value = data[n] / 10;
            value = value % 10;
        }
    }

    cout<<value<<endl;

    return 0;
}
