#define MOD 1000000007

class Solution {
public:
    int dp[100005], n;
    
    int solve(string& s, int pos, int k)
    {
        if(pos >= n)
            return 1;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        int ret = 0;
        long long temp = 0;
        for(int j = pos; j < n; j++){
            temp = (temp * 10) + (s[j] - 48);
            if(temp > k || temp < 1)
                break;
            ret += solve(s, j + 1, k);
            ret %= MOD;
        }
        
        return dp[pos] = ret;
    }
    
    int numberOfArrays(string s, int k) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        int ans = solve(s, 0, k);
        
        return ans;
    }
};