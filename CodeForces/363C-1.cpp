#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

string str, modifiedStr, res;
int counter[MAX];

int main()
{
    cin>>str;

    int len = (int) str.size();

    if(len <= 2){
        cout<<str<<endl;
        return 0;
    }

    str += "#";
    len = (int) str.size();

    int cnt = 1;
    modifiedStr += str[0];

    for(int i = 1; i < len; i++){
        if(str[i] == str[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }
        if(cnt <= 2){
            modifiedStr += str[i];
        }
    }

    int n = (int) modifiedStr.size() - 1;

    counter[0] = 1;
    for(int i = 1; i < n; i++){
        if(modifiedStr[i] == modifiedStr[i-1]){
            cnt++;
            counter[i] = cnt;
        }
        else{
            cnt = 1;
        }
    }

    res += modifiedStr[0];
    res += modifiedStr[1];

    for(int i = 2; i < n; i++){
        if(counter[i] == 2 && counter[i-2] == 2){
            counter[i] = 1;
        }
        else{
            res += modifiedStr[i];
        }
    }

    cout<<res<<endl;

    return 0;
}
