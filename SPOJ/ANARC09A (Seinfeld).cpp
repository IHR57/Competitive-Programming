#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    int caseNo = 1;

    while(cin>>str){
        if(str[0] == '-')
            break;
        stack<char> st1, st2;
        int len = (int) str.size();

        for(int i = 0; i < len; i++){
            if(str[i] == '{')
                st1.push('{');
            else if(str[i] == '}' && st1.empty()){
                st2.push('}');
            }
            else if(str[i] == '}' && !st1.empty()){
                st1.pop();
            }
        }

        int result;

        //cout<<st1.size()<<" "<<st2.size()<<endl;
        if(st1.size() % 2 != 0 && st2.size() % 2 != 0){
            result = (st1.size() + st2.size()) / 2 + 1;
        }
        else{
            result = (st1.size() + st2.size()) / 2;
        }

        cout<<caseNo++<<". "<<result<<endl;
    }

    return 0;
}
