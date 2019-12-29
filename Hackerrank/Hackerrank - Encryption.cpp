#include <bits/stdc++.h>
using namespace std;

void encryption(string s) {
    string str = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ')
            str += s[i];
    }
    int n = (int) sqrt((int)str.size());
    int r, c;
    if(n * n == str.size()){
        r = n, c = n;
    }
    else{
        if(n * (n + 1) < str.size()){
            r = c = n + 1;
        }
        else
            r = n, c = n + 1;
    }
    char ch[105][105];
    int k = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ch[i][j] = str[k];
            if(k >= str.size())
                ch[i][j] = '1';
            k++;
        }
    }
    for(int j = 0; j < c; j++){
        string res = "";
        for(int i = 0; i < r; i++){
            if(ch[i][j] != '1')
                res += ch[i][j];
        }
        cout<<res<<" ";
    }
}

int main()
{
    string s;
    getline(cin, s);

    encryption(s);


    return 0;
}
