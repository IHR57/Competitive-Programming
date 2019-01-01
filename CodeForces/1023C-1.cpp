// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int flag[2*MAX], optr[2*MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    string str;

    cin>>n>>k;
    cin>>str;

    int need = (n - k) / 2;

    int len = (int) str.size();

    if(need == 0){
        cout<<str<<endl;
        return 0;
    }
    int cnt = 0;

    stack<int> st;

    for(int i = 0; i < len; i++){
        if(str[i] == '(')
            st.push(i);
        else if(str[i] == ')'){
            int temp = st.top();
            st.pop();
            optr[i] = temp;
        }
    }
    for(int i = 0; i < len; i++){
        if(str[i] == ')'){
            flag[i] = 1;
            flag[optr[i]] = 1;
            cnt++;
            if(cnt == need)
                break;
        }
    }

    for(int i = 0; i < len; i++){
        if(!flag[i]){
            cout<<str[i];
        }
    }

    cout<<endl;

    return 0;
}
