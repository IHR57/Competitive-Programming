class Solution {
public:
    string convertToString(int n) {
        string res = "";
        while(n){
            res += (n % 10) + 48;
            n /= 10;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    vector<string> simplifiedFractions(int n) {
        int cnt = 0;
        vector<string> vs;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(__gcd(i, j) == 1){
                    string temp = convertToString(i) + "/" + convertToString(j);
                    vs.push_back(temp);
                }
            }
        }
        
        return vs;
    }
};