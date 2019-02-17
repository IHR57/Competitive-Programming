//Problem ID: CodeForces - 1005D (Polycarp and Div 3)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 17/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    int cnt = 0;

    cin>>str;
    int len = (int) str.length();

    for(int i = 0; i < len; i++){
        int temp = str[i] - 48;
        if(temp % 3 == 0){
            cnt++;
            str[i] = '0';
        }
    }

    int k = 0, sum = 0;
    for(int i = 0; i < len; i++){
        if(str[i] != '0'){
            k++;
            sum += str[i] - 48;
            if(sum % 3 == 0){
                k = 0;
                sum = 0;
                cnt++;
            }
            if(k >= 3){
                sum = 0;
                k = 0;
                cnt++;
            }
        }
        else{
            k = 0;
            sum = 0;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
