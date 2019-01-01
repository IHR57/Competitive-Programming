#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

int digit, n;

string solve(int base)
{
    string str;
    int temp = n;
    while(temp != 0){
        int r = temp % base;
        str += (r + 48);
        temp /= base;
    }

    return str;
}

int main()
{
    while(cin>>n){
        if(n == -1)
            break;
        cin>>digit;
        if(n == 0){
            cout<<0<<endl;
            continue;
        }
        int Max = 0;
        string ans;
        for(int i = 10; i >= 2; i--){
            string result = solve(i);
            int len = (int) result.length();

            int cnt = 0;
            for(int i = 0; i < len; i++){
                int d = result[i] - 48;
                if(d == digit)
                    cnt++;
            }
            if(cnt > Max){
                Max = cnt;
                ans = result;
            }
        }
        if(Max == 0){
            ans = solve(10);
            for(int i = ans.length() - 1; i >= 0; i--){
                cout<<ans[i];
            }
            cout<<endl;
        }
        else{
            for(int i = ans.length() - 1; i >= 0; i--){
                cout<<ans[i];
            }
            cout<<endl;
        }
    }

    return 0;
}
