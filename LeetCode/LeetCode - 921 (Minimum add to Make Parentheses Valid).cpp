#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        int n = S.size();
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(S[i] == ')'){
                if(st.empty()){
                    cnt++;
                }
                else{
                    st.pop();
                }
            }
            else
                st.push(S[i]);
        }
        
        return cnt + (int) st.size();
    }
};

int main()
{
    freopen("output.txt", "w", stdout);
    
    Solution obj;
    cout<<obj.minAddToMakeValid("()))((")<<endl;
}