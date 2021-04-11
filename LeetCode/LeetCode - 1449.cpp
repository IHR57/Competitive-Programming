class Solution {
public:
    
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < 9; j++){
                if(i >= cost[j]) {
                    dp[i] = max(dp[i], dp[i-cost[j]] + 1);
                }
            }
        }
        if(dp[target] < 0)
            return "0";
        
        string res = "";
        while(target) {
            int idx = -1;
            for(int i = 8; i >= 0; i--){
                if(cost[i] <= target && (idx == -1 || dp[target-cost[i]] > dp[target-cost[idx]])) {
                    idx = i;
                }
            }
            res += ((idx + 1) + 48);
            target -= cost[idx];
        }
        
        return res;

    }
};