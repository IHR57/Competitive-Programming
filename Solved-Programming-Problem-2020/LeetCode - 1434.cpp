#define MOD 1000000007

class Solution {
public:
    int dp[45][1030], n;
    vector<int> caps[45];
    
    int solve(int cap, int mask) {
        if(mask == ((1<<n) - 1))
            return 1;
        if(cap >= 41)
            return 0;
        if(dp[cap][mask] != -1)
            return dp[cap][mask];
        
        int ret = solve(cap + 1, mask) % MOD;
        for(int i = 0; i < caps[cap].size(); i++){
            if(!(mask & (1<<caps[cap][i]))){
                ret += solve(cap + 1, mask | (1<<caps[cap][i])) % MOD;
            }
            ret %= MOD;
        }
        
        return dp[cap][mask] = ret % MOD;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < hats[i].size(); j++){
                caps[hats[i][j]].push_back(i);
            }
        }
        
        int res = solve(1, 0);
        
        return res;
    }
};