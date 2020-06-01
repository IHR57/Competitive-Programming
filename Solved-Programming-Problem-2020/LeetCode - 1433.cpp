class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int l = 0, r = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] <= s2[i])
                l++;
            if(s2[i] <= s1[i])
                r++;
        }
        
        if(l == s1.size() || r == s1.size())
            return true;
        return false;
    }
};