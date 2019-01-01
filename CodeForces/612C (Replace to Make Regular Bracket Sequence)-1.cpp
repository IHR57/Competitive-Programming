#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
    char str[1000005];

    stack<char>stk;

    cin>>str;

    int len=strlen(str), flag=1;
    int count=0;

    for(int i=0; i<len; i++){
        if(str[i]=='<' || str[i]=='{' || str[i]=='[' || str[i]=='(')
            stk.push(str[i]);
        if((str[i]==']' || str[i]==')' || str[i]=='}' || str[i]=='>'))
        {
            if(stk.empty()){
                cout<<"Impossible"<<endl;
                return 0;
            }
            if(stk.top()=='<' && str[i]!='>')   count++;
            else if(stk.top()=='{' && str[i]!='}')  count++;
            else if(stk.top()=='(' && str[i]!=')')  count++;
            else if(stk.top()=='[' && str[i]!=']')  count++;
            stk.pop();
        }
    }

    if(!stk.empty())
        cout<<"Impossible"<<endl;
    else
        cout<<count<<endl;

    return 0;
}
