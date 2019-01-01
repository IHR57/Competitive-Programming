// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

bool check_vowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int len = (int) str.length();

    bool flag = true;
    for(int i = 0; i < len - 1; i++){
        if(str[i] == 'n' || check_vowel(str[i]))
            continue;
        else if(!check_vowel(str[i])){
            if(!check_vowel(str[i+1])){
                flag = false;
                break;
            }
        }
    }
    if(!check_vowel(str[len-1]) && str[len-1] != 'n')
        flag = false;

    (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}

