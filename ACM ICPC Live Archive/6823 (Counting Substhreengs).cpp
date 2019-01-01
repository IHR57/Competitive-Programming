#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define MAX 1000005
using namespace std;

typedef long long ll;

int main()
{
    string str;
    int counter[4], sum;

    while(cin>>str){
        counter[0] = 1, counter[1] = 0, counter[2] = 0, sum = 0;
        int len = (int) str.length();
        ll ans = 0;
        for(int i = 0; i < len; i++){
            if(str[i] >= '0' && str[i] <= '9'){
                sum = (sum + (str[i] - 48)) % 3;
                ans += counter[sum];
                counter[sum]++;
            }
            else{
                counter[0] = 1, counter[1] = 0, counter[2] = 0, sum = 0;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
