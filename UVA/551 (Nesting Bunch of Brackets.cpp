#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    char str[3010];
    int count, i;

    while(cin.getline(str, sizeof(str))){
        int len=strlen(str);
        count=0;
        stack<char>data;
        for(i=0; i<len; i++){
            count++;
            if(str[i]=='(' || str[i]=='[' || str[i]=='{' || str[i]=='<'){
                if(str[i]=='(' && str[i+1]=='*'){
                    data.push('*');
                    i++;        //we don't need to check next element
                }
                else
                    data.push(str[i]);
            }
            else if((str[i]==')' || str[i]=='}' || str[i]==']' || str[i]=='>') ||(str[i]=='*' && str[i+1]==')')){
                if(data.empty()){
                    break;
                }

                if(str[i]=='*'){
                    if(data.top()!='*')
                        break;
                    data.pop();
                    i++;        //we don't need to check next element
                }
                else if(str[i]==')'){
                    if(data.top()!='('){
                        break;
                    }
                    data.pop();     //delete the top element
                }
                else if(str[i]==']'){
                    if(data.top()!='['){
                        break;
                    }
                    data.pop();
                }
                else if(str[i]=='}'){
                    if(data.top()!='{'){
                        break;
                    }
                    data.pop();
                }
                else if(str[i]=='>'){
                    if(data.top()!='<'){
                        break;
                    }
                    data.pop();     //delete the top element
                }
            }
        }
        if(i<len || !data.empty()){
            if(i>=len && !data.empty()){        //if we find the last element wrong
                count++;
            }
            cout<<"NO "<<count<<endl;
        }
        else
            cout<<"YES"<<endl;

        while(!data.empty())        //deleting the remaining element
            data.pop();
    }

    return 0;
}
