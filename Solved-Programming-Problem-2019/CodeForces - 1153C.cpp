//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

string str, temp;
stack<int> st;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    cin>>str;

    if(str[0] == ')' || str[n-1] == '(' || n % 2){
        cout<<":("<<endl;
        return 0;
    }

    if(str[0] == '?'){
        str[0] = '(';
    }
    else if(str[0] == '('){
        str[0] = '(';
    }
    str[n-1] = ')';

    int cnt = 0;
    for(int i = 1; i < n - 1; i++){
        if(str[i] == '(')
            cnt++;
        else if(str[i] == ')')
            cnt--;
        else if(str[i] == '?'){
            str[i] = ')';
            st.push(i);
            cnt--;
        }
        if(cnt < 0){
            if(st.empty()){
                cout<<":("<<endl;
                return 0;
            }
            else{
                int idx = st.top();
                str[idx] = '(';
                st.pop();
                cnt += 2;
            }
        }
    }

    (cnt > 0) ? cout<<":("<<endl : cout<<str<<endl;

    return 0;
}

