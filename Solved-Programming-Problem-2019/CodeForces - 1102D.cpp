//Problem ID: CodeForces - 1102D (Balanced Ternary String)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 09/02/19
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;

int counter[5], lim, n;
string str;

bool check(int a, int b, int c)
{
    int idx;
    if(a > lim){
        if(c < lim){
            for(int i = n - 1; i >= 0; i--){
                if(a == lim || c == lim){
                    break;
                }
                if(str[i] == '0'){
                    str[i] = '2';
                    a--;
                    c++;
                }
            }
        }
        if(b < lim){
            for(int i =  n - 1; i >= 0; i--){
                if(a == lim || b == lim)
                    break;
                if(str[i] == '0'){
                    str[i] = '1';
                    a--; b++;
                }
            }
        }
    }
    if(b > lim){
        if(a < lim){
            for(int i = 0; i < n; i++){
                if(b == lim || a == lim)
                    break;
                if(str[i] == '1'){
                    str[i] = '0';
                    a++;
                    b--;
                }
            }
        }
        if(c < lim){
            for(int i = n - 1; i >= 0; i--){
                if(b ==  lim || c == lim)
                    break;
                if(str[i] == '1'){
                    str[i] = '2';
                    c++;
                    b--;
                }
            }
        }
    }
    if(c > lim){
        if(a <  lim){
            for(int i = 0; i < n; i++){
                if(a == lim || c == lim)
                    break;
                if(str[i] == '2'){
                    str[i] = '0';
                    a++;
                    c--;
                }
            }
        }
        if(b < lim){
            for(int i = 0; i < n; i++){
                if(b == lim || c == lim){
                    break;
                }
                if(str[i] == '2'){
                    str[i] = '1';
                    b++; c--;
                }
            }
        }
    }
    if(a == b && a == c)
        return true;
    return false;
}

int main()
{
    cin>>n;
    cin>>str;

    lim = n / 3;
    for(int i = 0; i < n; i++){
        counter[str[i] - 48]++;
    }

    int lim = n / 3;

    while(!check(counter[0], counter[1], counter[2])){

    }

    cout<<str<<endl;

    return 0;
}
