#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long lint;

/*int bigMod(int a, int b)
{
    if(b == 0)  return 1;
    int x = bigMod(a, b / 2);
    x = (x * x) % mod;
    if(b % 2 == 1)
        x = (x * a) % mod;
    return x;
}
int convertDecimal(char* str, int base)
{
    int len = strlen(str);
    int Power = len - 1;
    int sum = 0;

    for(int i = 0; i < len; i++){
        int n = str[i] - 48;
        sum += (n * bigMod(base, Power--)) % mod;
    }

    return sum;
}*/

int main()
{
    int base, arr[1005], mod;
    char dividend[1005], divider[1005];

    while(cin>>base){
        if(!base)   break;
        cin>>dividend>>divider;

        int len = strlen(divider);
        int count = len - 1;
        mod = 0;

        int temp = 1, k = 0;
        for(int i = len - 1; i >= 0; i--){
            mod += (divider[i] - '0') * temp;
            temp *= base;
        }
        //cout<<mod<<endl;
        int length = strlen(dividend);
        int sum = 0;

        for(int i = 0; i < length; i++){
            sum = sum * base;
            sum += dividend[i] - 48;
            sum = sum % mod;
        }

        if(sum == 0)
            cout<<0<<endl;
        else{
            while(sum != 0){
                arr[k++] = sum % base;
                sum = sum / base;
            }

            for(int i = k - 1; i >= 0; i--){
                cout<<arr[i];
            }
            cout<<endl;
        }
    }

    return 0;

}
