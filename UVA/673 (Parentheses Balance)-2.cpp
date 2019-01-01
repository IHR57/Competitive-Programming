#include <iostream>
#include <cstdio>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char str[200];
    int test, flag=0;

    cin>>test;
    getc(stdin);

    while(test--){
        gets(str);
        int len=strlen(str);

        stack<char>data;
        for(int i=0; i<len; i++){
            if(str[i]=='(' || str[i]=='[')
                data.push(str[i]);
            else if(str[i]==')'){
                if(data.empty() || data.top()!='('){
                    data.push(str[i]);
                    break;
                }
                data.pop();
            }
            else if(str[i]==']'){
                if(data.empty() || data.top()!='['){
                    data.push(str[i]);
                    break;
                }
                data.pop();
            }
        }
       if(data.empty())
            cout<<"Yes"<<endl;
       else
            cout<<"No"<<endl;
    }

    return 0;
}
