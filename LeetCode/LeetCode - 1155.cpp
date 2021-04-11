#define MOD 1000000007

class Solution {
public:
    int dp[35][35][1005];
    int n, m, s;
    
    int solve(int pos, int val, int sum)  {
        if(pos >= n){
            if(sum == s)
                return 1;
            return 0;
        }
        if(dp[pos][val][sum] != -1)
            return dp[pos][val][sum];
        
        int ret = 0;
        for(int i = 1; i <= m; i++){
            if(sum + i <= 1000)
                ret += solve(pos + 1, i, sum + i) % MOD;
            ret %= MOD;
        }
        
        return dp[pos][val][sum] = ret;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        n = d, m = f, s = target;
        memset(dp, -1, sizeof(dp));
        
        int res = solve(0, 0, 0);
        
        return res;
    }
};