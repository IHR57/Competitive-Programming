#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define MAX 100005
using namespace std;

typedef long long ll;

string convertBinary(ll n)
{
    string str;
    while(n != 0){
        int r = (n % 2);
        str += (r + 48);
        n /= 2;
    }

    return str;
}

int main()
{
    int test, sum;
    ll n;
    string str1, str2;

    cin>>test;

    while(test--){
        cin>>str1;
        cin>>n;
        str2 = convertBinary(n);
        //cout<<str2<<endl;
        int len1 = (int) str1.length(), len2 = (int) str2.length();
        int len = max(len1, len2);
        string temp = "";
        reverse(str2.begin(), str2.end());

        //cout<<str2<<endl;
        int j = min(len1, len2) - 1, rem = 0;
        for(int i = len - 1; i >= 0; i--){
            if(len1 == len){
                if(j >= 0){
                    sum = ((str1[i] - 48) + (str2[j] - 48) + rem);
                    if(sum >= 2)
                        rem = 1;
                    else
                        rem = 0;
                    temp += ((sum % 2) + 48);
                }
                else{
                    sum = (str1[i] - 48) + rem;
                    if(sum >= 2)
                        rem = 1;
                    else
                        rem = 0;
                    temp += ((sum % 2) + 48);
                }
                j--;
            }
            else if(len2 == len){
                if(j >= 0){
                    sum = ((str2[i] - 48) + (str1[j] - 48) + rem);
                    if(sum >= 2)
                        rem = 1;
                    else
                        rem = 0;
                    temp += ((sum % 2) + 48);
                }
                else{
                    sum = (str2[i] - 48) + rem;
                    if(sum >= 2)
                        rem = 1;
                    else
                        rem = 0;
                    temp += ((sum % 2) + 48);
                }
                j--;
            }
        }
        if(rem >= 1)
            temp += "1";
        reverse(temp.begin(), temp.end());
        cout<<temp<<endl;
    }

    return 0;
}
