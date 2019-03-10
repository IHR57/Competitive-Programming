#include <bits/stdc++.h>
#define MAX 3005
using namespace std;

int mark[MAX];

bool isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[MAX];

    cin>>str;

    int len = strlen(str);

    int k = 0;
    while(k < len){
        if(!isVowel(str[k]) && k + 1 < len && !isVowel(str[k+1]) && k + 2 < len && !isVowel(str[k+2])){
            if(str[k] == str[k+1] && str[k] == str[k+2]){
                k++;
                continue;
            }
            mark[k+1] = 1;
            k += 2;
        }
        else{
            k++;
        }
    }

    for(int i = 0; i < len; i++){
        cout<<str[i];
        if(mark[i])
            cout<<" ";
    }

    cout<<endl;

    return 0;
}
