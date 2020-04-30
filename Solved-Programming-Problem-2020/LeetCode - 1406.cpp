#define INF 2e9

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> cs(n + 1), dp(n + 1, -INF);
        
        for(int i = n - 1; i >= 0; i--){
            cs[i] = cs[i+1] + stoneValue[i];
        }
        dp[n] = 0;
        dp[n-1] = cs[n-1];
        
        for(int i = n - 2; i >= 0; i--){
            dp[i] = stoneValue[i] + (cs[i+1] - dp[i+1]);
            if(i + 2 <= n){
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + (cs[i+2] - dp[i+2]));
            }
            if(i + 3 <= n){
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] + (cs[i+3] - dp[i+3]));
            }
        }
        
        if(dp[0] > cs[0] - dp[0])
            return "Alice";
        else if(dp[0] < cs[0] - dp[0])
            return "Bob";
        return "Tie";
    }
};