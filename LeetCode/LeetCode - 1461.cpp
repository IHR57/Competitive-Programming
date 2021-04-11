class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        set<int> st;
        for(int i = 0; i <= n - k; i++) {
            int num = 0;
            for(int j = i; j < k + i; j++) {
                num += (s[j] - '0') * (1<<(k + i - j -1));
            }
            st.insert(num);
        }
        
        for(int i = 0; i < (1<<k); i++) {
            if(!st.count(i)){
                return false;
            }
        }
        
        return true;
    }
};