//Problem ID: CodeForces - 990C (Bracket Sequences Concatenation Problem)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 23/02/19
#include <bits/stdc++.h>
#define  MAX 300005
using namespace std;

typedef long long ll;

int open[MAX], close[MAX];
string str;
ll ans = 0;

void check()
{
    stack<int> st;
    int len = (int) str.length();

    int cnt = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == '(')
            st.push(0);
        else if(str[i] == ')'){
            if(!st.empty()){
                st.pop();
            }
            else{
                cnt++;
            }
        }
    }
    if(!st.empty() && cnt == 0)
        open[st.size()]++;
    if(st.empty() && cnt != 0){
        close[cnt]++;
    }
    if(st.empty() && cnt == 0){
        open[0]++, close[0]++;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>str;
        check();
    }

    for(int i = 0; i< MAX; i++){
        ans += ((ll) open[i] * (ll) close[i]);
    }

    cout<<ans<<endl;

    return 0;
}
