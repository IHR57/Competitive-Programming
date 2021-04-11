class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }
        int palinSize = 0, odd = 0, maxOdd = 0;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 0){
                palinSize += freq[i];
            }
            else{
                odd++;
                maxOdd = max(maxOdd, freq[i]);
            }
        }
        if(odd){
            palinSize += maxOdd;
            odd--;
        }
        
        int Min = (palinSize > 0) + odd;
        int Max = n;
        
        if(k >= Min && k <= Max)
            return true;
        return false;
    }
};
